#include "func.h"
/**
 * main - main loop through getline to display prompt
 * @ac: number of arg
 * @av: arguments
 * @env: array of env elements
 * Return: 
 */
int main(void)
{
	char *buff = NULL;
	char **cmd = NULL;
	char **env = NULL;
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
		get_path(cmd);
		execve_cmd(cmd);
		/*printf("%s", buff); */
		write(1, "hedy_cherif&>", 13);
		free_array(cmd);
	}
	free(buff);
}
