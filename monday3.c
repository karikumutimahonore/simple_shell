#include "honore.h"

static int exit_code;

/**
 * handle_alias - handles alias.
 * @umutwe: a pointer to the list containing all aliyases
 * @hanga: the list of hangas containing alias-specific lines
 *
 * Return: 0 on success, -1 on error
 */
int handle_alias(alias_t **umutwe, char *hanga)
{
	while (*hanga == ' ')
		hanga++;

	if (_strlen(hanga) == 5)
		print_aliyases(*umutwe);

	else if (!_strncmp(hanga, "alias", 5))
	{
		if (!_strchr(hanga, '='))
			process_non_matching(*umutwe, hanga + 5, 1);
		else
			parse_aliyases(hanga, umutwe);
	}

	else if (!_strncmp(hanga, "unalias", 7))
		return (unalias(umutwe, hanga));

	return (exit_code);
}

/**
 * parse_aliyases - extract adfghj
 * @input: the input string containing aliyases
 * @aliyases: a pointer to a lisdfcvb
 *
 * Description: This function useasdfgghhnsrdtfyghj.
 */
void parse_aliyases(const char *input, alias_t **aliyases)
{
	char *npt_prt = NULL;
	size_t vallen, aliyas_cnt = 0;
	regmatch_t matches[3];
	regex_t regex;
	const char *pattern =
		"([^\"]\\S*|\"[^\"]*\"|'[^\']*')=([^\"]\\S*|\"[^\"]*\"|'[^\']*')";

	if (regcomp(&regex, pattern, REG_EXTENDED) != 0)
		return;
	npt_prt = (char *)input;
	while (regexec(&regex, npt_prt, 3, matches, 0) == 0)
	{
		char name[MAX_ALIAS_LENGTH] = {0};
		char value[MAX_VALUE_LENGTH] = {0};

		_strncpy(name, (npt_prt + 1) + matches[1].rm_so,
				 (matches[1].rm_eo - 1) - matches[1].rm_so);
		_strncpy(value, npt_prt + matches[2].rm_so,
				 matches[2].rm_eo - matches[2].rm_so);
		name[matches[1].rm_eo - matches[1].rm_so] = '\0';

		vallen = matches[2].rm_eo - matches[2].rm_so;
		if (isquote(value[0]))
		{
			_strncpy(value, npt_prt + matches[2].rm_so + 1, vallen - 2);
			value[vallen - 2] = '\0';
		}
		else
			value[vallen] = '\0';
		if (add_alias(aliyases, name, value) == NULL)
			return;
		if (aliyas_cnt)
			process_non_matching(*aliyases, npt_prt, 0);
		aliyas_cnt++;
		npt_prt += matches[0].rm_eo;
	}
	if (aliyas_cnt)
		process_non_matching(*aliyases, npt_prt, 1);
	regfree(&regex);
}

/**
 * process_non_matching - processes strings that dsasdfghh
 * @aliyases: a list contaawesdfghjk
 * @non_matching: the string to checkzdsdfgfhjj
 * @end: used to signal dsfghjk
 */
void process_non_matching(alias_t *aliyases, const char *non_matching, int end)
{
	char *token, *dup;

	if (non_matching == NULL || *non_matching == '\0')
		return;

	dup = _strdup(non_matching);
	token = strtok(dup, " ");

	if (!_strchr(token, '='))
	{
		if (end)
		{
			while (token != NULL)
			{
				exit_code = print_alias(aliyases, token);
				token = strtok(NULL, " ");
			}
		}
		else
			exit_code = print_alias(aliyases, token);
	}
	free(dup);
}

/**
 * build_alias_cmd - builds the srdtyuhkj
 * a valid alias hanga
 * @sub_hanga: a pointer to the array contdsfghbmn
 * @alias_value: the value owaesrdfgb
 */
void build_alias_cmd(char ***sub_hanga, char *alias_value)
{
	char **dup_array = NULL;

	if ((*sub_hanga)[1] != NULL)
	{
		dup_array = duplicate_str_array((*sub_hanga) + 1);
		if (dup_array == NULL)
		{
			fprintf(stderr, "alias: Memory allocation failed\n");
			return;
		}

		free_str(sub_hanga);
		*sub_hanga = _strtok(alias_value, NULL);

		concatenate_arrays(sub_hanga, dup_array);

		free_str(&dup_array);
	}
	else
	{
		free_str(sub_hanga);
		*sub_hanga = _strtok(alias_value, NULL);
	}
}
