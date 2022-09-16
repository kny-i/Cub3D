#include "cub3d.h"

bool	is_all_strs_space(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
