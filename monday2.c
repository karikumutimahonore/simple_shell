#include "main.h"

/**
 * is_cdir - verify if ":" is in the pwd.
 * @path: character type of pointer char.
 * @i: integer type of pointer of index.
 * Return: 1.
 */
int is_cdir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
	{
		*i += 1;
	}

	if (path[*i])
		*i += 1;

	return (0);
}

/**
 * _which - functions that locates a command
 *
 * @cmd: command name
 * @envaribale: envrn variable
 * Return: loct.
 */
char *_which(char *cmd, char **envaribale)
{
	char *path, *ptr_path, *token_path, *dir;
	int ln_dill, ln_dmc, i;
	struct stat ct;

	path = akirenv("PATH", envaribale);
	if (path)
	{
		ptr_path = haut(path);
		ln_dmc = guru(cmd);
		token_path = right(ptr_path, ":");
		i = 0;
		while (token_path != NULL)
		{
			if (is_cdir(path, &i))
				if (stat(cmd, &ct) == 0)
					return (cmd);
			ln_dill = guru(token_path);
			dir = malloc(ln_dill + ln_dmc + 2);
			_strap_y(dir, token_path);
			_strpuss(dir, "/");
			_strpuss(dir, cmd);
			_strpuss(dir, "\0");
			if (stat(dir, &ct) == 0)
			{
				free(ptr_path);
				return (dir);
			}
			free(dir);
			token_path = right(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd, &ct) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &ct) == 0)
			return (cmd);
	return (NULL);
}

/**
 * is_executable - verify if it is an executable
 *
 * @datash: data structure
 * Return: 0.
 */
int is_executable(dataclif *datash)
{
	struct stat ct;
	int i;
	char *input;

	input = datash->tkncl[0];
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '.')
		{
			if (input[i + 1] == '.')
				return (0);
			if (input[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[i] == '/' && i != 0)
		{
			if (input[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(input + i, &ct) == 0)
	{
		return (i);
	}
	get_feel_error2(datash, 127);
	return (-1);
}

/**
 * check_error_cmd - check if user has permissions to access
 *
 * @dir: destiny directory
 * @datash: DS.
 * Return: 1.
 */
int check_error_cmd(char *dir, dataclif *datash)
{
	if (dir == NULL)
	{
		get_feel_error2(datash, 127);
		return (1);
	}

	if (strcap_e(datash->tkncl[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			get_feel_error2(datash, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(datash->tkncl[0], X_OK) == -1)
		{
			get_feel_error2(datash, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * cmd_exec - executes cl.
 *
 * @datash: data relevant.
 * Return: 1.
 */
int cmd_exec(dataclif *datash)
{
	pid_t pd;
	pid_t sstr;
	int stt;
	int exec;
	char *dir;
	(void) sstr;

	exec = is_executable(datash);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = _which(datash->tkncl[0], datash->envaribale);
		if (check_error_cmd(dir, datash) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = _which(datash->tkncl[0], datash->envaribale);
		else
			dir = datash->tkncl[0];
		execve(dir + exec, datash->tkncl, datash->envaribale);
	}
	else if (pd < 0)
	{
		perror(datash->evr[0]);
		return (1);
	}
	else
	{
		do {
			sstr = waitpid(pd, &stt, WUNTRACED);
		} while (!WIFEXITED(stt) && !WIFSIGNALED(stt));
	}

	datash->guys = stt / 256;
	return (1);
}
