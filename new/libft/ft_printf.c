#include "libft.h"

static void	check_ui(unsigned int ascii, char c, size_t *len)
{
	if (c == 'x')
		*len += ft_putnbr_convert_base(ascii, "0123456789abcdef");
	if (c == 'X')
		*len += ft_putnbr_convert_base(ascii, "0123456789ABCDEF");
	if (c == 'u')
		*len += ft_putnbr_len(ascii);
}

static void	check_int(int ascii, const char c, size_t *len)
{
	if (c == 'd' || c == 'i')
		*len += ft_putnbr_len(ascii);
	if (c == 'c')
		*len += ft_putchar_len(ascii);
}

static void	check_conversion(va_list *ap, const char c, size_t *len)
{
	if (c == 'd' || c == 'i' || c == 'c')
		check_int(va_arg(*ap, int), c, len);
	else if (c == 'x' || c == 'X' || c == 'u')
		check_ui(va_arg(*ap, unsigned int), c, len);
	else if (c == 's')
		*len += ft_putstr_len(va_arg(*ap, char *));
	else if (c == 'p')
		*len += ft_putaddress_len(va_arg(*ap, unsigned long long));
	else
		*len += ft_putchar_len(c);
}

static void	check_fmt(va_list *ap, const char *fmt, size_t *len)
{
	size_t	i;

	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
			check_conversion(ap, fmt[++i], len);
		else
			*len += ft_putchar_len(fmt[i]);
		i++;
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	size_t	len;

	if (fmt == NULL)
		return (-1);
	len = 0;
	va_start(ap, fmt);
	check_fmt(&ap, fmt, &len);
	va_end(ap);
	return ((int)len);
}
