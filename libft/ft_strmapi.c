/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:34:04 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/13 21:25:09 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			n;
	char			*p;

	if (!s)
		return (0);
	i = 0;
	n = ft_strlen((char *) s);
	p = malloc(n + 1);
	if (p == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}

// char	mapi(unsigned int i, char c)
// {
// 	static int	indexArray[11] = {0};

// 	if (i > 10 || indexArray[i] == 1)
// 		write(1, "wrong index\n", 12);
// 	else
// 		indexArray[i] = 1;
// 	if (c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	else if (c >= 'A' && c <= 'Z')
// 		return (c + 32);
// 	else
// 		return (c);
// }

// int main(void)
// {
//    char *str;
//    char *p;

// 			str = (char *)malloc(sizeof(*str) * 12);
// 			strcpy(str, "LoReM iPsUm");
//    char add(unsigned int, char);
// 			p = ft_strmapi(str,&mapi);
//    printf("%s\n", p);
//    free(p);
//    return (0);
// }