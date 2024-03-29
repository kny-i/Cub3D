#include "cub3d.h"

void	play_gaming(t_cub3d *info)
{
	mlx_hook(info->window, 2, 1, key_settings, info);
	mlx_hook(info->window, 3, 2, reset_key, info);
	mlx_hook(info->window, WINDOW_DESTROY, \
	1L << 1, &the_end, info);
	mlx_loop_hook(info->mlx, rendering, info);
	mlx_loop_hook(info->mlx, updating, info);
	mlx_loop(info->mlx);
}
