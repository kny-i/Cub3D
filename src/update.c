#include "cub3d.h"

void move_player(t_cub3d *info)
{
	t_point *next_point;
	double move_angle;

	next_point = ft_calloc(1, sizeof(t_cub3d));
	move_angle = normalize_angle(info->player->angle + info->player->walk_direction);
	next_point->x = info->player->position->x + cos(move_angle) * MOVE_STEP;
	next_point->y = info->player->position->y + sin(move_angle) * MOVE_STEP;
	if (next_point->x < 0.0 || (double )info->map->nb_row < next_point->x
		|| next_point->y < 0.0 || (double )info->map->nb_col < next_point->y)
		info->player->position = next_point;
	if (info->map->grid[(int)next_point->y][(int)next_point->x] == '1')
		info->player->position = next_point;
}

void updating_info(t_cub3d *info)
{
	if (info->player->should_move == true)
		move_player(info);
	cast_all_rays(info, info->ray);
}

int updating(t_cub3d *info)
{
	updating_info(info);
	rendering(info);
	return (0);
}
