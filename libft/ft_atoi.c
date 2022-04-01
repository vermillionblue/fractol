/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessa <alessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:01:11 by danisanc          #+#    #+#             */
/*   Updated: 2021/12/14 11:33:16 by alessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include <ctype.h>

static int	ft_pow(int base, int exp)
{
	char	temp;

	temp = base;
	if (exp == 0)
	{
		base = 1;
		return (base);
	}
	if (exp == 1)
		return (base);
	while (exp > 1)
	{
		base *= temp;
		exp--;
	}
	return (base);
}

static int	minusorplus(const char *str, int count)
{
	if (str[0] == '-')
		return (count * -1);
	else
		return (count);
}

static int	numlen(const char *str)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	while (ft_isdigit(str[i++]))
		k++;
	return (k);
}

static char	*correctindex(const char *str)
{
	if (str[0] == '\t' || str[0] == ' ' || str[0] == '\r'
		|| str[0] == '\v' || str[0] == '\n' || str[0] == '\f')
	{
		while (*str == '\t' || *str == ' ' || *str == '\r'
			|| *str == '\v' || *str == '\n' || *str == '\f')
		{
			str++;
		}
	}
	return ((char *)str);
}

int	ft_atoi(const char *str)
{
	int						n;
	int						i;
	int						x;
	long int				count;

	count = 0;
	str = correctindex(str);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	n = numlen((char *)str);
	while (str[i] != '\0')
	{
		x = str[i] - '0';
		if (x > 9 || x < 0)
			break ;
		count += x * ft_pow(10, n - 1);
		i++;
		n--;
	}
	return (minusorplus(str, count));
}

// int main(void)
// {
//     char num[] = "-2147483648";
//     printf("%d\n", ft_atoi(num));
//     printf("%d\n", atoi(num));
//     return(0);
// }