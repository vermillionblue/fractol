/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:36:07 by danisanc          #+#    #+#             */
/*   Updated: 2021/12/05 13:59:47 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "libft.h"

//int	ft_isalpha(int c)
//{
//	if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' )
//		return (1);
//	else
//		return (0);
//}
//
//int	ft_isdigit(int c)
//{
//	if (c >= '0' && c <= '9')
//		return (1);
//	else
//		return (0);
//}

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	else
		return (0);
}

// int main(void)
// {
//     char c = 'l';
//     printf("%d", ft_isalnum(c));
//     printf("%d", isalnum(c));
// }