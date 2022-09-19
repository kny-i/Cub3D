#include "cub3d.h"

double	normalize_angle(double ray_angle)
{
	double	normalized_angle;

	normalized_angle = remainder(ray_angle, M_PI * 2);
	if (normalized_angle < 0)
		normalized_angle += M_PI * 2;
	return (normalized_angle);
}

void	set_ray_direction(t_ray *ray, double ray_angle)
{
	ray->angle = normalize_angle(ray_angle);
	if ((ray_angle > 0 && ray->angle < M_PI) == true)
		ray->is_face_down = true;
	else
		ray->is_face_down = false;
	ray->is_face_up = !ray->is_face_down;
	if ((ray->angle < M_PI / 2 || 3 *M_PI / 2 < ray->angle) == true)
		ray->is_face_right = true;
	else
		ray->is_face_right = false;
	ray->is_face_left = !ray->is_face_right;
}

static double	pythagorean_theorem_for_delta(t_point *light_source, \
t_point *interception)
{
	double	dx;
	double	dy;

	dx = light_source->x - interception->x;
	dy = light_source->y - interception->y;
	return (sqrt(dx * dx + dy * dy));
}

void	get_closest_wall_hit(t_ray *ray, t_point *horizontal_wall_hit, \
													t_point *vertical_wall_hit)
{
	double	horiz_distance;
	double	vert_distance;

	horiz_distance = \
	pythagorean_theorem_for_delta(horizontal_wall_hit, ray->light_source);
	vert_distance = \
	pythagorean_theorem_for_delta(vertical_wall_hit, ray->light_source);
	if (horiz_distance < vert_distance)
	{
		ray->wall_hit = *horizontal_wall_hit;
		ray->distance = horiz_distance;
		ray->horizontal_or_vertical = HORIZONTAL;
	}
	else
	{
		ray->wall_hit = *vertical_wall_hit;
		ray->distance = vert_distance;
		ray->horizontal_or_vertical = VERTICAL;
	}
}

void	get_hit_wall_direction(t_ray *ray)
{
	if (ray->horizontal_or_vertical == VERTICAL)
	{
		if (ray->is_face_left)
			ray->wall_direction = west;
		else
			ray->wall_direction = east;
	}
	else
	{
		if (ray->is_face_up)
			ray->wall_direction = north;
		else
			ray->wall_direction = south;
	}
}
