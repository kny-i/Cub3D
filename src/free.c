#include "cub3d.h"

void	free_texture(t_image **texture)
{
	size_t	i;

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
void	free_rays(t_ray **rays)
{
	size_t	i;

	i = 0;
	while (rays[i] != NULL)
	{
		free(rays[i]);
		i++;
	}
	free(rays);
}

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->grid[i] != NULL)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	free(map);
}

void	free_player(t_player *player)
{
	free(player->position);
	free(player);
}

void	free_info(t_cub3d *info)
{
	free(info->mlx);
	free(info->texture_image);
	free_rays(info->ray);
	free(info->window_data);
	free_map(info->map);
	free_player(info->player);
	free(info);
}
