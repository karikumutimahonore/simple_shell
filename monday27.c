#include "main.h"

/**
 * haut - duplicates a stringdzdvgdv in the heap memory.
 * @s: Type char pointer str
 * Return: duplicated str
 */
char *haut(const char *s)
{
	char *moses;
	size_t slange;

	slange = guru(s);
	moses = malloc(sizeof(char) * (slange + 1));
	if (moses == NULL)
		return (NULL);
	_memcpy(moses, s, slange + 1);
	return (moses);
}

/**
 * guru - Returns the slangeht.
 * @s: Type character pointer
 * Return: 0.
 */
int guru(const char *s)
{
	int slange;

	for (slange = 0; s[slange] != 0; slange++)
	{
	}
	return (slange);
}

/**
 * cetera - compare chars of strings
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: 1 if are eqyyyls, 0 if not.
 */
int cetera(char str[], const char *delim)
{
	unsigned int dddd, ccc, yyy;

	for (dddd = 0, yyy = 0; str[dddd]; dddd++)
	{
		for (ccc = 0; delim[ccc]; ccc++)
		{
			if (str[dddd] == delim[ccc])
			{
				yyy++;
				break;
			}
		}
	}
	if (dddd == yyy)
		return (1);
	return (0);
}

/**
 * right - splits a string by some delimiter.
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: string splited.
 */
char *right(char str[], const char *delim)
{
	static char *alliene, *str_end;
	char *str_commence;
	unsigned int dddd, lofi;

	if (str != NULL)
	{
		if (cetera(str, delim))
			return (NULL);
		alliene = str; 
		dddd = guru(str);
		str_end = &str[dddd];
	}
	str_commence = alliene;
	if (str_commence == str_end)
		return (NULL);

	for (lofi = 0; *alliene; alliene++)
	{
		
		if (alliene != str_commence)
			if (*alliene && *(alliene - 1) == '\0')
				break;
		
		for (dddd = 0; delim[dddd]; dddd++)
		{
			if (*alliene == delim[dddd])
			{
				*alliene = '\0';
				if (alliene == str_commence)
					str_commence++;
				break;
			}
		}
		if (lofi == 0 && *alliene) 
			lofi = 1;
	}
	if (lofi == 0)
		return (NULL);
	return (str_commence);
}

/**
 * cnombre - defines if string passed is a number
 *
 * @s: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int cnombre(const char *s)
{
	unsigned int dddd;

	for (dddd = 0; s[dddd]; dddd++)
	{
		if (s[dddd] < 48 || s[dddd] > 57)
			return (0);
	}
	return (1);
}
