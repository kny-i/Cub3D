#include "cub3d.h"
/*
 * map判定はvalidate_mapで別のタイミングでする予定
 */

void allocate_map(t_map *map, char *line, size_t row_index)
{
	size_t col_index = 0;
	map->grid = calloc()
}

void parser(char *file, t_map *map)
{
	int fd;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_message("OPEN FAILURE!!");

	size_t row = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		allocate_map(map, line, row);
		row++;
	}
}
