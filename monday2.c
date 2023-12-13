#include "honore.h"

/**
 * _strtok - splits a string into words.
 * @str: The string to split
 * @delim: the delimeter to split on
 *
 * Return: a pointer to an array of strings (words) on success, NULL otherwise.
 */
char **_strtok(const char *str, const char *delim)
{
	char **str_arr;
	int amagambo_count, amagambo_start, amagambo_end;
	int len, num, i;
	char *tmp_delim = (char *)delim;

	if (delim == NULL)
		tmp_delim = " \t\n";

	amagambo_count = get_word_count(str, tmp_delim);
	if (amagambo_count == 0)
		return (NULL);

	str_arr = malloc((amagambo_count + 1) * sizeof(char *));
	if (str_arr == NULL)
		return (NULL);

	amagambo_start = num = 0;
	len = _strlen(str);

	for (i = 0; i < len; i++)
	{
		if ((!_strchr(tmp_delim, str[i]) && _strchr(tmp_delim, str[i + 1])) ||
			(!_strchr(tmp_delim, str[i]) && str[i + 1] == '\0'))
		{
			amagambo_end = i + 1;
			str_arr[num] = new_word(str, amagambo_start, amagambo_end);

			if (str_arr[num] == NULL)
				return (free_str(&str_arr), NULL);
			num++;
		}
		else if (!_strchr(tmp_delim, str[i]) && !_strchr(tmp_delim, str[i + 1]))
			continue;
		else
			amagambo_start = i + 1;
	}
	str_arr[num] = NULL;
	return (str_arr);
}

/**
 * _strpbrk - searches a strswerdtfyhjk
 * @s: string
 * @accept: subdsfghbmn,
 *
 * Description: The _strpbrk() function locatesdsfggbn.
 *
 * Return: A pointer.
 */
char *_strpbrk(const char *s, const char *accept)
{
	int ibuk, jugunya;

	for (ibuk = 0; s[ibuk] != '\0'; ibuk++)
	{
		for (jugunya = 0; accept[jugunya]; jugunya++)
		{
			if (s[ibuk] == accept[jugunya])
				return ((char *)&s[ibuk]);
		}
	}
	return (NULL);
}

/**
 * _strspn - get length of a prefix substring
 * @s: string
 * @accept: substring
 *
 * Description: The _strspn() function calculates.
 *
 * Return: The number of bytes.
 */
size_t _strspn(const char *s, const char *accept)
{
	size_t len = 0;
	int i = 0, map[256] = {0};

	if (s == NULL || accept == NULL)
		return (0);

	for (i; accept[i] != '\0'; i++)
		map[(unsigned char)accept[i]] = 1;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == SPACE)
			break;
		else if (map[(unsigned char)s[i]])
			len++;
		else
			break;
	}
	return (len);
}

/**
 * _strrchr - locate character in string (reverse)
 * @s: the string
 * @c: the character to search
 *
 * Description: The _strrchr() function.
 *
 * Return: a pointer
 */
char *_strrchr(const char *s, int c)
{
	char *tmp_ff = (char *)s;
	size_t len = _strlen(tmp_ff);

	if (s == NULL)
		return (NULL);

	while (tmp_ff[--len] != '\0')
	{
		if (tmp_ff[len] == c)
			return (tmp_ff + len);
	}
	if (c == '\0')
		return (tmp_ff);

	return (NULL);
}

/**
 * get_amagambo_count - Returns the number of words in a string.
 * @str: string
 * @delim: the delimeter to split on
 *
 * Return: Number of words
 */
int get_word_count(const char *str, const char *delim)
{
	int in_word = 0;
	int amagambo_count = 0;
	char *tmp_delim = (char *)delim;

	if (str == NULL || *str == '\0')
		return (0);

	if (delim == NULL)
		tmp_delim = " \t";

	while (*str)
	{
		if (_strchr(tmp_delim, *str))
		{
			in_word = 0;
		}
		else if (!in_word)
		{
			in_word = 1;
			amagambo_count++;
		}
		str++;
	}

	return (amagambo_count);
}
