#include "cub3d.h"

bool	s_wall_conflict(t_cub3d *info, t_point *point)
{
	if ((point->x < 0.0 || \
	(double)info->map->nb_row * TILE_SIZE < point->x || \
	point->y < 0.0 || \
	(double)info->map->nb_col * TILE_SIZE < point->y || \
	info->player->should_move) == false \
	|| info->map->grid \
	[(int)point->y / TILE_SIZE][(int)point->x / TILE_SIZE] == '1')
		return (true);
	else
		return (false);
}
