#include "cub3d.h"

t_point	find_horizontal_wall_hit(t_ray *ray, t_map *map, t_point interceptopn)
{
	double	x_step;
	double	y_step;
	t_point check;

	x_step = horizontal_x_step(ray);
	y_step = horizontal_y_step(ray);
	while (true)
	{
		check = interceptopn;
		if (ray->is_face_up)
			check.y -= 1;
		if (check.x < 0.0 || (double)map->nb_row * TILE_SIZE < check.x \
		|| check.y < 0.0 || (double)map->nb_col * TILE_SIZE < check.y)
			return (interceptopn);
		if (map-> \
		grid[(int)check.y / TILE_SIZE][(int)check.x / TILE_SIZE] == '1')
			return (interceptopn);
		else
		{
			interceptopn.x += x_step;
			interceptopn.y += y_step;
		}
	}
}

t_point	find_vertical_wall_hit(t_ray *ray, t_map *map, t_point interception)
{
	double	x_step;
	double	y_step;
	t_point check;

	x_step = vertical_x_step(ray);
	y_step = vertical_y_step(ray);
	while (true)
	{
		check = interception;
		if (ray->is_face_left == true)
			check.x -= 1;
		if (check.x < 0.0 || (double )map->nb_row * TILE_SIZE < check.x \
		|| check.y < 0.0 || (double )map->nb_col * TILE_SIZE < check.y)
			return (interception);
		if (map->grid[(int)check.y / TILE_SIZE][(int)check.x / TILE_SIZE] \
		== '1')
			return (interception);
		else
		{
			interception.x += x_step;
			interception.y += y_step;
		}
	}
}

t_point	get_horizontal_wall_hit(t_ray *ray, t_map *map)
{
	t_point	interception;
	t_point	wall_hit;

	interception = find_first_horizontal_interception(ray);
	wall_hit = find_horizontal_wall_hit(ray, map, interception);
	return (wall_hit);
}

t_point	get_vertical_wall_hit(t_ray *ray, t_map *map)
{
	t_point	interception;
	t_point	wall_hit;

	interception = find_first_vertical_interception(ray);
	wall_hit = find_vertical_wall_hit(ray, map, interception);
	return (wall_hit);
}

t_ray	*cast_ray(t_ray *ray, t_cub3d *info, double ray_angle)
{
	t_point	horizotal_wall_hit;
	t_point	vertical_wall_hit;

	set_ray_direction(ray, ray_angle);
	horizotal_wall_hit = get_horizontal_wall_hit(ray, info->map);
	vertical_wall_hit = get_vertical_wall_hit(ray, info->map);
	get_closest_wall_hit(ray, &horizotal_wall_hit, &vertical_wall_hit);
	get_hit_wall_direction(ray);
	return (ray);
}
