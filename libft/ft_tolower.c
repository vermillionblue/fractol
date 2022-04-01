/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessa <alessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:04:40 by danisanc          #+#    #+#             */
/*   Updated: 2021/12/14 11:03:21 by alessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + 32;
		return (c);
	}
	else
		return (c);
}

// int main()
// {
//    char c = 'D';
//    printf("%c", tolower(c));
//    printf("%c", ft_tolower(c));
// 