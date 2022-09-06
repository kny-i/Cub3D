#include "cub3d.h"

bool is_screen_edge(t_map *map, double x, double y)
{
	if (x < 0 || x >= map->width ||
	y < 0 || y >= map->height)
		return (false);
	else
		return (true);
}


