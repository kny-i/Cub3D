#include "cub3d.h"

bool is_screen_edge(t_map *map, double x, double y)
{
	if (x < 0 || x >= map->nb_col * TILE_SIZE ||
	 y < 0 || y >= map->nb_row * TILE_SIZE)
		return (true);
	else
		return (false);
}

bool is_wall(t_map *map, int x, int y, char identification)
{
	int grid_x;
	int grid_y;

//	printf("___________");
//	printf("%d\n", x);
//	printf("%d\n", y);
	if (is_screen_edge(map, x, y) == true)
		return (true);
	/* ここで必ず処理が止まってしまっている */
	grid_x = floor(x / TILE_SIZE);
	grid_y = floor(y / TILE_SIZE);
	if (grid_x >= map->nb_col || grid_y >= map->nb_row)
		return (true);
	if (map->grid[grid_x][grid_y] == identification)
		return (true);
	return (false);
}
