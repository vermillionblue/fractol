/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:19:33 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/13 22:48:55 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	j;

	if (!s1)
		return (0);
	j = 0;
	p = malloc(ft_strlen((char *)s2) + ft_strlen((char *)s1) + 1);
	if (p == NULL)
		return (NULL);
	while (j < ft_strlen((char *)s1))
	{
		p[j] = s1[j];
		j++;
	}
	j = 0;
	while (j < ft_strlen((char *)s2))
	{
		p[ft_strlen((char *)s1) + j] = s2[j];
		j++;
	}
	p[ft_strlen((char *)s1) + ft_strlen((char *)s2)] = '\0';
	return (p);
}

// int main(void)
// {
// 		char	s1[] = "lorem ipsum";
// 		s1[0] = '\0';
// 		char	s2[] = "dolor sit amet";
// 		char *p = ft_strjoin(s1, s2);
// 		printf("%s\n", p);

// }