#include "main.h"

/**
 * load_color - Help info for the builtin env
 * Return: NULL
 */
void load_color(void)
{
	char *rekareka = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, rekareka, guru(rekareka));
	rekareka = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, rekareka, guru(rekareka));

}
/**
 * invert_color - Help info for the builtin setenv
 * Return: NULL
 */
void invert_color(void)
{

	char *rekareka = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, rekareka, guru(rekareka));
	rekareka = "int replace)\n\t";
	write(STDOUT_FILENO, rekareka, guru(rekareka));
	rekareka = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, rekareka, guru(rekareka));
}
/**
 * lens_color - Help info for the builtin
 * Return: NULL.
 */
void lens_color(void)
{
	char *rekareka = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, rekareka, guru(rekareka));
	rekareka = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, rekareka, guru(rekareka));
}


/**
 * duo_color - help builtin
 * Return: NULL.
 */
void duo_color(void)
{
	char *rekareka = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, rekareka, guru(rekareka));
	rekareka = "These commands are defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, rekareka, guru(rekareka));
	rekareka = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, rekareka, guru(rekareka));
	rekareka = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, rekareka, guru(rekareka));
	rekareka = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, rekareka, guru(rekareka));
	rekareka = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, rekareka, guru(rekareka));
	rekareka = "unsetenv [variable]\n";
	write(STDOUT_FILENO, rekareka, guru(rekareka));
}
/**
 * saturn_color - Help info fot the builin exit
 * Return: NULL.
 */
void saturn_color(void)
{
	char *rekareka = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, rekareka, guru(rekareka));
	rekareka = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, rekareka, guru(rekareka));
	rekareka = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, rekareka, guru(rekareka));
}
