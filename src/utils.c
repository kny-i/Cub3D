#include "cub3d.h"

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == ' ');
}

char	*xstrdup(const char *s1)
{
	char	*ret;
	size_t	len;
	size_t	i;

	ret = xcalloc(ft_strlen(s1) + 1, sizeof(char));
	i = 0;
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		ret[i] = s1[i];
		i++;
	}
	return (ret);
}

char	*skip_space_str(char *str)
{
	while (ft_isspace(*str) == true)
		str++;
	return (str);
}

size_t	strs_len(char **strs)
{
	size_t	len;

	len = 0;
	while (strs[len])
		len++;
	return (len);
}


