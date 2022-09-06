#include "cub3d.h"

/*
 * angleがマイナス値だった時には正の方向に一周回している
 */

double normalize_angle(double angle)
{
	angle = remainder(angle, 2 * PI);
	if (angle < 0)
		angle = (2 * PI) + angle;
	return (angle);
}


//int 	ray_faicing(double angle, int way, )

void horizontal_interception(t_cub3d *info, t_point *interception, double ray_angle, t_point *step)
{
	interception->y = floor(info->player->position->y / TILE_SIZE) * TILE_SIZE;

}

void vertical_interception(t_cub3d *info, t_point *interception, double ray_angle, t_point *step)
{
	;
}
void casting_ray(t_cub3d *info, double ray_angle, int flag, t_point *next)
{
	t_point step;
	double x_check;
	double y_check;

	if (flag == HORIZONTAL)
		;
}

void get_closest_wall_data(t_cub3d *info, t_ray *ray, double ray_angle)
{
	t_point horizontal_interception;
	t_point vertical_interception;

	casting_ray(info, ray_angle, HORIZONTAL, &horizontal_interception);
	casting_ray(info, ray_angle, VERTICAL, &vertical_interception);
}

void ray_casting(t_cub3d *info)
{
	size_t i = 0;
	info->player->player_to_plane_distance = (info->map->width / 2) / (tan(FOV / 2));
	while (i < info->map->nb_ray)
	{
		info->ray[i]->angle = info->player->rotate_speed + atan2(i - info->map->nb_ray / 2, info->player->player_to_plane_distance);
		info->ray[i]->angle = normalize_angle(info->ray[i]->angle);
		get_closest_wall_data(info, info->ray[i], info->ray[i]->angle);
		i++;
	}
}

void drawing_color(t_cub3d *info, double wall_height, size_t index)
{
	double choice[2];
	int x;
	int y;

	choice[0] = (info->map->height / 2) - (wall_height / 2);
}


/* skip this function understanding */
void drawing_3dmap(t_cub3d *info)
{
	double distance_to_plane;
	double wall_height;
	size_t i = 0;
	while (i < info->map->nb_ray)
	{
		distance_to_plane = info->ray[i]->ray_to_plane_distance * cos(info->ray[i]->angle - info->player->angle);
		wall_height = TILE_SIZE / distance_to_plane * info->player->player_to_plane_distance;
		drawing_color(info, wall_height, i);
	}
}

void game_start(t_cub3d *info)
{
//	ray_casting(info);
//	drawing_3dmap(info);
}