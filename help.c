/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:11:52 by danisanc          #+#    #+#             */
/*   Updated: 2022/04/27 20:41:45 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    print_help()
{
	ft_putendl_fd("Usage: ./fractol <name>", 1);
	ft_putendl_fd(NULL, 1);
	ft_putendl_fd("List of available fractals:", 1);
	ft_putendl_fd("Mandelbrot", 1);
	ft_putendl_fd("Julia <real part> <imaginary part>", 1);
	ft_putendl_fd("e.g: ./fractol Julia -0.4 0.6", 1);
	ft_putendl_fd("++++++++++++++", 1);
	ft_putendl_fd("From the 'Mandelbrot' option 'Julia' option can also "
	"be seen by pressing the right mouse button. The input coordinates are "
	"set by the mouse position", 1);
}


