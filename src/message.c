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
	if (info->mlx_ptr && info->texture_image[north]->image)
		mlx_destroy_image(info->mlx_ptr, info->texture_image[north]->image);
	if (info->mlx_ptr && info->texture_image.south.img_ptr)
		mlx_destroy_image(info->mlx_ptr, info->texture_image.south.img_ptr);
	if (info->mlx_ptr && info->texture_image.west.img_ptr)
		mlx_destroy_image(info->mlx_ptr, info->texture_image.west.img_ptr);
	if (info->mlx_ptr && info->texture_image.east.img_ptr)
		mlx_destroy_image(info->mlx_ptr, info->texture_image.east.img_ptr);
	if (info->mlx_ptr && info->win_img.img_ptr)
		mlx_destroy_image(info->mlx_ptr, info->win_img.img_ptr);
	if (info->mlx_ptr && info->win_ptr)
		mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	if (info->mlx_ptr)
	{
		mlx_destroy_display(info->mlx_ptr);
		mlx_loop_end(info->mlx_ptr);
	}
	free(info->mlx_ptr);
}
int	the_end(t_cub3d *info)
{
	terminate_mlx(info);
	ft_putendl_fd("have a nice day!", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}
