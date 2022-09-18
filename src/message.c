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
	if (info->mlx != NULL && info->texture_image[north]->image != NULL)
		mlx_destroy_image(info->mlx, info->texture_image[north]->image);
	if (info->mlx != NULL && info->texture_image[south]->image != NULL)
		mlx_destroy_image(info->mlx, info->texture_image[south]->image);
	if (info->mlx != NULL&& info->texture_image[west]->image != NULL)
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

void free_texture(t_image **texture)
{
	size_t i;

	i = 0;
	while (texture[i] != NULL)
	{
		free(texture[i]->image);
		free(texture[i]->address);
		free(texture[i]);
		i++;
	}
	free(texture);
}

/* light source is form info->player->position so we dont have to free */
void free_rays(t_ray **rays)
{
	size_t i;

	i = 0;
	while (rays[i] != NULL)
	{
		free(rays[i]);
		i++;
	}
	free(rays);
}

void free_image(t_image *image)
{
	free(image);
}

void free_map(t_map *map)
{
	size_t i;

	i = 0;
	while (map->grid[i] != NULL)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	free(map);
}

void free_player(t_player *player)
{
	free(player->position);
	free(player);
}

/* already free contents of texture_image we dont have to free them right now */
void free_info(t_cub3d *info)
{
	free(info->mlx);
	free(info->texture_image);
	free_rays(info->ray);
	free_image(info->window_data);
	free_map(info->map);
	free_player(info->player);
	free(info);
}

int	the_end(t_cub3d *info)
{
	terminate_mlx(info);
	free_info(info);
	ft_putendl_fd("have a nice day!", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}
