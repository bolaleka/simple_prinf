#include "main.h"

/**
 * main - check the code.
 * @ac: Number of Argument passed
 * @args: Argument command passed
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(int ac, char **args, char **env)
{
	char *line;

	if (ac != 1)
		return (EXIT_SUCCESS);
	do {
		printf("#cisfun$ ");
		line = hsh_read_line();
		if (_strcmp(line, "/bin/ls") != 0 || _strchr(line, ' ') != NULL)
			_puts("./shell: No such file or directory");
		else
			args = hsh_split_line(line);
		if (args[0] != NULL)
		{
			hsh_execute(args, env);
			free(line);
			free(args);
		}
	} while (1);

	return (EXIT_SUCCESS);
}
