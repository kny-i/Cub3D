#include "libft.h"

size_t	ft_putaddress_len(unsigned long long c)
{
	size_t	len;

	len = 0;
	ft_putstr_len("0x");
	len += 2;
	if (!c)
	{
		ft_putchar_len('0');
		return (++len);
	}
	len += ft_putnbr_convert_base(c, "0123456789abcdef");
	return (len);
}
