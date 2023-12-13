#include "main.h"

/**
 * _strpuss - concat two string.
 * @best: character pointer copied string.
 * @srcm: constant character pointer the source of string.
 * Return: best.
 */
char *_strpuss(char *best, const char *srcm)
{
	int starting;
	int ending;

	for (starting = 0; best[starting] != '\0'; starting++)
		;

	for (ending = 0; srcm[ending] != '\0'; ending++)
	{
		best[starting] = srcm[ending];
		starting++;
	}

	best[starting] = '\0';
	return (best);
}
/**
 * *_strap_y - Copy the string pointed to by source.
 * @best: Type of character pointer copied string.
 * @srcm: Type of character pointer the source of string.
 * Return: best.
 */
char *_strap_y(char *best, char *srcm)
{

	size_t pillo;

	for (pillo = 0; srcm[pillo] != '\0'; pillo++)
	{
		best[pillo] = srcm[pillo];
	}
	best[pillo] = '\0';

	return (best);
}
/**
 * strcap_e - compares two strings.
 * @b1: type string one
 * @b2: type string one
 * Return: 0.
 */
int strcap_e(char *b1, char *b2)
{
	int starting;

	for (starting = 0; b1[starting] == b2[starting] && b1[starting]; starting++)
		;

	if (b1[starting] > b2[starting])
		return (1);
	if (b1[starting] < b2[starting])
		return (-1);
	return (0);
}
/**
 * strchrap_load - function that locates a character in a string,
 * @b: string.
 * @charac: character.
 * Return: pointer.
 */
char *strchrap_load(char *b, char charac)
{
	unsigned int starting = 0;

	for (; *(b + starting) != '\0'; starting++)
		if (*(b + starting) == charac)
			return (b + starting);
	if (*(b + starting) == charac)
		return (b + starting);
	return ('\0');
}
/**
 * strsnap_load - function that gets the length of a prefix substring.
 * @b: initial sg.
 * @expat: accepted bytes.
 * Return: accepted bytes.
 */
int strsnap_load(char *b, char *expat)
{
	int starting, ending, bol;

	for (starting = 0; *(b + starting) != '\0'; starting++)
	{
		bol = 1;
		for (ending = 0; *(expat + ending) != '\0'; ending++)
		{
			if (*(b + starting) == *(expat + ending))
			{
				bol = 0;
				break;
			}
		}
		if (bol == 1)
			break;
	}
	return (starting);
}
