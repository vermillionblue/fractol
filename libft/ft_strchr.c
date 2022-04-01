/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessa <alessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:30:20 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/12 03:46:50 by alessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	int			k;
	char		*p;

	p = (char *)s;
	k = 0;
	i = ft_strlen((char *)s) + 1;
	while (i > 0)
	{
		if (s[k] == (char)c)
			return ((p + k));
		i--;
		k++;
	}
	return (NULL);
}

// int main () {
// char s[] = "tripouille";
//   printf("%s:\n", ft_strchr(s, 't' + 256));
// 		printf("%s:\n", strchr(s, 't' + 256));
//   return(0);
// }