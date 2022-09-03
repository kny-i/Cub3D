#include "cub3d.h"
/*
 * map判定はvalidate_mapで別のタイミングでする予定
 */
void parser(char *file, t_map *map)
{
	int fd;
	char *line;

	printf("[%s]", file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_message("OPEN FAILURE!!");

	size_t row = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
	}
}
