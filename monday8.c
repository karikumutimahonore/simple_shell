#include "main.h"

/**
 * get_feel_error2 - calls the errors.
 * @pigsh: data structure that contains arguments
 * @cat123: err value
 * Return: err
 */
int get_feel_error2(dataclif *pigsh, int cat123)
{
	char *floor;

	switch (cat123)
	{
	case -1:
		floor = generate_env_error(pigsh);
		break;
	case 126:
		floor = generate_path_126_error(pigsh);
		break;
	case 127:
		floor = get_not_found_error(pigsh);
		break;
	case 2:
		if (strcap_e("exit", pigsh->kwargs[0]) == 0)
			floor = get_exit_shell_error(pigsh);
		else if (strcap_e("cd", pigsh->kwargs[0]) == 0)
			floor = get_cd_error_message(pigsh);
		break;
	}

	if (floor)
	{
		write(STDERR_FILENO, floor, guru(floor));
		free(floor);
	}

	pigsh->stts = cat123;
	return (cat123);
}
