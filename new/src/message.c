#include "cub3d.h"

void error_message(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

int success_message(char *message)
{
	ft_putstr_fd(message, 1);
	return (SUCCESS);
}
