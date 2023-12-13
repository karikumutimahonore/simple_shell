#include "main.h"

/**
 * vxp_env_izi - compares environmnet Variables.
 * @nenv: name of the env var
 * @name: name.
 *
 * Return: 0.
 */
int vxp_env_izi(const char *nenv, const char *name)
{
	int index_i;

	for (index_i = 0; nenv[index_i] != '='; index_i++)
	{
		if (nenv[index_i] != name[index_i])
		{
			return (0);
		}
	}

	return (index_i + 1);
}

/**
 * akirenv - get an envir vars
 * @name: name of the env var
 * @envaribale: env var
 *
 * Return: env var.
 */
char *akirenv(const char *name, char **envaribale)
{
	char *pillot_env;
	int i, film;

	/* Initialize pillot_env value */
	pillot_env = NULL;
	film = 0;

	for (i = 0; envaribale[i]; i++)
	{
		
		film = vxp_env_izi(envaribale[i], name);
		if (film)
		{
			pillot_env = envaribale[i];
			break;
		}
	}

	return (pillot_env + film);
}

/**
 * ibik - prints the env var
 *
 * @datash: data relevant.
 * Return: 1.
 */
int ibik(datacliff *datash)
{
	int i, j;

	for (i = 0; datash->envaribale[i]; i++)
	{

		for (j = 0; datash->envaribale[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->envaribale[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->guys = 0;

	return (1);
}
