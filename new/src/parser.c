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

int allocate_color(t_map *map, char *line)
{
	char **strs = ft_split(line, ',');
	if (strs_len(strs) != 3)
		error_message("INVALID RGB FORMAT!");
	free(line);
	size_t i = 0;
	int rgb[3];

	if (is_nbrs(strs[0]) == false
	|| is_nbrs(strs[1]) == false
	|| is_nbrs(strs[2]) == false)
		error_message("COLOR INFORMATION IS INVALID FORMAT!");
	rgb[0] = ft_atoi(strs[0]) << 16;
	rgb[1] = ft_atoi(strs[1]) << 8;
	rgb[2] = ft_atoi(strs[2]);
	return (rgb[0] + rgb[1] + rgb[2]);
}

bool parse_color(t_map *map, char *line)
{
	if (ft_strncmp(line, "F", 1) == 0)
	{
		map->floor_color = allocate_color(map, xstrdup(skip_space_str(line + 2)));
		return (SUCCESS);
	}
	if (ft_strncmp(line, "C", 1) == 0)
	{
		map->ceiling_color = allocate_color(map, xstrdup(skip_space_str(line + 2)));
		return (SUCCESS);
	}
	else
		return (FAILURE);
}

void allocate_map(t_map *map, char *line, size_t *map_col_index)
{
	map->grid[*map_col_index] = xstrdup(line);
	(*map_col_index)++;
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
	printf("__test__03\n");
	set_player_info_loop(map);
	return (map);
}
