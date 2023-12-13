#include "main.h"

/**
 * rnd_catch - changes current directory
 *
 * @pigsh: data relevant
 * Return: 1.
 */
int rnd_catch(dataclif *pigsh)
{
	char *tirmnl;
	int takken, wrttn, froky;

	tirmnl = pigsh->tkncl[1];

	if (tirmnl != NULL)
	{
		takken = strcap_e("$HOME", tirmnl);
		wrttn = strcap_e("~", tirmnl);
		froky = strcap_e("--", tirmnl);
	}

	if (tirmnl == NULL || !takken || !wrttn || !froky)
	{
		home_to_cdr(pigsh);
		return (1);
	}

	if (strcap_e("-", tirmnl) == 0)
	{
		previous_cmd(pigsh);
		return (1);
	}

	if (strcap_e(".", tirmnl) == 0 || strcap_e("..", tirmnl) == 0)
	{
		_dot(pigsh);
		return (1);
	}

	dot_cmd(pigsh);

	return (1);
}
