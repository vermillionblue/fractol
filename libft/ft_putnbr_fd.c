/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:19:41 by danisanc          #+#    #+#             */
/*   Updated: 2021/12/06 12:14:53 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		c;
	int			temp;
	int			temp2;
	long int	b;

	b = n;
	if (b < 0)
	{
		write(fd, "-", 1);
		b *= -1;
	}
	if (b <= 9)
	{
		c = '0' + b;
		write(fd, &c, 1);
	}
	else
	{
		temp = b / 10;
		temp2 = b % 10;
		c = '0' + temp2;
		ft_putnbr_fd(temp, fd);
		write(fd, &c, 1);
	}
}

// int main(void)
// {
//    int n = 45464561;
//    int fd = 1;

//    ft_putnbr_fd(n, fd);
//    return(0);
// }