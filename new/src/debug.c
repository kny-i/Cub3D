#include "cub3d.h"

void debug_direction_path(t_map *map)
{
	fprintf(stderr, RED"====[DEBUG DIRECTION PATH]====\n"STOP);
	for (size_t i = 0; i < 4; i++)
		fprintf(stderr, "%s\n", map->path[i]);
}

void debug_colors(t_map *map)
{
	fprintf(stderr, GREEN"====[DEBUG DIRECTION PATH]====\n"STOP);
	fprintf(stderr, "floor color:%d", map->floor_color);
	fprintf(stderr, "\nceilng color:%d\n", map->ceiling_color);
}

void debug_map(t_map *map)
{
	fprintf(stderr, YELLOW"====[DEBUG MAP]====\n"STOP);
	for (size_t i = 0; map->grid[i]; i++) {
		fprintf(stderr, "%s\n", map->grid[i]);
	}
}

void debug_parser(t_map *map)
{
	debug_direction_path(map);
	debug_colors(map);
	debug_map(map);
}
