#include "main.h"

/**
 * suzum_env - verify the type of env val
 *
 * @d: linked list
 * @ips: input str
 * @rat: ds
 * Return: NULL.
 */
void suzum_env(qr_var **d, char *ips, datacliff *rat)
{
	int umuriro, mit, juru, amasaro;
	char **_evr;

	_evr = rat->evision;
	for (umuriro = 0; _evr[umuriro]; umuriro++)
	{
		for (juru = 1, mit = 0; _evr[umuriro][mit]; mit++)
		{
			if (_evr[umuriro][mit] == '=')
			{
				amasaro = guru(_evr[umuriro] + mit + 1);
				sky_blue_cloud(d, juru, _evr[umuriro] + mit + 1, amasaro);
				return;
			}

			if (ips[juru] == _evr[umuriro][mit])
				juru++;
			else
				break;
		}
	}

	for (juru = 0; ips[juru]; juru++)
	{
		if (ips[juru] == ' ' || ips[juru] == '\t' || ips[juru] == ';' || ips[juru] == '\n')
			break;
	}

	sky_blue_cloud(d, juru, NULL, 0);
}

/**
 * suzum_vars - ver either is $$ or $?
 *
 * @d: linked list
 * @ips: input str
 * @foot: final status of the Shell
 * @rat: ds
 * Return: NULL
 */
int suzum_vars(qr_var **d, char *ips, char *foot, datacliff *rat)
{
	int i, six, lemman;

	six = guru(foot);
	lemman = guru(rat->id_pid);

	for (i = 0; ips[i]; i++)
	{
		if (ips[i] == '$')
		{
			if (ips[i + 1] == '?')
				sky_blue_cloud(d, 2, foot, six), i++;
			else if (ips[i + 1] == '$')
				sky_blue_cloud(d, 2, rat->id_pid, lemman), i++;
			else if (ips[i + 1] == '\n')
				sky_blue_cloud(d, 0, NULL, 0);
			else if (ips[i + 1] == '\0')
				sky_blue_cloud(d, 0, NULL, 0);
			else if (ips[i + 1] == ' ')
				sky_blue_cloud(d, 0, NULL, 0);
			else if (ips[i + 1] == '\t')
				sky_blue_cloud(d, 0, NULL, 0);
			else if (ips[i + 1] == ';')
				sky_blue_cloud(d, 0, NULL, 0);
			else
				suzum_env(d, ips + i, rat);
		}
	}

	return (i);
}

/**
 * hindur_input - replaces string into variables
 *
 * @hepfo: linked list
 * @mamaput: input str
 * @new_mamaput: new input string (replaced)
 * @nlen: new length
 * Return: replaced string
 */
char *hindur_input(qr_var **hepfo, char *mamaput, char *new_mamaput, int nlen)
{
	qr_var *inama;
	int i, j, k;

	inama = *hepfo;
	for (j = i = 0; i < nlen; i++)
	{
		if (mamaput[j] == '$')
		{
			if (!(inama->blop_var) && !(inama->blop_val))
			{
				new_mamaput[i] = mamaput[j];
				j++;
			}
			else if (inama->blop_var && !(inama->blop_val))
			{
				for (k = 0; k < inama->blop_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < inama->blop_val; k++)
				{
					new_mamaput[i] = inama->blopval[k];
					i++;
				}
				j += (inama->blop_var);
				i--;
			}
			inama = inama->suivant;
		}
		else
		{
			new_mamaput[i] = mamaput[j];
			j++;
		}
	}

	return (new_mamaput);
}

/**
 * indur_var - call func
 *
 * @mamaput: input str
 * @rndsh: ds
 * Return: new str.
 */
char *indur_var(char *mamaput, datacliff *rndsh)
{
	qr_var *hepfo, *inama;
	char *guys, *new_mamaput;
	int blen, nlen;

	guys = conv_num(rndsh->guys);
	hepfo = NULL;

	blen = suzum_vars(&hepfo, mamaput, guys, rndsh);

	if (hepfo == NULL)
	{
		free(guys);
		return (mamaput);
	}

	inama = hepfo;
	nlen = 0;

	while (inama != NULL)
	{
		nlen += (inama->blop_val - inama->blop_var);
		inama = inama->suivant;
	}

	nlen += blen;

	new_mamaput = malloc(sizeof(char) * (nlen + 1));
	new_mamaput[nlen] = '\0';

	new_mamaput = hindur_input(&hepfo, mamaput, new_mamaput, nlen);

	free(mamaput);
	free(guys);
	ladder_lift_up(&hepfo);

	return (new_mamaput);
}
