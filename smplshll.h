#ifndef SMPLSHLL_H
#define SMPLSHLL_H

/**
 * struct dataClif - It is struct that contains all necessary data on runtime
 * @arvtr: argument vector.
 * @cmluser: user command line.
 * @tkncl: cml tokens.
 * @stts: last stts of shll
 * @determine: Determine number of lines
 * @envaribale: envR variable
 * @id_pid: process ID of the shell
 */
typedef struct dataClif
{
	char **arvtr;
	char *cmluser;
	char **tkncl;
	int stts;
	int determine;
	char **envaribale;
	char *id_pid;
} dataclif;

/**
 * struct xclussive - single linked list
 * @differencw: ; OR AND
 * @followedNode: next node
 * Description: It is linked list that keeps separators
 */
typedef struct xclussive
{
	char differencw;
	struct xclussive *followedNode;
} honore;

/**
 * struct karikumutima - single linked list
 * @signally: command line
 * @followedNode: next node
 * Description: single linked list to store command lines
 */
typedef struct karikumutima
{
	char *signally;
	struct karikumutima *followedNode;
} signally_list;

/**
 * struct silva_list - single linked list
 * @ln_valia: length of the variable
 * @val_valia: value of the variable
 * @ln_vlauu: length of the value
 * @followedNode: next node
 * Description: single linked list to store variables
 */
typedef struct silva_list
{
	int ln_valia;
	char *val_valia;
	int ln_vlauu;
	struct silva_list *followedNode;
} silva;

/**
 * struct ball_builtin - Builtin struct for command arguments.
 * @nameless: The name of the command.
 * @f: data type pointer function.
 */
typedef struct ball_builtin
{
	char *nameless;
	int (*f)(dataclif *hnr);
} ball_b;

#endif /* SMPLSHLL_H */

