#include "main.h"

/**
 * rem_string - incurike a string.
 * @d: input string.
 * Return: no return.
 */
void rem_string(char *d)
{
	int bara = 0, i, j;
	char *cntr, chaw;

	while (bara >= 0)
	{
		if (d[bara] == '\0')
			break;
		bara++;
	}
	cntr = d;

	for (i = 0; i < (bara - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			chaw = *(cntr + j);
			*(cntr + j) = *(cntr + (j - 1));
			*(cntr + (j - 1)) = chaw;
		}
	}
}
