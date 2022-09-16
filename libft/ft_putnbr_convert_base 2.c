#include "libft.h"

size_t	ft_putnbr_convert_base(unsigned long long nb, char *base)
{
	size_t	base_len;
	size_t	word_len;
	size_t	e;

	base_len = 0;
	word_len = 0;
	e = 1;
	while (base[base_len])
		base_len += 1;
	while (e <= nb / base_len)
		e *= base_len;
	while (e > 0)
	{
		word_len += write(1, &base[nb / e % base_len], 1);
		e /= base_len;
	}
	return (word_len);
}
