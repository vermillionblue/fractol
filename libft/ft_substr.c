/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:08:18 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/13 21:26:30 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		k;
	size_t		x;
	char		*p;

	if (!s)
		return (0);
	k = 0;
	x = ft_strlen(s);
	if (len > x)
		len = x;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	if (start >= x)
	{
		p[0] = 0;
		return (p);
	}
	while (s[k + start] && len > k)
	{
		p[k] = s[k + start];
		k++;
	}
	p[k] = '\0';
	return (p);
}

// int main(void)
// {
//    	char * s = ft_substr("tripouille", 0, 42000);
//    printf("%s\n", s);
// 			free(s);
// }