/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:14:46 by danisanc          #+#    #+#             */
/*   Updated: 2022/02/01 16:32:23 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

#include "libft.h"

size_t	ft_strlcat( char	*dst, const char	*src, size_t dstsize)
{
	size_t	i;
	size_t	k;
	size_t	j;

	j = 0;
	k = 0;
	i = 0;
	i = strlen((char *)src);
	j = strlen(dst);
	if (dstsize == 0)
		return (i);
	if (dstsize < j + 1)
		return (i + dstsize);
	while (src[k] != '\0' && (dstsize - j - 1) > 0)
	{
		dst[j + k] = src[k];
		k++;
		dstsize--;
	}
	dst[j + k] = '\0';
	return (i + j);
}

// int main(void)
// {
//    char src[11] = "Dani";
//    char dest[10] = "Hello";
// 	printf("%c\n", dest[10]);
//    printf("%lu\n", ft_strlcat(dest, "lorem ipsum", 15));
//    printf("%c\n", dest[10]);
//    return (0);
// }
