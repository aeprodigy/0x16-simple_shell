
#include "main.h"

/**
 * rev_string - reverses a string.
 * @s: input string.
 * @temprl: temporal.
 * Return: no return.
 */
void rev_string(char *s)
{
	int count = 0, i, j;
	char *str, temprl;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temprl = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temprl;
		}
	}
}
