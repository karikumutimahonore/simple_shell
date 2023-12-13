#include "honore.h"

/**
 * _getline - reads input from a file descriptor
 * @str_buff: a pointer to the string buffer (lineptr)
 * @num: number of bytes written
 * @file_disc: file descriptor(fd)
 *
 * Return: number of bytes.
 */
ssize_t _getline(char **str_buff, size_t *num, int file_disc)
{
	ssize_t num_reading;
	size_t Summ_read, buffer_size = BUFF_SIZE;

	/* verify allocate memory */
	if (*str_buff == NULL)
	{
		*str_buff = malloc(sizeof(char) * (buffer_size + 1));
		if (*str_buff == NULL)
			return (-1);
	}
	num_reading = Summ_read = 0;
	while ((num_reading = read(file_disc, *str_buff + Summ_read, BUFF_SIZE)) > 0)
	{
		Summ_read = Summ_read + num_reading;
		if (Summ_read >= buffer_size)
		{
			buffer_size *= 2;
			*str_buff = _realloc(*str_buff, Summ_read, buffer_size);
			if (*str_buff == NULL)
				return (-1);
			*num = Summ_read;
		}
		if (Summ_read && (*str_buff)[Summ_read - 1] == '\n')
		{
			(*str_buff)[Summ_read] = '\0';
			*num = Summ_read;
			return (Summ_read);
		}
	}
	if (num_reading == -1)
	{
		safe_free(*str_buff);
		return (-1);
	}
	if (Summ_read == 0)
		safe_free(*str_buff);

	return (Summ_read);
}
