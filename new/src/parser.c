#include "cub3d.h"

bool parse_direction(t_map *map, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
	{
		map->path[north] = xstrdup(skip_space_str(line + 3));
		return (SUCCESS);
	}
	if (ft_strncmp(line, "SO", 2) == 0)
	{
		map->path[south] = xstrdup(skip_space_str(line + 3));
		return (SUCCESS);
	}
	if (ft_strncmp(line, "WE", 2) == 0)
	{
		map->path[west] = xstrdup(skip_space_str(line + 3));
		return (SUCCESS);
	}
	if (ft_strncmp(line, "EA", 2) == 0)
	{
		map->path[east] = xstrdup(skip_space_str(line + 3));
		return (SUCCESS);
	}
	else
		return (FAILURE);
}

bool parse_map(t_map *map, char *line, size_t *map_col_index)
{
	if (is_all_specific_char(line, "NSEW 01") == false)
		return (FAILURE);
	else
	{
		allocate_map(map, line, map_col_index);
		return (SUCCESS);
	}
}

void parse_cub3d_file(t_map *map, char *line, size_t *map_col_index)
{
	if (parse_direction(map, line) == SUCCESS \
	|| parse_color(map, line) == SUCCESS
	|| parse_map(map, line, map_col_index) == SUCCESS)
		return;
	else
		return;
}

t_map *parser(char *file, t_map *map)
{
	int fd;
	char *line;

	if (is_valid_format_file(file) == false)
		error_message("INVALID FORMAT FILE!");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_message("OPEN FAILURE!");

	size_t nb_col = 0;

	get_nb_col(fd, map, &nb_col);
	close(fd);
	int fd2 = open(file, O_RDONLY);
	map = ft_calloc(1, sizeof(t_map));
	map->is_filled_start_position = false;
	map->grid = ft_calloc(map->nb_col + 1, sizeof(char *));
	size_t map_col_index = 0;
	while (true)
	{
		line = get_next_line(fd2);
		if (line == NULL)
			break ;
		parse_cub3d_file(map, line, &map_col_index);
		free(line);
	}
	map->grid[map_col_index] = NULL;
	free(line);

	set_player_info_loop(map);
	return (map);
}
