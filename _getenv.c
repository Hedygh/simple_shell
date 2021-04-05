#include "func.h"

char *_getenv(char *name)
{
	int i = 0;

	while (*environ[i])
	{
		if(_strstr(environ[i], name) != NULL && environ[i][0] == 'P')
		{
			return(environ[i]);
		}
		i++;
	}
	return (NULL);
}
