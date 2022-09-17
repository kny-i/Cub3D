#include "cub3d.h"

int	allocate_color(char *line)
{
	char	**strs;
	int		i;
	int		rgb[3];

	strs = ft_split(line, ',');
	if (strs_len(strs) != 3)
		error_message("INVALID RGB FORMAT!");
	str_free(&line);
	i = 0;
	if (is_nbrs(strs[0]) == false
		|| is_nbrs(strs[1]) == false
		|| is_nbrs(strs[2]) == false)
		error_message("COLOR INFORMATION IS INVALID FORMAT!");
	rgb[0] = ft_atoi(strs[0]) << 16;
	rgb[1] = ft_atoi(strs[1]) << 8;
	rgb[2] = ft_atoi(strs[2]);
	return (rgb[0] + rgb[1] + rgb[2]);
}

bool	parse_color(t_map *map, char *line)
{
	if (ft_strncmp(line, "F", 1) == 0)
	{
		map->floor_color = \
		allocate_color(xstrdup(skip_space_str(line + 2)));
		return (SUCCESS);
	}
	if (ft_strncmp(line, "C", 1) == 0)
	{
		map->ceiling_color = \
		allocate_color(xstrdup(skip_space_str(line + 2)));
		return (SUCCESS);
	}
	else
		return (FAILURE);
}

void	allocate_map(t_map *map, char *line, int *map_col_index)
{
	printf("%d\n", *map_col_index);
	map->grid[*map_col_index] = xstrdup(line);
	printf("hoge\n");
	(*map_col_index)++;
	printf("B");
}

void	get_nb_col(int fd, int *nb_col)
{
	char	*line;

	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (is_all_strs_space(line) == true)
			continue ;
		if (is_one_at_first(line) == false)
			continue ;
		if (is_all_specific_char(line, "NSEW 01\0") == true)
			(*nb_col)++;
	}
}
