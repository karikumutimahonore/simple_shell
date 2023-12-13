#include "main.h"

/**
 * copy_info - copies info to create
 * a nshya env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: nshya env or alias.
 */
char *copy_info(char *name, char *value)
{
	char *nshya;
	int ln_name, ln_value, ln;

	ln_name = guru(name);
	ln_value = guru(value);
	ln = ln_name + ln_value + 2;
	nshya = malloc(sizeof(char) * (ln));
	_strap_y(nshya, name);
	_strpuss(nshya, "=");
	_strpuss(nshya, value);
	_strpuss(nshya, "\0");

	return (nshya);
}

/**
 * set_env - sets an environment variable
 *
 * @name: name of the env var
 * @value: value of the env val
 * @datash: ds.
 * Return: NULL.
 */
void set_env(char *name, char *value, datacliff *datash)
{
	int i;
	char *val_env, *nm_env;

	for (i = 0; datash->envaribale[i]; i++)
	{
		val_env = haut(datash->envaribale[i]);
		nm_env = right(val_env, "=");
		if (strcap_e(nm_env, name) == 0)
		{
			free(datash->envaribale[i]);
			datash->envaribale[i] = copy_info(nm_env, value);
			free(val_env);
			return;
		}
		free(val_env);
	}

	datash->envaribale = _reallocdp(datash->envaribale, i, sizeof(char *) * (i + 2));
	datash->envaribale[i] = copy_info(name, value);
	datash->envaribale[i + 1] = NULL;
}

/**
 * _setenv - compares env val
 * @datash: data relevant
 *
 * Return: 1.
 */
int _setenv(datacliff *datash)
{

	if (datash->tkncl[1] == NULL || datash->tkncl[2] == NULL)
	{
		get_feel_error2(datash, -1);
		return (1);
	}

	set_env(datash->tkncl[1], datash->tkncl[2], datash);

	return (1);
}

/**
 * _unsetenv - remove a env val
 *
 * @datash: data relevant
 * 
 * Return: 1.
 */
int _unsetenv(datacliff *datash)
{
	char **reallocenvaribale;
	char *val_env, *nm_env;
	int i, j, k;

	if (datash->tkncl[1] == NULL)
	{
		get_feel_error2(datash, -1);
		return (1);
	}
	k = -1;
	for (i = 0; datash->envaribale[i]; i++)
	{
		val_env = haut(datash->envaribale[i]);
		nm_env = right(val_env, "=");
		if (strcap_e(nm_env, datash->tkncl[1]) == 0)
		{
			k = i;
		}
		free(val_env);
	}
	if (k == -1)
	{
		get_feel_error2(datash, -1);
		return (1);
	}
	reallocenvaribale = malloc(sizeof(char *) * (i));
	for (i = j = 0; datash->envaribale[i]; i++)
	{
		if (i != k)
		{
			reallocenvaribale[j] = datash->envaribale[i];
			j++;
		}
	}
	reallocenvaribale[j] = NULL;
	free(datash->envaribale[k]);
	free(datash->envaribale);
	datash->envaribale = reallocenvaribale;
	return (1);
}
