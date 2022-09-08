/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondo <ykondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 20:24:07 by ykondo            #+#    #+#             */
/*   Updated: 2021/10/31 20:24:07 by ykondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1) && (*s2) && (n > 0))
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/*


#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "ABC";
	printf("ABC: ABC   = %d\n", ft_strncmp(str, "", 2));
	printf("ABC: ABC   = %d\n", strncmp(str, "", 2));
	printf("ABC: AAA   = %d\n", ft_strncmp(str, "AA", 2));
	printf("ABC: AAA  = %d\n", strncmp(str, "AAA", 2));
	printf("ABC: AB    = %d\n", ft_strncmp(str, "AB", 2));
	printf("ABC: AB     = %d\n", strncmp(str, "AB", 2));
	return 0;
}
*/
