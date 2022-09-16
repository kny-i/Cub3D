#include "cub3d.h"

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
