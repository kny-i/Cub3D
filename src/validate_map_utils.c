#include "cub3d.h"

char	**strs_dup(char **strs)
{
	char	**copy;
	int		i;
	int		num_rows;

	i = 0;
	num_rows = strs_len(strs);
	copy = ft_calloc(sizeof(char *), (num_rows + 1));
	while (strs[i] != NULL)
	{
		copy[i] = ft_strdup(strs[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i] != NULL)
	{
		str_free(&strs[i]);
		i += 1;
	}
	str_free(strs);
}
