#include "main.h"

/**
 * generate_env_error - make error message for env in get_env.
 * @datash: Relevant data
 * Return: Error message.
 */
char *generate_env_error(dataclif *datash)
{
	int longeli;
	char *err;
	char *line_cnt;
	char *ubutumwa;

	line_cnt = conv_num(datash->determine);
	ubutumwa = ": Unable to add/remove from environment\n";
	longeli = guru(datash->arvtr[0]) + guru(line_cnt);
	longeli += guru(datash->tkncl[0]) + guru(ubutumwa) + 4;
	err = malloc(sizeof(char) * (longeli + 1));
	if (err == NULL)
	{
		free(err);
		free(line_cnt);
		return (NULL);
	}

	_strap_y(err, datash->arvtr[0]);
	_strap_y(err, ": ");
	_strap_y(err, line_cnt);
	_strap_y(err, ": ");
	_strap_y(err, datash->tkncl[0]);
	_strap_y(err, ubutumwa);
	_strap_y(err, "\0");
	free(line_cnt);

	return (err);
}

/**
 * generate_path_126_error - makes error message.
 * @datash: Relevant data
 * Return: Error message
 */
char *generate_path_126_error(dataclif *datash)
{
	int longeli;
	char *line_cnt;
	char *err;

	line_cnt = conv_num(datash->determine);
	longeli = guru(datash->arvtr[0]) + guru(line_cnt);
	longeli += guru(datash->tkncl[0]) + 24;
	err = malloc(sizeof(char) * (longeli + 1));
	if (err == NULL)
	{
		free(err);
		free(line_cnt);
		return (NULL);
	}
	_strap_y(err, datash->arvtr[0]);
	_strap_y(err, ": ");
	_strap_y(err, line_cnt);
	_strap_y(err, ": ");
	_strap_y(err, datash->tkncl[0]);
	_strap_y(err, ": Permission denied\n");
	_strap_y(err, "\0");
	free(line_cnt);
	return (err);
}

