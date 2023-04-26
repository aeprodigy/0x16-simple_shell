#include "main.h"

/**
 * repeated_char - counts the repetitions of a char
 *
 * @inputstr: inputstr string
 * @i: index
 * Return: repetitions
 */
int repeated_char(char *inputstr, int i)
{
	if (*(inputstr - 1) == *inputstr)
		return (repeated_char(inputstr - 1, i + 1));

	return (i);
}

/**
 * error_sep_op - finds syntax errors
 *
 * @inputstr: inputstr string
 * @i: index
 * @lastchr: last character read
 * Return: index of error. 0 when there are no
 * errors
 */
int error_sep_op(char *inputstr, int i, char lastchr)
{
	int count;

	count = 0;
	if (*inputstr == '\0')
		return (0);

	if (*inputstr == ' ' || *inputstr == '\t')
		return (error_sep_op(inputstr + 1, i + 1, lastchr));

	if (*inputstr == ';')
		if (lastchr == '|' || lastchr == '&' || lastchr == ';')
			return (i);

	if (*inputstr == '|')
	{
		if (lastchr == ';' || lastchr == '&')
			return (i);

		if (lastchr == '|')
		{
			count = repeated_char(inputstr, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	if (*inputstr == '&')
	{
		if (lastchr == ';' || lastchr == '|')
			return (i);

		if (lastchr == '&')
		{
			count = repeated_char(inputstr, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	return (error_sep_op(inputstr + 1, i + 1, *inputstr));
}

/**
 * first_char - finds index of the first char
 *
 * @inputstr: inputstr string
 * @i: index
 * Return: 1 if there is an error. 0 in other case.
 */
int first_char(char *inputstr, int *i)
{

	for (*i = 0; inputstr[*i]; *i += 1)
	{
		if (inputstr[*i] == ' ' || inputstr[*i] == '\t')
			continue;

		if (inputstr[*i] == ';' || inputstr[*i] == '|' || inputstr[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * print_syntax_error - prints when a syntax error is found
 *
 * @datash: data structure
 * @inputstr: inputstr string
 * @i: index of the error
 * @bool: to control msg error
 * Return: no return
 */
void print_syntax_error(data_shell *datash, char *inputstr, int i, int bool)
{
	char *msg, *msg2, *msg3, *error, *counter;
	int length;

	if (inputstr[i] == ';')
	{
		if (bool == 0)
			msg = (inputstr[i + 1] == ';' ? ";;" : ";");
		else
			msg = (inputstr[i - 1] == ';' ? ";;" : ";");
	}

	if (inputstr[i] == '|')
		msg = (inputstr[i + 1] == '|' ? "||" : "|");

	if (inputstr[i] == '&')
		msg = (inputstr[i + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	counter = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(counter);
	length += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, counter);
	_strcat(error, msg2);
	_strcat(error, msg);
	_strcat(error, msg3);
	_strcat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(counter);
}

/**
 * check_syntax_error - intermediate function to
 * find and print a syntax error
 *
 * @datash: data structure
 * @inputstr: inputstr string
 * Return: 1 if there is an error. 0 in other case
 */
int check_syntax_error(data_shell *datash, char *inputstr)
{
	int begin = 0;
	int f_char = 0;
	int i = 0;

	f_char = first_char(inputstr, &begin);
	if (f_char == -1)
	{
		print_syntax_error(datash, inputstr, begin, 0);
		return (1);
	}

	i = error_sep_op(inputstr + begin, 0, *(inputstr + begin));
	if (i != 0)
	{
		print_syntax_error(datash, inputstr, begin + i, 1);
		return (1);
	}

	return (0);
}
