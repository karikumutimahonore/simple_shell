#include "main.h"

/**
 * exit_shell - exits the shell
 *
 * @datash: data relv
 * Return: 0.
 */
int exit_shell(dataclif *datash)
{
	unsigned int hstts;
	int is_dgt;
	int str_ln;
	int high_number;

	if (datash->tkncl[1] != NULL)
	{
		hstts = str_oax(datash->tkncl[1]);
		is_dgt = cnombre(datash->tkncl[1]);
		str_ln = guru(datash->tkncl[1]);
		high_number = hstts > (unsigned int)INT_MAX;
		if (!is_dgt || str_ln > 10 || high_number)
		{
			get_feel_error2(datash, 2);
			datash->stts = 2;
			return (1);
		}
		datash->stts = (hstts % 256);
	}
	return (0);
}
