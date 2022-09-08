/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondo <ykondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 20:24:07 by ykondo            #+#    #+#             */
/*   Updated: 2021/10/31 20:24:07 by ykondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int			neg;
	size_t		i;
	long long	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		   || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg *= -1;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * neg);
}
/*

#include <stdio.h>

main()
{
	printf("%d\n", atoi("--123"));
	printf("%d\n", ft_atoi("--123"));
	printf("%d\n", atoi("1234567890"));
	printf("%d\n", atoi("12345678901"));
	printf("%d\n", atoi("12.34"));
	printf("%d\n", atoi("abc"));
}
*/
/*int main(void)
{
	printf("%d\n", ft_atoi("++323"));
	printf("%d\n", atoi("++323"));
	return (0);
}*/
