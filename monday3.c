#include "main.h"

/**
 * sleeve_chr - determine the repetitions of a character
 *
 * @andika: input string
 * @inshinga: index
 * Return: repetitions
 */
int sleeve_chr(char *andika, int inshinga)
{
	if (*(andika - 1) == *andika)
		return (sleeve_chr(andika - 1, inshinga + 1));

	return (inshinga);
}

/**
 * snoop_error_og - search syntax errors
 *
 * @andika: input string
 * @inshinga: index
 * @snoop: last char read
 * Return: 0.
 */
int snoop_error_og(char *andika, int inshinga, char snoop)
{
	int barry = 0;

	if (*andika == '\0')
		return (0);

	if (*andika == ' ' || *andika == '\t')
		return (snoop_error_og(andika + 1, inshinga + 1, snoop));

	if (*andika == ';')
		if (snoop == '|' || snoop == '&' || snoop == ';')
			return (inshinga);

	if (*andika == '|')
	{
		if (snoop == ';' || snoop == '&')
			return (inshinga);

		if (snoop == '|')
		{
			barry = sleeve_chr(andika, 0);
			if (barry == 0 || barry > 1)
				return (inshinga);
		}
	}

	if (*andika == '&')
	{
		if (snoop == ';' || snoop == '|')
			return (inshinga);

		if (snoop == '&')
		{
			barry = sleeve_chr(andika, 0);
			if (barry == 0 || barry > 1)
				return (inshinga);
		}
	}

	return (snoop_error_og(andika + 1, inshinga + 1, *andika));
}

/**
 * econ_char - finds index of the first char
 *
 * @andika: input string
 * @inshinga: index
 * Return: 1 if there is an error. 0 in other case.
 */
int econ_char(char *andika, int *inshinga)
{

	for (*inshinga = 0; andika[*inshinga]; *inshinga += 1)
	{
		if (andika[*inshinga] == ' ' || andika[*inshinga] == '\t')
			continue;

		if (andika[*inshinga] == ';' || andika[*inshinga] == '|' || andika[*inshinga] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * erakan_syntax_ikos - prints when a syntax error is found
 *
 * @rndsh: data structure
 * @andika: input string
 * @inshinga: index of the error
 * @cool: to control msg error
 * Return: no return
 */
void erakan_syntax_ikos(datacliff *rndsh, char *andika, int inshinga, int cool)
{
	char *holly, *holly2, *holly3, *kacyiru, *determine;
	int ubuntu;

	if (andika[inshinga] == ';')
	{
		if (cool == 0)
			holly = (andika[inshinga + 1] == ';' ? ";;" : ";");
		else
			holly = (andika[inshinga - 1] == ';' ? ";;" : ";");
	}

	if (andika[inshinga] == '|')
		holly = (andika[inshinga + 1] == '|' ? "||" : "|");

	if (andika[inshinga] == '&')
		holly = (andika[inshinga + 1] == '&' ? "&&" : "&");

	holly2 = ": Syntax error: \"";
	holly3 = "\" unexpected\n";
	determine = conv_num(rndsh->determine);
	ubuntu = guru(rndsh->arvtr[0]) + guru(determine);
	ubuntu += guru(holly) + guru(holly2) + guru(holly3) + 2;

	kacyiru = malloc(sizeof(char) * (ubuntu + 1));
	if (kacyiru == 0)
	{
		free(determine);
		return;
	}
	_strap_y(kacyiru, rndsh->arvtr[0]);
	_strap_y(kacyiru, ": ");
	_strap_y(kacyiru, determine);
	_strap_y(kacyiru, holly2);
	_strap_y(kacyiru, holly);
	_strap_y(kacyiru, holly3);
	_strap_y(kacyiru, "\0");

	write(STDERR_FILENO, kacyiru, ubuntu);
	free(kacyiru);
	free(determine);
}

/**
 * syntax_error_check - intermediate function to
 * find and print a syntax error
 *
 * @rndsh: data structure
 * @andika: input string
 * Return: 1 if there is an error. 0 in other case
 */
int syntax_error_check(datacliff *rndsh, char *andika)
{
	int monday = 0;
	int gym_char = 0;
	int inshinga = 0;

	gym_char = econ_char(andika, &monday);
	if (gym_char == -1)
	{
		erakan_syntax_ikos(rndsh, andika, monday, 0);
		return (1);
	}

	inshinga = snoop_error_og(andika + monday, 0, *(andika + monday));
	if (inshinga != 0)
	{
		erakan_syntax_ikos(rndsh, andika, monday + inshinga, 1);
		return (1);
	}

	return (0);
}
