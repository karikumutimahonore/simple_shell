#include "main.h"

/**
 * get_builtin - builtin cmd argmnt
 * @cmd: command
 * Return: pointer.
 */
int (*get_builtin(char *cmd))(dataclif *)
{
	ball_b builtin[] = {
		{ "env", ibik },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", rnd_catch },
		{ "help", akir_ubuf },
		{ NULL, NULL }
	};
	int hm;

	for (hm = 0; builtin[hm].nom; hm++)
	{
		if (strcap_e(builtin[hm].nom, cmd) == 0)
			break;
	}

	return (builtin[hm].f);
}
