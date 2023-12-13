#include "honore.h"

/**
 * handle_builtin - handles the builtin commands
 * @hons: contains all the data relevant to the shell's operation
 *
 * Return: exit code
 */
int handle_builtin(shell_t *hons)
{
	if (!_strcmp(hons->other_cmd[0], "env") ||
		!_strcmp(hons->other_cmd[0], "printenv"))
	{
		_printenv();
		return (0);
	}
	else if (!_strcmp(hons->other_cmd[0], "exit"))
	{
		return (handle_exit(hons, multi_free));
	}

	/* let's handle the builtin 'cd' command */
	else if (!_strcmp(hons->other_cmd[0], "cd"))
		return (handle_cd(hons));

	else if (!_strcmp(hons->other_cmd[0], "setenv"))
	{
		if (hons->other_cmd[1] && hons->other_cmd[2])
			return (setenv(hons->other_cmd[1], hons->other_cmd[2], 1));
		return (1); /* invalid number of parameters received */
	}
	else if (!_strcmp(hons->other_cmd[0], "unsetenv"))
		return (_unsetenv(hons->other_cmd[1]));

	return (NOT_BUILTIN); /* not a builtin command */
}
