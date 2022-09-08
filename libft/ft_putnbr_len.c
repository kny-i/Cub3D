#include "libft.h"

size_t	ft_putnbr_len(long long int nb)
{
	size_t	i;

	i = 0;
	if (nb < 0)
	{
		i += write (1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		i += ft_putnbr_len(nb / 10);
		nb %= 10;
	}
	if (nb < 10 && nb >= 0)
		i += ft_putchar_len(nb + '0');
	return (i);
}
