#include "cub3d.h"

bool	parst_direction(t_map *map, char *line)
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

bool	parse_map(t_map *map, char *line, int *map_col_index)
{
	if (is_all_specific_char(line, "NSEW 01") == false)
		return (FAILURE);
	else
	{
		allocate_map(map, line, map_col_index);
		return (SUCCESS);
	}
}

void	parse_cub3d_file(t_map *map, char *line, int *map_col_index)
{
	if (parst_direction(map, line) == SUCCESS \
	|| parse_color(map, line) == SUCCESS \
	|| parse_map(map, line, map_col_index) == SUCCESS)
		return ;
	else
		return ;
}

void	parse_setup(t_cub3d *info, char *file)
{
	size_t	nb_col;
	int		fd;

	if (is_valid_format_file(file) == false)
		error_message("INVALID FORMAT FILE!");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_message("OPEN FAILURE!");
	nb_col = 0;
	get_nb_col(fd, &nb_col);
	close(fd);
	info->map = xcalloc(1, sizeof(t_map));
	info->map->is_filled_start_position = false;
	info->map->grid = xcalloc(info->map->nb_col + 1, sizeof(char *));
}

t_cub3d	*parser(char *file, t_cub3d *info)
{
	char	*line;
	int		fd;
	int		map_col_index;

	parse_setup(info, file);
	info->map->grid = xcalloc(info->map->nb_col + 1, sizeof(char *));
	map_col_index = 0;
	fd = open(file, O_RDONLY);
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (is_all_strs_space(line) == true)
			continue ;
		parse_cub3d_file(info->map, line, &map_col_index);
		str_free(&line);
	}
	info->map->grid[map_col_index] = NULL;
	info->map->nb_col = map_col_index;
	str_free(&line);
	set_player_info_loop(info);
	return (info);
}
