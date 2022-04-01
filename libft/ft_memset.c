/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:00:47 by danisanc          #+#    #+#             */
/*   Updated: 2021/12/06 13:14:12 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	chr;
	size_t			j;

	chr = c;
	p = b;
	j = 0;
	while (j < len)
	{
		*(p + j) = chr;
		j++;
	}
	return (b);
}

// int main()
// {
// 	void *mem;

// 	mem = malloc(sizeof(*mem));
//    // Fill 8 characters starting from str[13] with '.'
//    memset(mem, 'c', 15);
// 	void *mem2;

// 	mem2 = malloc(sizeof(*mem2));
//    // Fill 8 characters starting from str[13] with '.'
//    ft_memset(mem2, 'c', 15);
//    printf("After  ft_memset  %s\n", (char *)mem);
//    printf("After  ft_memset  %s", (char *)mem2);
//    return 0;
// }