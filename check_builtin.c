#include "func.h"
/**
 * check_built_in - check if the arg is treated as built in
 * @cmd: string to check
 * Return: true if built in else false
 */
bool check_built_in(char *cmd)
{
	char *built_in = "env";
	char *built_in2 = "exit";

	if (!_strcmp(built_in, cmd))
		return (true);
	if (!_strcmp(built_in2, cmd))
		return (true);
	else
		return (false);
}
/**
 * exec_built_in - exec the appropriate built in function
 * @built_in: cmd array of strings
 */
void exec_built_in(char **built_in)
{
	if (!_strcmp(built_in[0], "env") && built_in[1] == NULL)
		print_env();
	if (!_strcmp(built_in[0], "exit") && built_in[1] == NULL)
		exit(EXIT_SUCCESS);
	else
		perror("No file found");
}
/**
 * print_env - print env as env cmd
 */
void print_env(void)
{
	int i = 0;
	int j = 0;

	while (environ[i])
	{
		j = 0;
		while (environ[i][j])
		{
			write(1, &environ[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
