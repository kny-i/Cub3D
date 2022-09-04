#include "cub3d.h"

bool is_map_line(char *line)
{
	size_t i = 0;
	while (ft_isprint(line[i]) == false)
		i++;
	if (line[i] == '1')
		return (true);
	else
		return (false);
}

bool is_valid_map(int fd, t_map *map, size_t *nb_col)
{
	char *line;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (is_map_line(line) == true)
			(*nb_col)++;
	}
	return (true);//ここもっとちゃんとやんないとだめ
}

bool parse_direction(t_map *map, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
	{
		map->path[north] = xstrdup(line + 3);
		return (true);
	}
	if (ft_strncmp(line, "SO", 2) == 0)
	{
		map->path[south] = xstrdup(line + 3);
		return (true);
	}
	if (ft_strncmp(line, "WE", 2) == 0)
	{
		map->path[west] = xstrdup(line + 3);
		return (true);
	}
	if (ft_strncmp(line, "EA", 2) == 0)
	{
		map->path[east] = xstrdup(line + 3);
		return (true);
	}
	else
		return (false);
}

int allocate_color(t_map *map, char *line)
{
	char **strs = ft_split(line, ',');
	size_t i = 0;
	int rgb[3];

	rgb[0] = ft_atoi(strs[0]) << 16;
	rgb[1] = ft_atoi(strs[1]) << 8;
	rgb[2] = ft_atoi(strs[2]);
	return (rgb[0] + rgb[1] + rgb[2]);
}

bool parse_color(t_map *map, char *line)
{
	if (ft_strncmp(line, "F", 1) == 0)
	{
		map->floor_color = allocate_color(map, line + 2);
		return (true);
	}
	if (ft_strncmp(line, "C", 1) == 0)
	{
		map->ceiling_color = allocate_color(map, line + 2);
		return (true);
	}
	else
		return (false);
}

bool is_map_line(char *line)
{
	size_t i = 0;
	while (ft_isprint(line[i]) == false)
		i++;
	if (line[i] == '1')
		return (true);
	else
		return (false);
}

void allocate_map(t_map *map, char *line, size_t *map_row_index)
{
	char **strs = malloc(sizeof(char *));
}

bool parse_map(t_map *map, char *line, size_t *map_row_index)
{
	if (is_map_line(line) == false)
		return (false);
	else
	{
		allocate_map(map, line, map_row_index);
		return (true);
	}
}

void parse_cub3d_file(t_map *map, char *line, size_t *map_row_index)
{
	if (parse_direction(map, line)
	|| parse_color(map, line)
	|| parse_map(map, line, map_row_index))
		return;
	else
		return;//error handling
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
	map = ft_calloc(1, sizeof(t_map));

	size_t map_row_index = 0;
	while (true)
	{
		line = get_next_line(fd2);
		if (line == NULL)
			break ;
		parse_cub3d_file(map, line, &map_row_index);
		free(line);
	}
	free(line);
	debug_parser(map);
}
