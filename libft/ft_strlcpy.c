/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessa <alessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:17:59 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/12 03:59:31 by alessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char	*src, size_t dstsize)
{
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	i = ft_strlen((char *)src);
	if (dstsize == 0)
		return (i);
	while (src[k] != '\0' && dstsize > 1)
	{
		dst[k] = src[k];
		k++;
		dstsize--;
	}
	dst[k] = '\0';
	return (i);
}

// int main(void)
// {
// 	char src[] = "coucou";
// 	char dest[10]; memset(dest, 'A', 10);
//    printf("%u\n", ft_strlcpy(dest, src, -1));
//    printf("%s", dest);
//    return (0);
// }