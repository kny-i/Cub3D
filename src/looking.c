#include "cub3d.h"

void	looking_rightside(t_cub3d *info)
{
	info->player->angle += ROTATE_SPEED;
	info->player->angle = normalize_angle(info->player->angle);
}

void	looking_leftside(t_cub3d *info)
{
	info->player->angle -= ROTATE_SPEED;
	info->player->angle = normalize_angle(info->player->angle);
}
