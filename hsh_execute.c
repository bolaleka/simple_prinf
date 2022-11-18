#include "main.h"

/**
* hsh_execute - Execute builtin functions
* @args: Argument pass to built
*
* Return: Integer
*/
void hsh_execute(char **args, char **env)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		execve(args[0], args, env);
		perror("./hsh");
		exit(1);
	} else if (child_pid > 0)
	{
		int status;

		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	} else
		perror("./hsh");
}
