#include "cub3d.h"

bool is_wall_conflict(t_cub3d *info, t_point *point)
{
	if (point->x < 0.0 || \
	(double)info->map->nb_row * TILE_SIZE < point->x || \
	point->y < 0.0 || \
	(double)info->map->nb_col * TILE_SIZE < point->y || \
	info->player->should_move == false)
	return (true);
}