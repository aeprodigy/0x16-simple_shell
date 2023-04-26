#include "main.h"

/**
 * get_error - calls the error according the built in, permission or syntax
 * @datash: data structure that contains arguments
 * @errval: error value
 * Return: error
 */
int get_error(data_shell *datash, int errval)
{
	char *error;

	switch (errval)
	{
	case -1:
		error = error_env(datash);
		break;
	case 126:
		error = error_path_126(datash);
		break;
	case 127:
		error = error_not_found(datash);
		break;
	case 2:
		if (_strcmp("exit", datash->args[0]) == 0)
			error = error_exit_shell(datash);
		else if (_strcmp("cd", datash->args[0]) == 0)
			error = error_get_cd(datash);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	datash->status = errval;
	return (errval);
}
