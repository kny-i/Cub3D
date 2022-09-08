#include "cub3d.h"

t_ray **initialize_ray(t_cub3d *info)
{
	t_ray **ray;

	info->map->nb_ray = info->map->width;
	ray = ft_calloc(info->map->width, sizeof(t_ray *));
	size_t i = 0;
	while (i < info->map->nb_ray)
	{
		ray[i] = ft_calloc(1, sizeof(t_ray));
		ray[i]->collision = ft_calloc(1, sizeof(t_point));
		i++;
	}
	return (ray);
}

void initialize_object(t_cub3d *info)
{
	info->texture = initialize_texture(info->mlx, info->map->path);
	info->data = initialize_data(info->mlx, info->map);
	info->point = initialize_point(OFFSET, OFFSET, WALL_COLOR);
	info->player = initialize_player(info->map, DEFAULT_SPEED, ROTATE_SPEED);
	info->ray = initialize_ray(info);
}

void start_game(t_cub3d *info)
{
	//init game
	initialize_object(info);
	//game start!!!!!!
	game_start(info);
}
