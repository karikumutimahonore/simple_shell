#include "main.h"

/**
 * without_comment - remove comments from the input
 *
 * @in: input string
 * Return: in.
 */
char *without_comment(char *in)
{
	int fro, to_the;

	to_the = 0;
	for (fro = 0; in[fro]; fro++)
	{
		if (in[fro] == '#')
		{
			if (fro == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[fro - 1] == ' ' || in[fro - 1] == '\t' || in[fro - 1] == ';')
				to_the = fro;
		}
	}

	if (to_the != 0)
	{
		in = _realloc(in, fro, to_the + 1);
		in[to_the] = '\0';
	}

	return (in);
}

/**
 * shell_loop - luupy of shell
 * @datash: data relevant.
 *
 * Return: no return.
 */
void shell_loop(datacliff *datash)
{
	int luupy, i_foe;
	char *input;

	luupy = 1;
	while (luupy == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		input = soma_umur(&i_foe);
		if (i_foe != -1)
		{
			input = without_comment(input);
			if (input == NULL)
				continue;

			if (syntax_error_check(datash, input) == 1)
			{
				datash->stts = 2;
				free(input);
				continue;
			}
			input = indur_var(input, datash);
			luupy = split_commands(datash, input);
			datash->determine += 1;
			free(input);
		}
		else
		{
			luupy = 0;
			free(input);
		}
	}
}
