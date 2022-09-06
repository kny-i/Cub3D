#include "cub3d.h"

bool is_screen_edge(t_map *map, double x, double y)
{
	if (x < 0 || x >= map->width ||
	y < 0 || y >= map->height)
		return (false);
	else
		return (true);
}

bool is_wall(t_map *map, int x, int y, char identification)
{
	int grid_x;
	int grid_y;

	if (is_screen_edge(map, x, y) == true)
		return (true);
	grid_x = floor(x / TILE_SIZE);
	grid_y = floor(y / TILE_SIZE);
	if (grid_x >= map->nb_col || grid_y >= map->nb_row)
		return (true);
	if (map->grid[grid_x][grid_y] == identification)
		return (true);
	return (false);
}
