#include "cub3d.h"

bool is_map_line(char *line)
{
	size_t i = 0;
	while (ft_isspace(line[i]) == true)
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
	return (true);
}

bool is_valid_format_file(char *filename)
{
	while (*filename)
		filename++;
	if (ft_strncmp(filename - 4, ".cub", 4) == 0)
		return (true);
	return (false);
}

bool is_valid_args(int argc, char **argv)
{
	return (argc == 2);
}

int is_nbrs(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

