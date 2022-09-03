/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondo <ykondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 20:24:07 by ykondo            #+#    #+#             */
/*   Updated: 2021/10/31 20:24:07 by ykondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		len_needle;

	len_needle = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len_needle <= len)
	{
		if (ft_strncmp(haystack, needle, len_needle) == 0 )
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
/*

#include<stdio.h>
int main(void) {
	char a[] = "";
	char b[] = "2isvdhsi";

	printf("%s\n", ft_strnstr(a, b, 5));
	printf("%s\n", strnstr(a, b, 5));

}
*/
