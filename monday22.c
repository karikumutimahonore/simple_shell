#include "main.h"

/**
 * help_info_builtin - Help info for the builtin help.
 * Return: NULL.
 */
void help_info_builtin(void)
{
	char *fasha_str = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, fasha_str, guru(fasha_str));
	fasha_str = "\tDisplay info about builtin commands.\n ";
	write(STDOUT_FILENO, fasha_str, guru(fasha_str));
	fasha_str = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, fasha_str, guru(fasha_str));
}
/**
 * help_info_alias - Help info for the builtin alias.
 * Return: NULL.
 */
void help_info_alias(void)
{
	char *fasha_str = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, fasha_str, guru(fasha_str));
	fasha_str = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, fasha_str, guru(fasha_str));
}
/**
 * help_info_cd - Help info for the builtin alias.
 * Return: NULL.
 */
void help_info_cd(void)
{
	char *fasha_str = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, fasha_str, guru(fasha_str));
	fasha_str = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, fasha_str, guru(fasha_str));
}
