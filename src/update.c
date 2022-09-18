#include "cub3d.h"

void	move_player(t_cub3d *info)
{
	t_point	*next_point;
	double	move_angle;

	next_point = xcalloc(1, sizeof(t_point));
	move_angle = \
	normalize_angle(info->player->angle + info->player->walk_direction);
	next_point->x = info->player->position->x + cos(move_angle) * MOVE_STEP;
	next_point->y = info->player->position->y + sin(move_angle) * MOVE_STEP;
	if (is_wall_conflict(info, next_point) == true)
	{
		info->player->should_move = false;
		return ;
	}
	info->player->position = next_point;
}

void	updating_info(t_cub3d *info)
{
	if (info->player->should_move == true)
		move_player(info);
	cast_all_rays(info, info->ray);
}

int	updating(t_cub3d *info)
{
	updating_info(info);
	rendering(info);
	return (42);
}
