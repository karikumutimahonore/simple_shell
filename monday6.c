#include "honore.h"

/**
 * handle_variables - handles variables passed to the shell
 * @hons: shell data
 *
 * Return: the updated command with variables expanded if one was found, else
 * the @command is returned as received with no modifications
 */
char **handle_variables(shell_t *hons)
{
	size_t i;
	ssize_t offset;
	char *value, *loc, result[32];

	for (i = 0; hons->other_cmd[i] != NULL; i++)
	{
		loc = _strchr(hons->other_cmd[i], '$');
		if (loc == NULL)
			continue;

		offset = (&loc[0]) - (&hons->other_cmd[i][0]);

		if (hons->other_cmd[i][offset + 1] == '\0')
			continue;
		if (hons->other_cmd[i][offset + 1] == '$')
		{
			_itoa(getpid(), result);
			safe_free(hons->other_cmd[i]);
			hons->other_cmd[i] = _strdup(result);
		}
		else if (hons->other_cmd[i][offset + 1] == '?')
		{
			_itoa(hons->terminate_code, result);
			safe_free(hons->other_cmd[i]);
			hons->other_cmd[i] = _strdup(result);
		}
		else
		{
			value = _getenv(loc + 1);
			safe_free(hons->other_cmd[i]);
			hons->other_cmd[i] = _strdup(value);
		}
	}

	return (hons->other_cmd);
}
