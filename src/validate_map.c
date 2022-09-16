#include "cub3d.h"

void set_player_info(t_cub3d *info, size_t x, size_t y, char direction)
{
	if (info->map->is_filled_start_position == true)
		error_message("INVALID MAP: MULTIPLE PLAYER");
	info->player = ft_calloc(1, sizeof(t_player));
	info->player->position = ft_calloc(1, sizeof (t_point));

	/* TILEの中心にplayerの位置をおくため */
	/*
	 * 方角に関しては絶対的な位置として考えるため
	 * x/y座標との対応関係はない
	 * example north -> 3/2 PI
	 */
	info->player->position->x = x * TILE_SIZE + TILE_SIZE / 2;
	info->player->position->y = y * TILE_SIZE + TILE_SIZE / 2;
	if (direction == 'N')
		info->player->angle = 3 * M_PI / 2;
	if (direction == 'S')
		info->player->angle = 1 * M_PI / 2;
	if (direction == 'E')
		info->player->angle = 0 * M_PI / 2;
	if (direction == 'W')
		info->player->angle = 2 * M_PI / 2;
	info->map->grid[y][x] = '0';
	info->map->is_filled_start_position = true;
}

void set_player_info_loop(t_cub3d *info)
{
	size_t y;
	size_t x;
	size_t tmp;

	y = 0;
	while (info->map->grid[y] != NULL)
	{
		x = 0;
		tmp = 0;
		while (info->map->grid[y][x] != '\0')
		{
			if (is_specific_char(info->map->grid[y][x], "NSEW") == true)
				set_player_info(info, x, y, info->map->grid[y][x]);
			tmp++;
			if (tmp > info->map->nb_row)
				info->map->nb_row = tmp;
			x++;
		}
		x = 0;
		y++;
	}
	if (info->map->is_filled_start_position == false)
		error_message("PLAY DOESN'T EXIST!!");
}

static bool	is_this_prison(char **map, size_t x, size_t y)
{
	if (map[y][x] == ' ' || map[y][x] == '\0')
		return (false);
	if (map[y][x] == '1' || map[y][x] == 'A')
		return (true);
	map[y][x] = 'A';
	return (is_this_prison(map, x + 1, y)
			&& is_this_prison(map, x - 1, y)
			&& is_this_prison(map, x, y + 1)
			&& is_this_prison(map, x, y - 1));
}

bool is_map_closed(t_map *map)
{

	size_t y;
	size_t x;
	char **tmp_map;

	y = 0;
	x = 0;
	tmp_map = strs_dup(map->grid);
	while (map->grid[y] != NULL)
	{
		while (map->grid[y][x] != '\0')
		{
			if (map->grid[y][x] == '0')
			{
				if (is_this_prison(tmp_map, x, y) == false)
					return (false);
			}
			x++;
		}
		x = 0;
		y++;
	}
	free_strs(tmp_map);
	return (true);
}

void is_valid_map(t_map *map)
{
	if (is_map_closed(map) == false)
		error_message("INVALID MAP: NOT CLOSED");
}
