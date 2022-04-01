/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessa <alessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:09:58 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/12 03:25:25 by alessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, int n)
{
	const unsigned char	*st1;
	const unsigned char	*st2;
	int					i;

	st2 = s2;
	st1 = s1;
	i = 0;
	while (n > 0)
	{
		if (st1[i] != st2[i])
			return (st1[i] - st2[i]);
		else
		{
			i++;
			n--;
		}
	}
	return (0);
}

//int main () {
//   char str1[15] = "abCdef";
//   char str2[15] = "abcdef";
//   int ret;
//
//    ret = ft_memcmp(str1, str2, 3);
//    printf("%d", ret);
//   return(0);
//}