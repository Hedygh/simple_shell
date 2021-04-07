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

	write(1, "hedy_cherif&>", 13);
	while (getline(&buff, &buf_size, stdin) > 0)
	{
		cmd = strtow(buff);
		if (check_built_in(cmd[0]) == false)
		{
			get_path(cmd);
			execve_cmd(cmd);
		}
		else
			exec_built_in(cmd);
		write(1, "hedy_cherif&>", 13);
		free_array(cmd);
	}
	write(1, "\n", 1);
	free(buff);
	return (0);
}
