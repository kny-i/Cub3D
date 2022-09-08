/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondo <ykondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 20:24:07 by ykondo            #+#    #+#             */
/*   Updated: 2021/10/31 20:24:07 by ykondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include        <stdio.h>
#include        <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;

	a = (unsigned char *)b;
	while (len-- > 0)
		a[len] = (unsigned char)c;
	return (b);
}

/*
#include        <stdio.h>
#include        <string.h>

int main(void)
{
	char str[] = "0123456789";

	ft_memset(str, '@', 2);

	printf("%s\n",str);

	memset(str, '@', 2);

	printf("%s\n",str);

	return 0;
}
*/
