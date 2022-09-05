#include "cub3d.h"

void initialize_object(t_cub3d *info)
{
	info->texture = initialize_texture(info->mlx, info->map->path);
	info->data = initialize_data(info->mlx, info->map);
	info->point = initialize_point(OFFSET, OFFSET, WALL_COLOR);
	info->player = initialize_player(info->map, DEFAULT_SPEED, ROTATE_SPEED);
}

void start_game(t_cub3d *info)
{
	//init game
	initialize_object(info);
	//game start!!!!!!
	game_start(info);
}

