#include "func.h"
/**
 * execve_cmd - use fork to clone process from parent to child
 * wait for the child process to exec the cmd then kill it
 * @cmd: commande to exec
 */

void execve_cmd(char **cmd)
{
	pid_t pid = 0;
	int i = 0;

	pid = fork(); /* child pid variable value is 0,*/
	/*pid of parent value is  pid of  child (random id value) */
	if (pid == -1)
		perror("fork failure");
	else if (pid > 0) /* parent process going on */
	{
		waitpid(pid, &i, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		if (execve(cmd[0], cmd, NULL) == -1)/* first arg must be path to binary*/
			perror("exec error");
		exit(EXIT_FAILURE);
	}
}
