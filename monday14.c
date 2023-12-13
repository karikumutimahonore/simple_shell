#include "main.h"

/**
 * _dot - cd.
 *
 * @rndsh: data relv
 *
 * Return: NULL.
 */
void _dot(datacliff *rndsh)
{
	char plunk[PATH_MAX];
	char *dir, *cp_plunk, *cpright_plunk;

	getcwd(plunk, sizeof(plunk));
	cp_plunk = haut(plunk);
	set_env("OLDPWD", cp_plunk, rndsh);
	dir = rndsh->tkncl[1];
	if (strcap_e(".", dir) == 0)
	{
		set_env("PWD", cp_plunk, rndsh);
		free(cp_plunk);
		return;
	}
	if (strcap_e("/", cp_plunk) == 0)
	{
		free(cp_plunk);
		return;
	}
	cpright_plunk = cp_plunk;
	rem_string(cpright_plunk);
	cpright_plunk = right(cpright_plunk, "/");
	if (cpright_plunk != NULL)
	{
		cpright_plunk = right(NULL, "\0");

		if (cpright_plunk != NULL)
			rem_string(cpright_plunk);
	}
	if (cpright_plunk != NULL)
	{
		chdir(cpright_plunk);
		set_env("PWD", cpright_plunk, rndsh);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", rndsh);
	}
	rndsh->stts = 0;
	free(cp_plunk);
}

/**
 * dot_cmd - changes to a directory.
 *
 * @rndsh: data relevant (directories)
 * Return: NULL.
 */
void dot_cmd(datacliff *rndsh)
{
	char plunk[PATH_MAX];
	char *dir, *cp_plunk, *cp_dir;

	getcwd(plunk, sizeof(plunk));

	dir = rndsh->tkncl[1];
	if (chdir(dir) == -1)
	{
		get_feel_error2(rndsh, 2);
		return;
	}

	cp_plunk = haut(plunk);
	set_env("OLDPWD", cp_plunk, rndsh);

	cp_dir = haut(dir);
	set_env("PWD", cp_dir, rndsh);

	free(cp_plunk);
	free(cp_dir);

	rndsh->stts = 0;

	chdir(dir);
}

/**
 * previous_cmd - changes to the backword directory
 *
 * @rndsh: data relv
 * Return: NULL
 */
void previous_cmd(datacliff *rndsh)
{
	char plunk[PATH_MAX];
	char *p_plunk, *p_oldplunk, *cp_plunk, *cp_oldplunk;

	getcwd(plunk, sizeof(plunk));
	cp_plunk = haut(plunk);

	p_oldplunk = akirenv("OLDPWD", rndsh->evision);
	if (p_oldplunk == NULL)
		cp_oldplunk = cp_plunk;
	else
		cp_oldplunk = haut(p_oldplunk);

	set_env("OLDPWD", cp_plunk, rndsh);

	if (chdir(cp_oldplunk) == -1)
		set_env("PWD", cp_plunk, rndsh);
	else
		set_env("PWD", cp_oldplunk, rndsh);

	p_plunk = akirenv("PWD", rndsh->evision);
	write(STDOUT_FILENO, p_plunk, guru(p_plunk));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_plunk);
	if (p_oldplunk)
		free(cp_oldplunk);

	rndsh->stts = 0;

	chdir(p_plunk);
}

/**
 * home_to_cdr - changes to home dir
 *
 * @rndsh: data relv
 * Return: null
 */
void home_to_cdr(datacliff *rndsh)
{
	char *p_plunk, *home;
	char plunk[PATH_MAX];

	getcwd(plunk, sizeof(plunk));
	p_plunk = haut(plunk);
	home = akirenv("HOME", rndsh->evision);

	if (home == NULL)
	{
		set_env("OLDPWD", p_plunk, rndsh);
		free(p_plunk);
		return;
	}

	if (chdir(home) == -1)
	{
		get_feel_error2(rndsh, 2);
		free(p_plunk);
		return;
	}

	set_env("OLDPWD", p_plunk, rndsh);
	set_env("PWD", home, rndsh);
	free(p_plunk);
	rndsh->stts = 0;
}
