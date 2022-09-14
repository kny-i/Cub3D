#include "cub3d.h"

void play_gaming(t_cub3d *info)
{
	mlx_expose_hook(info->window, rendering, info);
//	mlx_loop_hook(info->mlx_ptr, update_screen, info);
}