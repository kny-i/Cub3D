#include "cub3d.h"

void	my_mlx_pixel_put(t_cub3d *info, int x, int y, int color)
{
	char	*dst;

	dst = info->window_data->address + \
	(y * info->window_data->size_line + x * (info->window_data->bpp / 8));
	*(unsigned int *)dst = color;
}
