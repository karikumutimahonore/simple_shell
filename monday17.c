#include "main.h"

/**
 * bring_line - assigns the line var for get_line
 * @linestr: Buff that store the ankd str
 * @buff: str that is been called to line
 * @n: size of line
 * @j: size of buff
 */
void bring_line(char **linestr, size_t *n, char *buff, size_t j)
{

	if (*linestr == NULL)
	{
		if  (j > BUFSIZE)
			*n = j;

		else
			*n = BUFSIZE;
		*linestr = buff;
	}
	else if (*n < j)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*linestr = buff;
	}
	else
	{
		_strap_y(*linestr, buff);
		free(buff);
	}
}
/**
 * get_line - Read ankdcd from stream
 * @linestr: buffert that stores the ankd
 * @n: size of line stringdsx
 * @stream: stream to read from
 * Return:bytes
 */
ssize_t get_line(char **linestr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t ankd;
	ssize_t retval;
	char *buff;
	char t = 'z';

	if (ankd == 0)
		fflush(stream);
	else
		return (-1);
	ankd = 0;

	buff = malloc(sizeof(char) * BUFSIZE);
	if (buff == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && ankd == 0))
		{
			free(buff);
			return (-1);
		}
		if (i == 0 && ankd != 0)
		{
			ankd++;
			break;
		}
		if (ankd >= BUFSIZE)
			buff = _realloc(buff, ankd, ankd + 1);
		buff[ankd] = t;
		ankd++;
	}
	buff[ankd] = '\0';
	bring_line(linestr, n, buff, ankd);
	retval = ankd;
	if (i != 0)
		ankd = 0;
	return (retval);
}
