#include "main.h"

/**
 * _strcat - concatenate two strings
 * @destn: char pointer the destn of the copied str
 * @strngsrc: const char pointer the source of str
 * Return: the destn
 */
char *_strcat(char *destn, const char *strngsrc)
{
	int i;
	int j;

	for (i = 0; destn[i] != '\0'; i++)
		;

	for (j = 0; strngsrc[j] != '\0'; j++)
	{
		destn[i] = strngsrc[j];
		i++;
	}

	destn[i] = '\0';
	return (destn);
}
/**
 * *_strcpy - Copies the string pointed to by strngsrc.
 * @destn: Type char pointer the destn of the copied str
 * @strngsrc: Type char pointer the source of str
 * Return: the destn.
 */
char *_strcpy(char *destn, char *strngsrc)
{

	size_t a;

	for (a = 0; strngsrc[a] != '\0'; a++)
	{
		destn[a] = strngsrc[a];
	}
	destn[a] = '\0';

	return (destn);
}
/**
 * _strcmp - Function that compares two strings.
 * @s1: type str compared
 * @s2: type str compared
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}
/**
 * _strchr - locates a character in a string,
 * @s: string.
 * @c: character.
 * Return: the pointer to the first occurrence of the character c.
 */
char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}
/**
 * _strspn - gets the length of a prefix substring.
 * @s: initial segment.
 * @accept: accepted bytes.
 * Return: the number of accepted bytes.
 */
int _strspn(char *s, char *accept)
{
	int i, j, bool;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (i);
}
