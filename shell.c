#include "func.h"
/**
 * main - main loop through getline to display prompt
 * Return: always 0
 */
int main(void)
{
	char *buff = NULL;
	char **cmd = NULL;
	size_t buf_size = 2048;

	buff = _calloc(sizeof(char), buf_size);
	if (!buff)
	{
		perror("alloc error");
		return (EXIT_FAILURE);
	}
	write(1, "$ ", 2);
	while (getline(&buff, &buf_size, stdin) > 0)
	{
		cmd = strtow(buff);
		if (cmd != NULL)
		{
			if (check_built_in(cmd[0]) == false)
			{
				if (get_path(cmd))
					execve_cmd(cmd);
				else
					perror(cmd[0]);
			}
			else
				exec_built_in(cmd);
			free_array(cmd);
		}
		if (isatty(STDIN_FILENO))
		write(1, "$ ", 2);
	}
	if (isatty(STDIN_FILENO))
	write(1, "\n", 1);
	free(buff);
	return (0);
}
