#include "func.h"
int main(int ac, char **av, char **env)
{
	char *buff = NULL;
	size_t buf_size = 2048;
	char **cmd;
	char **envi = NULL;

	buff = _calloc(sizeof(char), buf_size);
	if (!buff)
	exit;

	write(1, "hedy_cherif&>", 13);
	while (getline(&buff,&buf_size, stdin) > 0)
	{
		cmd = strtow(buff);
		printf("%s", buff);
		write(1, "hedy_cherif&>", 13);
	}
}
