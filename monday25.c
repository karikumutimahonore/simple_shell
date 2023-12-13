#include "main.h"

/**
 * _memcpy - copies information between void pointers.
 * @newpillot: destination pointer.
 * @ptr: source pointer.
 * @size: size of the new pointer.
 *
 * Return: no return.
 */
void _memcpy(void *newpillot, const void *ptr, unsigned int size)
{
	char *char_pillot = (char *)ptr;
	char *char_newpillot = (char *)newpillot;
	unsigned int i = 0;

	for (i; i < size; i++)
		char_newpillot[i] = char_pillot[i];
}

/**
 * _realloc - re-allocates a memory block.
 * @ptr: pointer to the memory previously allocated.
 * @old_size: size, in bytes, of the allocated space of ptr.
 * @new_size: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if new_size == old_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newpillot;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newpillot = malloc(new_size);
	if (newpillot == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newpillot, ptr, new_size);
	else
		_memcpy(newpillot, ptr, old_size);

	free(ptr);
	return (newpillot);
}

/**
 * _reallocdp - reallocates a memory block of a double pointer.
 * @ptr: double pointer to the memory previously allocated.
 * @old_size: size, in bytes, of the allocated space of ptr.
 * @new_size: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if new_size == old_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newpillot;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newpillot = malloc(sizeof(char *) * new_size);
	if (newpillot == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		newpillot[i] = ptr[i];

	free(ptr);

	return (newpillot);
}
