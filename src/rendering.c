#include "cub3d.h"

void drawing_ceiling_and_floor(t_cub3d *info)
{
	size_t scroll_x = 0;
	size_t scroll_y = 0;
	while (scroll_x < NB_RAYS)
	{
		while (scroll_y < DEFAULT_HEIGHT / 2)
		{

			my_mlx_pixel_put(info, scroll_x, scroll_y, info->map->ceiling_color);
			scroll_y++;
		}
		while (scroll_y < DEFAULT_HEIGHT)
		{
			my_mlx_pixel_put(info, scroll_x, scroll_y, info->map->floor_color);
			scroll_y++;
		}
		scroll_y = 0;
		scroll_x++;
	}
}

int rendering(t_cub3d *info)
{
	drawing_ceiling_and_floor(info);
	mlx_put_image_to_window(info->mlx, info->window, \
								info->data->image, 0, 0);
}