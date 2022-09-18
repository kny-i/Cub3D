#include "cub3d.h"

double	vertical_x_step(t_ray *ray)
{
	double	x_step;

	x_step = TILE_SIZE;
	if (ray->is_face_left == true)
		x_step *= -1;
	return (x_step);
}

double	vertical_y_step(t_ray *ray)
{
	double	y_step;

	y_step = TILE_SIZE * tan(ray->angle);
	if (ray->is_face_up && y_step > 0)
		y_step *= -1;
	if (ray->is_face_down && y_step < 0)
		y_step *= -1;
	return (y_step);
}

double	horizontal_x_step(t_ray *ray)
{
	double	x_step;

	x_step = TILE_SIZE / tan(ray->angle);
	if (ray->is_face_left && x_step > 0)
		x_step *= -1;
	if (ray->is_face_right && x_step < 0)
		x_step *= -1;
	return (x_step);
}

double	horizontal_y_step(t_ray *ray)
{
	double	y_step;

	y_step = TILE_SIZE;
	if (ray->is_face_up == true)
		y_step *= -1;
	return (y_step);
}
