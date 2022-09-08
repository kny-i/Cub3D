#include "cub3d.h"

void set_player_info(t_map *map, size_t x, size_t y, char direction)
{
	if (map->is_filled_start_position == true)
		error_message("INVALID MAP: MULTIPLE PLAYER");
	map->start_position = ft_calloc(1, sizeof (t_point));
	map->start_position->x = map->start_position->x * TILE_SIZE + 1;
	map->start_position->y = map->start_position->y * TILE_SIZE + 1;
	if (direction == 'N')
		map->angle = north;
	if (direction == 'S')
		map->angle = south;
	if (direction == 'E')
		map->angle = east;
	if (direction == 'W')
		map->angle = west;
	map->grid[y][x] = '0';
	map->is_filled_start_position = true;
}

void set_player_info_loop(t_map *map)
{
	size_t y;
	size_t x;

	y = 0;
	x = 0;
	while (map->grid[y] != NULL)
	{
		while (map->grid[y][x] != '\0')
		{
			if (is_specific_char(map->grid[y][x], "NSEW") == true)
				set_player_info(map, x, y, map->grid[y][x]);
			x++;
		}
		x = 0;
		y++;
	}
}
void is_map_closed(t_map *map)
{
	;
}
void is_valid_map(t_map *map)
{
	is_map_closed(map);
}