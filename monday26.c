#include "main.h"

/**
 * how_long - Get the lenght of a number.
 * @mbr_int: type int number.
 * Return: Lenght of a number.
 */
int how_long(int mbr_int)
{
	unsigned int kally;
	int xcluss = 1;

	if (mbr_int < 0)
	{
		xcluss++;
		kally = mbr_int * -1;
	}
	else
	{
		kally = mbr_int;
	}
	while (kally > 9)
	{
		xcluss++;
		kally = kally / 10;
	}

	return (xcluss);
}
/**
 * conv_num - function converts int to string.
 * @mbr_int: type int number
 * Return: String.
 */
char *conv_num(int mbr_int)
{
	unsigned int kally;
	int xcluss = how_long(mbr_int);
	char *kezy;

	kezy = malloc(sizeof(char) * (xcluss + 1));
	if (kezy == 0)
		return (NULL);

	*(kezy + xcluss) = '\0';

	if (mbr_int < 0)
	{
		kally = mbr_int * -1;
		kezy[0] = '-';
	}
	else
	{
		kally = mbr_int;
	}

	xcluss--;
	do {
		*(kezy + xcluss) = (kally % 10) + '0';
		kally = kally / 10;
		xcluss--;
	}
	while (kally > 0)
		;
	return (kezy);
}

/**
 * str_oax - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int str_oax(char *s)
{
	unsigned int comm = 0, muzamy = 0, indani = 0, frere = 1, rollly = 1, i;

	while (*(s + comm) != '\0')
	{
		if (muzamy > 0 && (*(s + comm) < '0' || *(s + comm) > '9'))
			break;

		if (*(s + comm) == '-')
			frere *= -1;

		if ((*(s + comm) >= '0') && (*(s + comm) <= '9'))
		{
			if (muzamy > 0)
				rollly *= 10;
			muzamy++;
		}
		comm++;
	}

	for (i = comm - muzamy; i < comm; i++)
	{
		indani = indani + ((*(s + i) - 48) * rollly);
		rollly /= 10;
	}
	return (indani * frere);
}
