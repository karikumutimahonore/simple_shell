#include "main.h"

/**
 * get_sigint - solve crtl + c call in prompt
 * @sign: Signal handler
 */
void get_sigint(int sign)
{
	(void)sign;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
