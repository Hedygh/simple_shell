#include "func.h"
void *get_path(char **cmd)
{
	char *path;
	char **split_path;
	int i = 0;
	char *find;

	path = strdup(_getenv("PATH"));

	if (cmd[0][0] != '/')
	{
		split_path = strtow(path);
		free(path);
		while (split_path[i])
		{
			find = calloc(sizeof(char), strlen(split_path[i]) + 1 + strlen(cmd[0]) + 1);
			if (!find)
				break;
			strcat(find, split_path[i]);
			strcat(find, "/");
			strcat(find, cmd[0]);

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
