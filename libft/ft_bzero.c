/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:01:30 by danisanc          #+#    #+#             */
/*   Updated: 2021/12/06 13:36:11 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, int n)
{
	int	j;

		j = 0;
	while (j < n)
	{
		*(char *)(s + j) = 0;
		j++;
	}
}

// int main()
// {
//     char str[50] = "GeeksForGeeks is for programming geeks.";
//     printf("\nBefore: %s\n", str);
//     ft_bzero(str, 2);
//     printf("After :  %s", str);
//     return 0;
// }