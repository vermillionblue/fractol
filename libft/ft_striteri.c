/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:27:43 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/13 21:25:47 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

//void add(unsigned int n, char* c)
//{
//    char x;
//    x = *c;
//    *c = x + n;
//}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

//int main(void)
//{
//    char s[10] = "23456";
//
//    ft_striteri(s,add);
//    printf("%s", s);
//    return (0);
//}