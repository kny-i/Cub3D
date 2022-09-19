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

int	xatoi_for_byte(const char *str)
{
	size_t		i;
	long long	num;

	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v' \
	|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (!(0 <= num && num <= 255))
	{
		error_message("RGB IS TOO LONG VALUE!");
		return (0);
	}
	else
		return ((int)num);
}
