#include "main.h"
#include "smplshll.h"

/**
 * swap_char - swamps | and & for non-print character
 *
 * @cmluser: input str
 * @bol: type of swap
 * Return: swped str.
 */
char *swap_char(char *cmluser, int bol)
{
	int i;

	if (bol == 0)
	{
		for (i = 0; cmluser[i]; i++)
		{
			if (cmluser[i] == '|')
			{
				if (cmluser[i + 1] != '|')
					cmluser[i] = 16;
				else
					i++;
			}

			if (cmluser[i] == '&')
			{
				if (cmluser[i + 1] != '&')
					cmluser[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; cmluser[i]; i++)
		{
			cmluser[i] = (cmluser[i] == 16 ? '|' : cmluser[i]);
			cmluser[i] = (cmluser[i] == 12 ? '&' : cmluser[i]);
		}
	}
	return (cmluser);
}

/**
 * add_nodes - add separators and command lines in the lists
 *
 * @head_s: head of separator list
 * @head_l: head of command lines list
 * @cmluser: input string
 * Return: NULL
 */
void add_nodes(blame_lists **head_s, ligna_lista **head_l, char *cmluser)
{
	int i = 0;
	char *ligna;

	cmluser = swap_char(cmluser, 0);

	for (i; cmluser[i]; i++)
	{
		if (cmluser[i] == ';')
			pin_stuff(head_s, cmluser[i]);

		if (cmluser[i] == '|' || cmluser[i] == '&')
		{
			pin_stuff(head_s, cmluser[i]);
			i++;
		}
	}

	ligna = right(cmluser, ";|&");
	do {
		ligna = swap_char(ligna, 1);
		lead_stuff(head_l, ligna);
		ligna = right(NULL, ";|&");
	} while (ligna != NULL);

}

/**
 * go_next - go to the next command line stored
 *
 * @list_s: separator list
 * @list_l: command line list
 * @rndsh: data structure
 * Return: no return
 */
void go_next(blame_lists **list_s, ligna_lista **list_l, datacliff *rndsh)
{
	int luppy_sep;
	blame_lists *ls_s;
	ligna_lista *ls_l;

	luppy_sep = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && luppy_sep)
	{

		if (rndsh->guys == 0)
		{
			if (ls_s->separateur == '&' || ls_s->separateur == ';')
				luppy_sep = 0;
			if (ls_s->separateur == '|')
				ls_l = ls_l->followedNode, ls_s = ls_s->followedNode;
		}
		else
		{
			if (ls_s->separateur == '|' || ls_s->separateur == ';')
				luppy_sep = 0;
			if (ls_s->separateur == '&')
				ls_l = ls_l->followedNode, ls_s = ls_s->followedNode;
		}
		if (ls_s != NULL && !luppy_sep)
			ls_s = ls_s->followedNode;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * split_commands - splits command lines according to
 * the separators ;, | and &, and executes them
 *
 * @rndsh: data structure
 * @cmluser: input string
 * Return: 0 to exit, 1 to continue
 */
int split_commands(datacliff *rndsh, char *cmluser)
{

	blame_lists *head_s, *list_s;
	ligna_lista *head_l, *list_l;
	int luppy;

	head_s = NULL;
	head_l = NULL;

	add_nodes(&head_s, &head_l, cmluser);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		rndsh->cmluser = list_l->ligna;
		rndsh->kwargs = split_line(rndsh->cmluser);
		luppy = iher_umur(rndsh);
		free(rndsh->kwargs);


		if (luppy == 0)
			break;

		go_next(&list_s, &list_l, rndsh);

		if (list_l != NULL)
			list_l = list_l->followedNode;
	}

	jargon_stuff(&head_s);
	oblique_stuff(&head_l);

	if (luppy == 0)
		return (0);
	return (1);
}

/**
 * split_line - tknz the input string
 *
 * @cmluser: input string.
 * Return: string splitted.
 */
char **split_line(char *cmluser)
{
	size_t bsize;
	size_t i;
	char **tokens;
	char *token;

	bsize = TOK_BUFSIZE;
	tokens = malloc(sizeof(char *) * (bsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = right(cmluser, TOK_DELIM);
	tokens[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == bsize)
		{
			bsize += TOK_BUFSIZE;
			tokens = _reallocdp(tokens, i, sizeof(char *) * bsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = right(NULL, TOK_DELIM);
		tokens[i] = token;
	}

	return (tokens);
}
