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

	if (cmd == NULL)
		return (false);
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
	if (!_strcmp(built_in[0], "exit"))
		exit_shell(built_in);
}
/**
 * exit_shell - exit with value
 * @built_in: command with num value
 */
void exit_shell(char **built_in)
{
	int ex = 0;

	if (built_in[1] == NULL)
		exit(EXIT_SUCCESS);
	if (built_in[1] && built_in[2])
		_puts("exit : too many arguments"),
		exit(1); /* 2 or 1 ? */
	if (_isnumber(built_in[1]))
		ex = _atoi(built_in[1]) % 256,
		exit(ex);
	else
		_puts("hedy_cherif: exit : numeric argument required"),
		exit(2);
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
