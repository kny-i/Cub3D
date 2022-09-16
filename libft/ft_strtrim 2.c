/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondo <ykondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:58:09 by ykondo            #+#    #+#             */
/*   Updated: 2021/11/20 19:58:09 by ykondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	n;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (*s1 == '\0')
	{
		dst = ft_strdup((char *)s1);
		return (dst);
	}
	n = ft_strlen(s1);
	while (n && ft_strchr(set, s1[n]))
		n--;
	dst = ft_substr((char *)s1, 0, n + 1);
	return (dst);
}
