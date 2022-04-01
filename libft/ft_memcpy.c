/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:03:51 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/14 00:42:23 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*p;
	unsigned char		*d;

	if (!dst && !src)
		return (0);
	d = (unsigned char *) dst;
	p = (unsigned char *)src;
	while (n-- > 0)
	{
		*d = *p;
			p++;
			d++;
	}
	return (dst);
}

// int main () {
// 		void *mem =  malloc(sizeof(*mem) * 30);
// 		memset(mem, 'j', 30);
// 		void *mem1 =  malloc(sizeof(*mem1) * 30);
// 		memset(mem1, 'j', 30);
//   printf("Before memcpy dest = %s\n", (char *)mem);
//   memcpy(mem, "zy\0xw\0vu\0\0tsr", 11);
//   printf("After memcpy dest = %s\n", (char *)mem);
// 		printf("Before ft_memcpy dest = %s\n", (char *)mem1);
//   ft_memcpy(mem1, "zy\0xw\0vu\0\0tsr", 11);
//   printf("After ft_memcpy dest = %s\n", (char *)mem1);
// }