#include "main.h"

/**
 * read_line - reads the input from the string.
 *
 * @i_eofun: return value of the getline function
 * Return: input string to the fun
 */
char *read_line(int *i_eofun)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eofun = getline(&input, &bufsize, stdin);

	return (input);
}
