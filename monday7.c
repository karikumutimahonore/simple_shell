#include "main.h"

/**
 * iher_umur - finds builtins commands
 *
 * @rndsh: data relevant
 * Return: 1.
 */
int iher_umur(datacliff *rndsh)
{
	int (*guruka)(datacliff *rndsh);

	if (rndsh->tkncl[0] == NULL)
		return (1);

	guruka = get_builtin(rndsh->tkncl[0]);

	if (guruka != NULL)
		return (guruka(rndsh));

	return (cmd_exec(rndsh));
}
