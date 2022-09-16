#include "libft.h"

size_t	ft_putchar_len(int c)
{
	write(1, &c, 1);
	return (1);
}
