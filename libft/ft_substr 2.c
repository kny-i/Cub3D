/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondo <ykondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:58:09 by ykondo            #+#    #+#             */
/*   Updated: 2021/11/20 19:58:09 by ykondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	malloclen;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s) || len == 0 )
		return (ft_strdup(""));
	if (ft_strlen(s) >= start + len)
		malloclen = len;
	else
		malloclen = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(*s) * (malloclen + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
		if (i >= start && j < len)
			str[j++] = s[i];
	str[j] = '\0';
	return (str);
}

/*

int main(void)
{
	char *s = "tripouille";
	printf("%s\n",ft_substr(s, 0, 42000));
	system("leaks a.out");
	return (0);
}
*/
