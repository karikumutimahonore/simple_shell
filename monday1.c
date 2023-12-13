#include "honore.h"

/**
 * pass_linne - yakira command linne akana yi handling mbere.
 * @hons: contains data relev.
 *
 * Return: 0.
 */
int pass_line(shell_t *hons)
{
	size_t start;

	if (*hons->linne == '\n' || *hons->linne == '#')
		return (0);

	hons->linne = handle_comments(hons->linne);

	hons->credential = _strtok(hons->linne, "\n");
	if (hons->credential == NULL)
	{
		fprintf(stderr, "Not enough system memory to continue\n");
		return (-1);
	}

	for (i = 0; hons->credential[start] != NULL; i++)
	{
		hons->token = hons->credential[start];

		if (!_strcmp(hons->credential[start], "exit") && 
			hons->credential[start + 1] == NULL)
		{
			handle_exit(hons, multi_free);
		}

		hons->commands = _strtok(hons->token, ";\n");
		if (hons->commands == NULL)
		{
			fprintf(stderr, "Memory allocation failed...\n");
			return (-1);
		}

		hons->terminate_code = pulse(hons);
		free_str(&hons->commands);
	}

	free_str(&hons->credential);
	return (hons->terminate_code);
}

/**
 * pulse - pass command and accept new prompt
 * @hons: contains data releva
 *
 * Return: terminate_code.
 */
int pulse(shell_t *hons)
{
	ssize_t i, offset;
	char *cur_cmd = NULL, *operator = NULL;
	char *next_cmd = NULL, *temp_next_cmd = NULL;

	for (i = 0; hons->commands[i] != NULL; i++)
	{
		operator = get_operator(hons->commands[i]);
		if (operator != NULL)
		{
			offset = strcspn(hons->commands[i], operator);
			cur_cmd = strndup(hons->commands[i], offset);
			if (cur_cmd == NULL)
				return (0);
			hons->other_cmd = _strtok(cur_cmd, NULL);
			safe_free(cur_cmd);
			if (hons->other_cmd == NULL)
				return (0);
			hons->other_cmd = handle_variables(hons);
			pulse_helper(hons, i);

			temp_next_cmd = _strdup(&hons->commands[i][offset + 2]);
			safe_free(next_cmd);
			safe_free(hons->commands[i]);

			if ((!_strcmp(operator, "&&") && hons->terminate_code == 0) ||
				(!_strcmp(operator, "||") && hons->terminate_code != 0))
			{
				hons->commands[i] = temp_next_cmd;
				pulse(hons);
				next_cmd = temp_next_cmd;
			}
			else
				safe_free(temp_next_cmd);
		}
		else
			pulse_and_tambuka(hons, i);
	}
	return (hons->terminate_code);
}

/**
 * pulse_and_tambuka - pass linne by linne and execut
 * @hons: contains data releva.
 * @index: the current i
 *
 * Return: the exit code.
 */
int pulse_and_tambuka(shell_t *hons, size_t index)
{
	hons->other_cmd = _strtok(hons->commands[index], NULL);
	if (hons->other_cmd == NULL)
	{
		return (0);
	}

	hons->other_cmd = handle_variables(hons);
	if (hons->other_cmd[0] != NULL && hons->other_cmd != NULL)
		pulse_helper(hons, index);
	else
		free_str(&hons->other_cmd);

	safe_free(hons->commands[index]);
	return (hons->terminate_code);
}

/**
 * pulse_helper - pass an extra parsing
 * @hons: contains alldrghj
 * @index: the current.
 */
void pulse_helper(shell_t *hons, size_t index)
{
	char *alias_value;

	if (!_strcmp(hons->other_cmd[0], "alias") ||
			!_strcmp(hons->other_cmd[0], "unalias"))
	{
		hons->terminate_code = handle_alias(&hons->aliyases, hons->commands[index]);
		free_str(&hons->other_cmd);
		return;
	}

	alias_value = get_alias(hons->aliyases, hons->other_cmd[0]);
	if (alias_value != NULL)
	{
		build_alias_cmd(&hons->other_cmd, alias_value);
		safe_free(alias_value);
	}

	hons->terminate_code = handle_builtin(hons);
	if (hons->terminate_code != NOT_BUILTIN)
	{
		free_str(&hons->other_cmd);
		return;
	}
	if (hons->path_list != NULL && !_strchr(hons->other_cmd[0], '/'))
	{
		hons->terminate_code = handle_with_path(hons);
		if (hons->terminate_code == -1)
			hons->terminate_code = print_cmd_not_found(hons);
	}
	else
	{
		if (access(hons->other_cmd[0], X_OK) == 0 &&
				_strchr(hons->other_cmd[0], '/'))
			hons->terminate_code = execute_command(hons->other_cmd[0], hons);
		else
			hons->terminate_code = print_cmd_not_found(hons);
	}
	free_str(&hons->other_cmd);
}

/**
 * print_cmd_not_found - prints the commasdfgh
 * @hons: contains alldfghjm,
 *
 * Return: 0.
 */
int print_cmd_not_found(shell_t *hons)
{
	dprintf(STDERR_FILENO, "%s: %lu: %s: not found\n", hons->prog_name,
			hons->comm_calc, hons->other_cmd[0]);

	return (CMD_NOT_FOUND);
}
