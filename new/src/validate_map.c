#include "cub3d.h"

void set_player_info(t_map *map, size_t x, size_t y)
{

	;
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
					set_player_info(map, x, y);
			x++;
		}
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