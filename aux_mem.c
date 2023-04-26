#include "main.h"

/**
 * _memcpy - copies information between void pointers.
 * @newptr: destination pointer.
 * @pntersrc: source of the pointer.
 * @size: size of the new pointer .
 *
 * Return: no return.
 */
void _memcpy(void *newptr, const void *pntersrc, unsigned int size)
{
	char *char_ptr = (char *)pntersrc;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}

/**
 * _realloc - reallocates a memory block.
 * @pntersrc: pointer to the memory previously allocated.
 * @old_size: size, in bytes, of the allocated space of pntersrc.
 * @new_size: new size, in bytes, of the new memory block.
 *
 * Return: pntersrc.
 * if new_size == old_size, returns pntersrc without changes.
 * if malloc fails, returns NULL.
 */
void *_realloc(void *pntersrc, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (pntersrc == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(pntersrc);
		return (NULL);
	}

	if (new_size == old_size)
		return (pntersrc);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, pntersrc, new_size);
	else
		_memcpy(newptr, pntersrc, old_size);

	free(pntersrc);
	return (newptr);
}

/**
 * _reallocdp - reallocates a memory block of a double pointer.
 * @pntersrc: double pointer to the memory previously allocated.
 * @old_size: size, in bytes, of the allocated space of pntersrc.
 * @new_size: new size, in bytes, of the new memory block.
 *
 * Return: pntersrc.
 * if new_size == old_size, returns pntersrc without changes.
 * if malloc fails, returns NULL.
 */
char **_reallocdp(char **pntersrc, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int i;

	if (pntersrc == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (pntersrc);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		newptr[i] = pntersrc[i];

	free(pntersrc);

	return (newptr);
}
