#include "main.h"

#define HSH_BUFFSIZE 1024
#define HSH_TOK_BUFFSIZE 64
#define HSH_TOK_DELIM " \t\r\n\a"

/**
* hsh_read_line - Function read line from standard input
*
* Return: string line read from stdin
*/
char *hsh_read_line(void)
{
	char *line;
	size_t buflen;

	line = NULL;
	buflen = 0;
	if (getline(&line, &buflen, stdin) == -1)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		else
		{
			perror("readline");
			exit(EXIT_SUCCESS);
		}
	}
	return (line);
}

/**
 * hsh_split_line - splite result
 * @line: input command
 *
 * Return: String
 */
char **hsh_split_line(char *line)
{
	int bufsize;
	int pos;
	char **tokens;
	char *token;

	pos = 0;
	bufsize = HSH_TOK_BUFFSIZE;
	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		_puts("hsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, HSH_TOK_DELIM);
	while (token != NULL)
	{
		tokens[pos] = token;
		pos++;

		if (pos >= bufsize)
		{
			bufsize += HSH_TOK_BUFFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				_puts("hsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, HSH_TOK_DELIM);
	}
	tokens[pos] = NULL;
	return (tokens);
}
