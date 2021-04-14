#include "func.h"
/**
 * ctrlC - handle ctC
 * @sign: unused
 */
void ctrlC(int sign __attribute__((unused)))
{
	_puts("\n");
	_puts("$ ");
}
/**
 * main - main loop through getline to display prompt
 * Return: always 0
 * @ac: num of arg
 * @av: arg
 */
int main(int ac, char **av)
{
	char *buff = NULL;
	char **cmd = NULL;
	size_t buf_size = 2048;
	(void)ac;

	buff = _calloc(sizeof(char), buf_size);
	if (!buff)
	{
		perror("alloc error");
		return (EXIT_FAILURE);
	}
	_puts("$ ");
	signal(SIGINT, ctrlC);
	while (getline(&buff, &buf_size, stdin) > 0)
	{
		cmd = strtow(buff);
		if (cmd != NULL)
		{
			if (check_built_in(cmd[0]) == false)
			{
				if (get_path(cmd))
					execve_cmd(cmd, av[0]);
				else
					perror(av[0]);
			}
			else
				exec_built_in(cmd);
			free_array(cmd);
		}
		_puts("$ ");
	}
	if (isatty(STDIN_FILENO))
	_putchar('\n');
	free(buff);
	return (0);
}
