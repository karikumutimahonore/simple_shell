#include "main.h"

/**
 * got_data - frees data structure
 *
 * @rndsh: data structure
 * Return: no return
 */
void got_data(datacliff *rndsh)
{
	unsigned int i;

	for (i = 0; rndsh->envaribale[i]; i++)
	{
		free(rndsh->envaribale[i]);
	}

	free(rndsh->envaribale);
	free(rndsh->id_pid);
}

/**
 * ubaka_data - Initialize data structure
 *
 * @rndsh: data structure
 * @agv: argument vector
 * Return: no return
 */
void ubaka_data(datacliff *rndsh, char **agv)
{
	unsigned int i;

	rndsh->agv = agv;
	rndsh->cmluser = NULL;
	rndsh->tkncl = NULL;
	rndsh->stts = 0;
	rndsh->determine = 1;

	for (i = 0; environ[i]; i++)
		;

	rndsh->envaribale = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		rndsh->envaribale[i] = haut(environ[i]);
	}

	rndsh->envaribale[i] = NULL;
	rndsh->id_pid = conv_num(getpid());
}

/**
 * maix - Entry point
 *
 * @act: argument count
 * @agv: argument vector
 *
 * Return: 0.
 */
int main(int act, char **agv)
{
	datacliff rndsh;
	(void) act;

	signal(SIGINT, get_sigint);
	ubaka_data(&rndsh, agv);
	shell_loop(&rndsh);
	got_data(&rndsh);
	if (rndsh.stts < 0)
		return (255);
	return (rndsh.stts);
}
