#include "cub3d.h"

double normalize_angle(double angle)
{

}

void ray_casting(t_cub3d *info)
{
	size_t i = 0;
	info->player->distance_projection = (info->map->width / 2) / (tan(FOV / 2));
	while (i < info->map->nb_ray)
	{
		info->ray[i]->angle = info->player->rotate_speed + atan2(i - info->map->nb_ray / 2, info->player->distance_projection);
		info->ray[i]->angle = normalize_angle(info->ray[i]->angle);
		i++;
	}
}

void game_start(t_cub3d *info)
{
	ray_casting(info);
}