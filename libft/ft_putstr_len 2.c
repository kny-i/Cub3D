#include "libft.h"

size_t	ft_putstr_len(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		i = 6;
		ft_putstr_len("(null)");
		return (i);
	}
	while (str[i] != '\0')
	{
		ft_putchar_len(str[i]);
		i++;
	}
	return (i);
}
