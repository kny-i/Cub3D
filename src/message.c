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

static void	terminate_mlx(t_cub3d *info)
{
	if (info->mlx != NULL && info->texture_image[north]->image != NULL)
		mlx_destroy_image(info->mlx, info->texture_image[north]->image);
	if (info->mlx != NULL && info->texture_image[south]->image != NULL)
		mlx_destroy_image(info->mlx, info->texture_image[south]->image);
	if (info->mlx != NULL && info->texture_image[west]->image != NULL)
		mlx_destroy_image(info->mlx, info->texture_image[west]->image);
	if (info->mlx != NULL && info->texture_image[east]->image != NULL)
		mlx_destroy_image(info->mlx, info->texture_image[east]->image);
	if (info->mlx != NULL && info->window != NULL)
		mlx_destroy_image(info->mlx, info->window_data->image);
	if (info->mlx != NULL && info->window != NULL)
		mlx_destroy_window(info->mlx, info->window);
	if (info->mlx != NULL)
	{
		mlx_destroy_display(info->mlx);
		mlx_loop_end(info->mlx);
	}
}

int	the_end(t_cub3d *info)
{
	terminate_mlx(info);
	free_info(info);
	ft_putendl_fd("have a nice day!", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}
