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

void terminate_mlx(t_cub3d *info)
{
	if (info->mlx && info->texture_image[north]->image)
		mlx_destroy_image(info->mlx, info->texture_image[north]->image);
	if (info->mlx && info->texture_image[south]->image)
		mlx_destroy_image(info->mlx, info->texture_image[south]->image);
	if (info->mlx && info->texture_image[west]->image)
		mlx_destroy_image(info->mlx, info->texture_image[west]->image);
	if (info->mlx && info->texture_image[east]->image)
		mlx_destroy_image(info->mlx, info->texture_image[east]->image);
	if (info->mlx && info->window)
		mlx_destroy_image(info->mlx, info->window_data->image);
	if (info->mlx && info->window)
		mlx_destroy_window(info->mlx, info->window);
	if (info->mlx)
	{
		mlx_destroy_display(info->mlx);
		mlx_loop_end(info->mlx);
	}

}

void free_texture(t_image **texture)
{
	size_t i;

	i = 0;
	while (texture[i] != NULL)
	{
		xfree(texture[i]->image);
		xfree(texture[i]->address);
		xfree(texture[i]);
	}
}
void free_info(t_cub3d *info)
{
	xfree(info->mlx);
	xfree(info->window);
	free_texture(info->texture_image);
	free_rays(info->ray);
	free_image(info->window_data);
	free_map(info->map);
	free_player(info->player);
}
int	the_end(t_cub3d *info)
{
	terminate_mlx(info);
	free_info(info);
	ft_putendl_fd("have a nice day!", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}
