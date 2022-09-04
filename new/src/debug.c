#include "cub3d.h"

void debug_direction_path(t_map *map)
{
	for (int i = 0; i < 4; i++)
		fprintf(stderr, "%s\n", map->path[i]);
}