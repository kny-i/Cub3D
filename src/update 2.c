#include "cub3d.h"

//void move_player(t_cub3d *info)
//{
//	t_point next;
//	double move_angle;
//
//	move_angle = normalize_angle(info->player->angle + info->player->walk_direction);
//	next.x = info->player->position.x + cos(move_angle) * MOVE_STEP;
//	next.y = info->player->position.y + sin(move_angle) * MOVE_STEP;
//	if (next.x < 0.0 || (double )info->map->nb_row < next.x
//		|| next.y < 0.0 || (double )info->map->nb_col < next.y)
//	{
//		info->player->position = next;
//	}
//	if (info->map->grid[(int)next.y][(int)next.x] == '1')
//	{
//		info->player->position = next;
//	}
//}
//
//void updating_info(t_cub3d *info)
//{
//	if (info->player->should_move == true)
//		move_player(info);
//	cast_all_rays(info, info->ray);
//}

int updating(t_cub3d *info)
{
	//updating_info(info);
	rendering(info);
	return (0);
}

