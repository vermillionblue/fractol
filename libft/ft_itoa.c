/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisancstudent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:07:56 by danisanc          #+#    #+#             */
/*   Updated: 2021/11/25 00:00:24 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
	}
	while (n >= 1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*nullterminate( char *p, int i)
{
	if (p[0] == '-')
		p[i + 1] = '\0';
	else
		p[i] = '\0';
	return (p);
}

static char	*itoa_iter(char *p, int n, int x)
{
	int	temp;
	int	i;
	int	k;

	k = ft_numlen(n);
	i = 0;
	while (k > 0)
	{
		temp = '0' + (n % 10);
		n = n / 10;
		if (x < 0)
		{
			p[k] = temp;
			p[0] = '-';
		}
		else
		{
			p[k - 1] = temp;
		}
		k--;
		i++;
	}
	return (nullterminate(p, i));
}

static char	*edgecase(void)
{
	char	*p;
	char	*x;
	int		i;

	i = 0;
	p = malloc(12);
	x = "-2147483648";
	while (i < 12)
	{
		p[i] = x[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		x;

	x = 1;
	if (n == (int)-2147483648)
		return (edgecase());
	if (n < 0)
	{
			p = malloc(ft_numlen(n) + 2);
			n *= -1;
			x = -1;
	}
	else if (n == 0)
	{
		p = (char *)malloc(2);
		*p = '0';
		*(p + 1) = '\0';
		return (p);
	}
	else
		p = (char *)malloc(ft_numlen(n) + 1);
	if (p == NULL)
		return (NULL);
	return (itoa_iter(p, n, x));
}

// int main(void)
// {
//     int n = -0;
//     char *p;

//     p = ft_itoa(n);
//     printf("number:%s\n", p);
//     return(0);
// }