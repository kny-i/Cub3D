#include "cub3d.h"

void	error_message(char *message)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	usage();
	exit(EXIT_FAILURE);
}

int	usage(void)
{
	ft_putstr_fd("[USAGE]\n./cub3d *.cub\n", STDERR_FILENO);
	return (FAILURE);
}

void	the_end(void)
{
	ft_putendl_fd("have a nice day!", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}
