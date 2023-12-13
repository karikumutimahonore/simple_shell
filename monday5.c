#include "main.h"

/**
 * concat_error_message - function that
 * concat the message.
 *
 * @rndsh: data relevant (directory)
 * @ubutumwa: message to be print
 * @err: output to be message
 * @line_cnt: counter lines
 * Return: err.
 */
char *concat_error_message(dataclif *rndsh, char *ubutumwa, char *err,
		char *line_cnt)
{
	char *illegal_flag;

	_strap_y(err, rndsh->arvtr[0]);
	_strap_y(err, ": ");
	_strap_y(err, line_cnt);
	_strap_y(err, ": ");
	_strap_y(err, rndsh->tkncl[0]);
	_strap_y(err, ubutumwa);
	if (rndsh->tkncl[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = rndsh->tkncl[1][1];
		illegal_flag[2] = '\0';
		_strap_y(err, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strap_y(err, rndsh->tkncl[1]);
	}

	_strap_y(err, "\n");
	_strap_y(err, "\0");
	return (err);
}

/**
 * get_cd_error_message - err message for cd command in get_cd
 * @rndsh: data relevant.
 * Return: Err.
 */
char *get_cd_error_message(dataclif *rndsh)
{
	int longeli, len_id;
	char *err, *line_cnt, *ubutumwa;

	line_cnt = conv_num(rndsh->determine);
	if (rndsh->tkncl[1][0] == '-')
	{
		ubutumwa = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		ubutumwa = ": can't cd to ";

		len_id = guru(rndsh->tkncl[1]);
	}

	longeli = guru(rndsh->arvtr[0]) + guru(rndsh->tkncl[0]);
	longeli += guru(line_cnt) + guru(ubutumwa) + len_id + 5;
	err = malloc(sizeof(char) * (longeli + 1));

	if (err == 0)
	{
		free(line_cnt);
		return (NULL);
	}

	err = concat_error_message(rndsh, ubutumwa, err, line_cnt);

	free(line_cnt);

	return (err);
}

/**
 * get_not_found_error - generic error message
 * @rndsh: data relevant.
 * Return: Err.
 */
char *get_not_found_error(dataclif *rndsh)
{
	int longeli;
	char *err;
	char *line_cnt;

	line_cnt = conv_num(rndsh->determine);
	longeli = guru(rndsh->arvtr[0]) + guru(line_cnt);
	longeli += guru(rndsh->tkncl[0]) + 16;
	err = malloc(sizeof(char) * (longeli + 1));
	if (err == 0)
	{
		free(err);
		free(line_cnt);
		return (NULL);
	}
	_strap_y(err, rndsh->arvtr[0]);
	_strap_y(err, ": ");
	_strap_y(err, line_cnt);
	_strap_y(err, ": ");
	_strap_y(err, rndsh->tkncl[0]);
	_strap_y(err, ": not found\n");
	_strap_y(err, "\0");
	free(line_cnt);
	return (err);
}

/**
 * get_exit_shell_error - generic error message for exit in get_exit
 * @rndsh: data relevant (determine, arguments)
 *
 * Return: Error message
 */
char *get_exit_shell_error(dataclif *rndsh)
{
	int longeli;
	char *err;
	char *line_cnt;

	line_cnt = conv_num(rndsh->determine);
	longeli = guru(rndsh->arvtr[0]) + guru(line_cnt);
	longeli += guru(rndsh->tkncl[0]) + guru(rndsh->tkncl[1]) + 23;
	err = malloc(sizeof(char) * (longeli + 1));
	if (err == 0)
	{
		free(line_cnt);
		return (NULL);
	}
	_strap_y(err, rndsh->arvtr[0]);
	_strap_y(err, ": ");
	_strap_y(err, line_cnt);
	_strap_y(err, ": ");
	_strap_y(err, rndsh->tkncl[0]);
	_strap_y(err, ": Illegal number: ");
	_strap_y(err, rndsh->tkncl[1]);
	_strap_y(err, "\n\0");
	free(line_cnt);

	return (err);
}

