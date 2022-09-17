#include "cub3d.h"

t_point	find_first_horizontal_interception(t_ray *ray)
{
	t_point	first_horizontal_interception;

	first_horizontal_interception.y = \
	floor(ray->light_source->y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_face_down == true)
		first_horizontal_interception.y += TILE_SIZE;
	first_horizontal_interception.x = \
	ray->light_source->x + \
	(first_horizontal_interception.y - ray->light_source->y) \
	/ tan(ray->angle);
	return (first_horizontal_interception);
}


t_point	find_first_vertical_interception(t_ray *ray)
{
	t_point	first_horizontal_interception;

	first_horizontal_interception.x = \
	floor(ray->light_source->x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_face_right == true)
		first_horizontal_interception.x += TILE_SIZE;
	first_horizontal_interception.y = \
	ray->light_source->y + \
	(first_horizontal_interception.x - ray->light_source->x) * tan(ray->angle);
	return (first_horizontal_interception);
}
