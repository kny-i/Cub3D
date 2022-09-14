#include "cub3d.h"

void	my_mlx_pixel_put(t_cub3d *info, int x, int y, int color)
{
	char	*dst;

	dst = info->data->address + (y * info->data->size_line + x * (info->data->bpp / 8));
	*(unsigned int *)dst = color;
}