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

	ret = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	i = 0;
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		ret[i] = s1[i];
		i++;
	}
	return (ret);
}

int	usage(void)
{
	ft_putstr_fd("[USAGE]\n./cub3d *.cub\n", STDERR_FILENO);
	return (FAILURE);
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

double distance_to_btw_points(double x0, double y0, double x1, double y1)
{
	return (sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0)));
}
