#include "honore.h"

/**
 * main - the entry point for the shell
 * @argc: command line arguments counter
 * @argv: command line arguments
 *
 * Return: 0 on success, or the exit code of the just exited process
 */
int main(int argc, char *argv[])
{
	size_t len = 0;
	ssize_t n_read = 0;
	shell_t *hons = NULL;

	/* scout for singal interrupts (Ctrl + C) */
	signal(SIGINT, sigint_handler);

	hons = init_shell();
	hons->prog_name = argv[0];
	build_path(&hons->path_list);

	if (argc >= 2)
	{
		handle_file_as_input(argv[1], hons);
	}

	while (RUNNING)
	{
		show_prompt();
		fflush(stdout);

		n_read = _getline(&hons->linne, &len, STDIN_FILENO);

		++hons->cmd_cnt; /* keep track of the number of inputs to the shell */

		/* check for empty prompt or if Ctrl+D was received */
		if (n_read == 0)
		{
			if (isatty(STDIN_FILENO))
				printf("exit\n");
			handle_exit(hons, multi_free); /* clean up and leave */
		}

		hons->terminate_code = pass_line(hons);
		safe_free(hons->linne);
	}

	return (hons->terminate_code);
}