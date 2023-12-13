#include "main.h"

/**
 * akir_ubuf - function that retrieves messages.
 * @rndsh: ds.
 * Return: 0.
*/
int akir_ubuf(datacliff *rndsh)
{

	if (rndsh->tkncl[1] == 0)
		duo_color();
	else if (strcap_e(rndsh->tkncl[1], "setenv") == 0)
		invert_color();
	else if (strcap_e(rndsh->tkncl[1], "env") == 0)
		load_color();
	else if (strcap_e(rndsh->tkncl[1], "unsetenv") == 0)
		lens_color();
	else if (strcap_e(rndsh->tkncl[1], "help") == 0)
		help_info_builtin();
	else if (strcap_e(rndsh->tkncl[1], "exit") == 0)
		saturn_color();
	else if (strcap_e(rndsh->tkncl[1], "cd") == 0)
		help_info_cd();
	else if (strcap_e(rndsh->tkncl[1], "alias") == 0)
		help_info_alias();
	else
		write(STDERR_FILENO, rndsh->tkncl[0],
		      guru(rndsh->tkncl[0]));

	rndsh->stts = 0;
	return (1);
}
