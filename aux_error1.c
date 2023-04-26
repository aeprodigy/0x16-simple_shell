
#include "main.h"

/**
 * strcat_cd - function that concatenates the message for cd error_output
 *
 * @datashell: data relevant (directory)
 * @print_msg: message to print
 * @error_output: output message
 * @ver_str: counter lines
 * Return: error_output message
 * mike mambwe and vanessa nakayange.
 */
char *strcat_cd(data_shell *datashell, char *print_msg, char *error_output, char *ver_str)
{
	char *illegal_flag;

	_strcpy(error_output, datashell->av[0]);
	_strcat(error_output, ": ");
	_strcat(error_output, ver_str);
	_strcat(error_output, ": ");
	_strcat(error_output, datashell->args[0]);
	_strcat(error_output, print_msg);
	if (datashell->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datashell->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(error_output, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(error_output, datashell->args[1]);
	}

	_strcat(error_output, "\n");
	_strcat(error_output, "\0");
	return (error_output);
}

/**
 * error_get_cd - error_output message for cd command in get_cd
 * @datashell: data relevant (directory)
 * Return: Error message
 */
char *error_get_cd(data_shell *datashell)
{
	int length, len_id;
	char *error_output, *ver_str, *print_msg;

	ver_str = aux_itoa(datashell->counter);
	if (datashell->args[1][0] == '-')
	{
		print_msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		print_msg = ": can't cd to ";
		len_id = _strlen(datashell->args[1]);
	}

	length = _strlen(datashell->av[0]) + _strlen(datashell->args[0]);
	length += _strlen(ver_str) + _strlen(print_msg) + len_id + 5;
	error_output = malloc(sizeof(char) * (length + 1));

	if (error_output == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error_output = strcat_cd(datashell, print_msg, error_output, ver_str);

	free(ver_str);

	return (error_output);
}

/**
 * error_not_found - generic error_output message for command not found
 * @datashell: data relevant (counter, arguments)
 * Return: Error message
 */
char *error_not_found(data_shell *datashell)
{
	int length;
	char *error_output;
	char *ver_str;

	ver_str = aux_itoa(datashell->counter);
	length = _strlen(datashell->av[0]) + _strlen(ver_str);
	length += _strlen(datashell->args[0]) + 16;
	error_output = malloc(sizeof(char) * (length + 1));
	if (error_output == 0)
	{
		free(error_output);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error_output, datashell->av[0]);
	_strcat(error_output, ": ");
	_strcat(error_output, ver_str);
	_strcat(error_output, ": ");
	_strcat(error_output, datashell->args[0]);
	_strcat(error_output, ": not found\n");
	_strcat(error_output, "\0");
	free(ver_str);
	return (error_output);
}

/**
 * error_exit_shell - generic error_output message for exit in get_exit
 * @datashell: data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *error_exit_shell(data_shell *datashell)
{
	int length;
	char *error_output;
	char *ver_str;

	ver_str = aux_itoa(datashell->counter);
	length = _strlen(datashell->av[0]) + _strlen(ver_str);
	length += _strlen(datashell->args[0]) + _strlen(datashell->args[1]) + 23;
	error_output = malloc(sizeof(char) * (length + 1));
	if (error_output == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error_output, datashell->av[0]);
	_strcat(error_output, ": ");
	_strcat(error_output, ver_str);
	_strcat(error_output, ": ");
	_strcat(error_output, datashell->args[0]);
	_strcat(error_output, ": Illegal number: ");
	_strcat(error_output, datashell->args[1]);
	_strcat(error_output, "\n\0");
	free(ver_str);

	return (error_output);
}
