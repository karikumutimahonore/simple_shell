#include "honore.h"

/**
 * execute_command - executes the command given
 * @pathname: the absolute path to the binary file to execute
 * @hons: the shell's context
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(const char *pathname, shell_t *hons)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0)
	{
		if (execve(pathname, hons->other_cmd, environ) == -1)
		{
			if (errno == EACCES)
			{
				fprintf(stderr, "%s: %lu: %s\n", hons->prog_name,
						++hons->comm_calc, strerror(errno));
				return (126);
			}
			perror("execve");
			return (-1);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("wait");
			return (-1);
		}
		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
	}

	return (0);
}
