#include "cub3d.h"

void error_message(char *message)
{
	printf(RED"%s\n"STOP, message);
	usage();
	exit(EXIT_FAILURE);
}

int success_message(char *message)
{
	ft_putstr_fd(message, 1);
}
