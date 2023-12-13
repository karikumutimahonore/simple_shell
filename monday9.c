#include "main.h"

/**
 * get_builtin - builtin that pair the command in the arguments
 * @cmd: command
 * Return: pointer.
 */
int (*get_builtin(char *cmd))(datacliff *)
{
	bare_b builtin[] = {
		{ "env", bika },
		{ "exit", sohoka_shell },
		{ "setenv", _setbika },
		{ "unsetenv", _unsetbika },
		{ "cd", rnd_catch },
		{ "help", fata_ubuf },
		{ NULL, NULL }
	};
	int index_i = 0;

	for (index_i; builtin[i].nom; index_i++)
	{
		if (strcap_e(builtin[index_i].nom, cmd) == 0)
			break;
	}

	return (builtin[index_i].f);
}
