/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessa <alessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:16:55 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/13 11:36:14 by alessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		k;
	char	*p;

	k = 0;
	p = malloc(ft_strlen((char *)s1) + 1);
	if (!p)
		return (NULL);
	while (s1[k])
	{
		p[k] = s1[k];
		k++;
	}
	p[k] = '\0';
	return (p);
}

//int main(void)
//{
//    const char *s1 = "A brave new world.";
//    char *s2 = ft_strdup(s1);
//    printf("%s", s2);
//    free(s2);
//}