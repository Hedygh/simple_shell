#include "func.h"
void *get_path(char **cmd)
{
	char *path;
	char **split_path;
	int i = 0;
	char *find;

	path = _strdup(_getenv("PATH"));

	if (cmd[0][0] != '/')
	{
		split_path = strtow(path);
		free(path);
		while (split_path[i])
		{
			find = calloc(sizeof(char), _strlen(split_path[i]) + 1 + _strlen(cmd[0]) + 1);
			if (!find)
				break;
			_strcat(find, split_path[i]);
			_strcat(find, "/");
			_strcat(find, cmd[0]);

			if (access(find, F_OK) == 0)
				break;
			i++;
			free(find);
			find = NULL;
		}
		free_array(split_path);
		free(cmd[0]);
		cmd[0] = find;
	}
	else
	{
		free(path);
		path = NULL;
	}
}
