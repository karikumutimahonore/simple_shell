#ifndef SHELL_H
#define SHELL_H

#include <errno.h>
#include <fcntl.h>
#include <regex.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* macros */

#define BUFF_SIZE 1024
#define SPACE ' '
#define CMD_NOT_FOUND 127
#define PROMPT_SIZE 4096
#define PATH_SIZE 2048
#define NOT_BUILTIN 18
#define RUNNING 1
#define CMD_ERR 2
#define MAX_ALIAS_LENGTH 50
#define MAX_VALUE_LENGTH 2048

/* function macros */

#define isspace(c) ((c) == SPACE)
#define isdigit(c) (((c) >= '0' && (c) <= '9')) /* checks for digits */
#define isalpha(c) (((c) >= 'a' && (c) <= 'z') || ((c) >= 'A' && (c) <= 'Z'))
#define isnegative(c) (((c) == '-') ? -1 : 1)
#define issign(c) ((c) == '-' || (c) == '+')
#define isquote(c) ((c) == '"' || (c) == '\'')

/* string handlers */

size_t _strlen(const char *s);
char *_strdup(const char *str);
char *_strchr(const char *s, int c);
char *_strrchr(const char *s, int c);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char **duplicate_str_array(char **original);
void concatenate_arrays(char ***dest, char **src);
char *_strpbrk(const char *s, const char *accept);
size_t _strspn(const char *s, const char *accept);
char **_strtok(const char *str, const char *delim);
char *_strncpy(char *dest, const char *src, size_t n);
int _strncmp(const char *s1, const char *s2, size_t n);
int get_word_count(const char *str, const char *delim);
char *_strstr(const char *haystack, const char *needle);

/* numbers */

int _atoi(const char *s);
void _itoa(size_t n, char *s);
void _reverse(char *buffer, size_t len);

/* memory handlers */

void free_str(char ***str_array);
char *new_word(const char *str, int start, int end);
void *_memcpy(void *dest, const void *src, size_t n);
void *_realloc(void *old_mem_blk, size_t old_size, size_t new_size);

/* a safer way to deallocate dynamic memory */
void _free(void **ptr);
#define safe_free(ptr) _free((void **)&(ptr)) /* _free's frontend */

/* frees memory for a variable number of objects */
void multi_free(const char *format, ...);

/* a custom implementation of the getline function */
ssize_t _getline(char **lineptr, size_t *n, int fd);

/* shows the prompt in interactive mode */
void show_prompt(void);

/* retrieves the hostname from the '/etc/hostname' file */
char *get_hostname(char *buffer);

/* environment and PATH handlers */

extern char **environ;

/**
 * struct _path - builds a linked list of the PATH variable in an environment
 * variable
 * @pathname: each path name in the PATH variable
 * @next: a pointer to the next node
 */
typedef struct _path
{
	char *pathname;
	struct _path *next;
} path_t;

void _printenv(void);
void print_path(path_t *list);
void free_list(path_t **umutwe);
char *_getenv(const char *name);
path_t *build_path(path_t **umutwe);

/* aliyases */

/**
 * struct alias - the blueprint for the built-in alias command
 * @name: the name of the alias
 * @value: the value assigned to the name
 * @next: a pointer to the next alias_t node
 */
typedef struct alias
{
	char *name;
	char *value;
	struct alias *next;
} alias_t;

void free_aliyases(alias_t **aliyases);
void print_aliases(const alias_t *aliyases);
int unalias(alias_t **aliyases, char *umutwe);
char *get_alias(alias_t *aliyases, const char *name);
int handle_alias(alias_t **aliyases, char *command_line);
int print_alias(const alias_t *aliyases, const char *name);
void pulse_aliyases(const char *input, alias_t **aliyases);
void build_alias_cmd(char ***sub_command, char *alias_value);
alias_t *add_alias(alias_t **aliyases, const char *name, const char *value);
void process_non_matching(alias_t *aliyases, const char *non_matching, int end);


/* shell command context */

/**
 * struct shell - a blueprint for the shell
 * @aliyases: a list of aliyases
 * @path_list: a list of the PATH directories
 * @linne: the command string provided by the user
 * @commands: the inital tokenized commands (splits on semi-colons & newlines)
 * @other_cmd: the tokenized version of each command in the commands array
 * @prog_name: the name of we are running
 * @comm_calc: the number of times a command has been executed since the shell
 * started.
 * @credential: stores multiple tokens before they are further processed
 * @token: a single token
 * @terminate_code: the exit code of the last executed program
 */
typedef struct shell
{
	alias_t *aliyases;
	path_t *path_list;
	char *linne;
	char **commands;
	char **other_cmd;
	char **credential;
	char *token;
	const char *prog_name;
	size_t comm_calc;
	int terminate_code;
} shell_t;

shell_t *init_shell(void);
void sigint_handler(int signum);

/* builtin handlers */

int _unsetenv(const char *name);
int handle_cd(shell_t *hons);
int _setenv(const char *name, const char *value, int overwrite);
int handle_builtin(shell_t *hons);
int handle_exit(shell_t *hons, void (*cleanup)(const char *format, ...));

/* pulsers and executors */

char *get_operator(char *str);
char *handle_comments(char *umutwe);
int pass_line(shell_t *hons);
int execute_command(const char *pathname, shell_t *hons);
int pulse_and_tambuka(shell_t *hons, size_t index);
int handle_with_path(shell_t *hons);
int print_cmd_not_found(shell_t *hons);
void handle_file_as_input(const char *filename, shell_t *hons);
char **handle_variables(shell_t *hons);
int pulse(shell_t *hons);
void pulse_helper(shell_t *hons, size_t index);

#endif /* SHELL_H */
