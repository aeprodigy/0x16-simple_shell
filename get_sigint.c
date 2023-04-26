#include "main.h"

/**
 * get_sigint - Handle the crtl + c call in prompt
 * @nl: Signal handler
 */
void get_sigint(int nl)
{
	(void)nl;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
