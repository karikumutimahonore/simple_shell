#include "main.h"

/**
 * soma_umur - check the input string.
 *
 * @toe_s: getline func
 * Return: string
 */
char *soma_umur(int *toe_s)
{
	char *mamaput = NULL;
	size_t dufite = 0;

	*toe_s = getline(&mamaput, &dufite, stdin);

	return (mamaput);
}
