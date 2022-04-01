/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:04:23 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/14 00:50:03 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memmove( void *dst, const void *src, size_t len)
{
	unsigned char	*p;
	unsigned char	*d;
	size_t			i;

	d = (unsigned char *)dst;
	p = (unsigned char *)src;
	if (!d && !p)
		return (NULL);
	if (d > p)
	{
		i = len - 1;
		while ((int)i >= 0)
		{
			d[i] = p[i];
			i--;
		}
	}
	else
	{
		i = -1;
		while (++i < len)
			d[i] = p[i];
	}
	return (dst);
}

// int main()
// {
// 	char src1[27] = "lorem ipsum dolor sit amet";
// 	char src2[27] = "lorem ipsum dolor sit amet";
// 	char *dest;
// 	char *dst2;
// 	dest = src1 + 1;
// 	dst2 = src2 + 1;
// 	//Use of memmove
// 	memmove(dest, "consectetur", 5);
// 	printf( "Result:%s\n", dest);
// 	//Use of ft_memmove
// 	ft_memmove(dst2, "consectetur", 5);
// 	printf( "Result:%s\n", dst2);
// 	return 0;
// }