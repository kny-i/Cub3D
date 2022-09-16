#include "cub3d.h"

bool	is_specific_char(char c, char *str)
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

bool	is_all_specific_char(char *line, char *specific_strs)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
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

bool	is_one_at_first(char *line)
{
	size_t	i;

	i = 0;
	while (ft_isspace(line[i]) == true)
		i++;
	if (line[i] == '1')
		return (true);
	else
		return (false);
}
