#include "cub3d.h"

bool is_valid_map(int fd, t_map *map, size_t *nb_col)
{
	char *line;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		(*nb_col)++;
	}
	return (true);//ここもっとちゃんとやんないとだめ
}

void allocate_map(t_map *map, char *line, size_t row)
{

}

void parser(char *file, t_map *map)
{
	int fd;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_message("OPEN FAILURE!!");

	size_t nb_col = 0;
	if (is_valid_map(fd, map, &nb_col) == false)
		error_message("INVALID MAP!!");
	close(fd);

	int fd2 = open(file, O_RDONLY);
	size_t row = 0;
	map = ft_calloc(1, sizeof(t_map));
	map->grid = ft_calloc(nb_col, sizeof(char *));
	while (true)
	{
		line = get_next_line(fd2);
		if (line == NULL)
			break ;
		printf("%s", line);
//		allocate_map(map, line, row);
		row++;
	}
}
