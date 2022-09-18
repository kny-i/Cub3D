#include "cub3d.h"

void	play_gaming(t_cub3d *info)
{
	mlx_hook(info->window, 2, 1, key_settings, info);
	mlx_hook(info->window, 3, 2, reset_key, info);
	mlx_hook \
	(info->mlx, WINDOW_DESTROY, STRUCTURE_NOTIFY_MASK, the_end, NULL);
	mlx_loop_hook(info->mlx, rendering, info);
	mlx_hook(data->mlx_win, 17, 1L << 1, the_end, data);
	mlx_loop_hook(info->mlx, updating, info);
}
