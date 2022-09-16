#include "cub3d.h"

void moving_forward(t_cub3d *info)
{
	info->player->walk_direction = 0;
	info->player->should_move = true;
}

void moving_backward(t_cub3d *info)
{
	info->player->walk_direction = M_PI;
	info->player->should_move = true;
}

void moving_rightside(t_cub3d *info)
{
	info->player->walk_direction = M_PI / 2;
	info->player->should_move = true;
}

void moving_leftside(t_cub3d *info)
{
	info->player->walk_direction =  -M_PI / 2;
	info->player->should_move = true;
}
