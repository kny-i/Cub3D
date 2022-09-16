#include "cub3d.h"

void	drawing_ceiling_and_floor(t_cub3d *info)
{
	int	scroll_x;
	int	scroll_y;

	scroll_x = 0;
	scroll_y = 0;
	while (scroll_x < NB_RAYS)
	{
		while (scroll_y < DEFAULT_HEIGHT)
		{
			if (scroll_y < DEFAULT_HEIGHT / 2)
				my_mlx_pixel_put \
				(info, scroll_x, scroll_y, info->map->ceiling_color);
			else
				my_mlx_pixel_put \
				(info, scroll_x, scroll_y, info->map->floor_color);
			scroll_y++;
		}
		scroll_y = 0;
		scroll_x++;
	}
}

t_strip	get_strip_info(t_cub3d *info, t_ray *ray)
{
	t_strip	strip;
	double	projected_distance;
	double	ray_to_wall_distance;

	projected_distance = (DEFAULT_WIDTH / 2) / tan(FOV / 2);
	ray_to_wall_distance = \
	ray->distance * cos(ray->angle - info->player->angle);
	strip.height = (TILE_SIZE / ray_to_wall_distance) * projected_distance;
	strip.top_pixel = (DEFAULT_HEIGHT / 2) - (strip.height / 2);
	if (strip.top_pixel < 0)
		strip.top_pixel = 0;
	strip.bottom_pixel = (DEFAULT_HEIGHT / 2) + (strip.height / 2);
	if (strip.bottom_pixel > DEFAULT_HEIGHT)
		strip.bottom_pixel = DEFAULT_HEIGHT;
	return (strip);
}

t_image	*choose_texture_image(t_cub3d *info, t_ray *ray)
{
	if (ray->wall_direction == north)
		return (info->texture_image[north]);
	if (ray->wall_direction == south)
		return (info->texture_image[south]);
	if (ray->wall_direction == west)
		return (info->texture_image[west]);
	if (ray->wall_direction == east)
		return (info->texture_image[east]);
	else
		return (NULL);
}
