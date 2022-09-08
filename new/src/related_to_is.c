#include "cub3d.h"

bool is_specific_char(char c, char *str)
{
	size_t	i;
	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (true);
		i++;
	}
	return (false);
}

bool is_all_specific_char(char *line, char *specific_strs)
{
	size_t i = 0;
	while(line[i] != '\0' && line[i] != '\n')
	{
		if (is_specific_char(line[i], specific_strs) == false)
		{
			error_message("INVALID MAP: FOUND INVALID CHAR");
			return (false);
		}
		i++;
	}
	return (true);
}
bool is_one_at_first(char *line)
{
	size_t i = 0;
	while (ft_isspace(line[i]) == true)
		i++;
	if (line[i] == '1')
		return (true);
	else
		return (false);
}

void get_nb_col(int fd, t_map *map, size_t *nb_col)
{
	char *line;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (is_one_at_first(line) == false)
			continue;
		if (is_all_specific_char(line, "NSEW 01\0") == true)
			(*nb_col)++;
	}
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

