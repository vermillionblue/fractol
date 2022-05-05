/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:11:52 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/05 18:57:44 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_help(void)
{
	ft_putendl_fd("Usage: ./fractol <name>", 1);
	ft_putendl_fd(NULL, 1);
	ft_putendl_fd("List of available fractals:", 1);
	ft_putendl_fd("Mandelbrot", 1);
	ft_putendl_fd("Julia <real part> <imaginary part>", 1);
	ft_putendl_fd("Koch", 1);
	ft_putendl_fd("e.g: ./fractol Julia -0.4 0.6", 1);
	ft_putendl_fd("++++++++++++++", 1);
	ft_putendl_fd("From the 'Mandelbrot' option 'Julia' option can also "
		"be seen by pressing the right mouse button. The input coordinates are "
		"set by the mouse position", 1);
}

void	hsv_options(t_data *data)
{
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH * 0.1), (HEIGHT * 0.8) \
	, create_rgb(0, 0, 0, 0), "Press M to change color mode");
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH * 0.05), (HEIGHT * 0.8) \
	+ 20, create_rgb(0, 0, 0, 0), "HSV color mode (default):");
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH * 0.05), (HEIGHT * 0.8) \
	+ 40, create_rgb(0, 0, 0, 0), "Press H to change hue");
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH * 0.05), (HEIGHT * 0.8) \
	+ 60, create_rgb(0, 0, 0, 0), "Press S to change saturation");
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH * 0.05), (HEIGHT * 0.8) \
	+ 80, create_rgb(0, 0, 0, 0), "Press V to change dark level");
}

void	print_options(t_data *data)
{
	hsv_options(data);
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH * 0.21), (HEIGHT * 0.8) \
	+ 20, create_rgb(0, 0, 0, 0), "RGB color mode:");
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH * 0.21), (HEIGHT * 0.8) \
	+ 40, create_rgb(0, 0, 0, 0), "Press R to change red values");
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH * 0.21), (HEIGHT * 0.8) \
	+ 60, create_rgb(0, 0, 0, 0), "Press G to change green values");
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH * 0.21), (HEIGHT * 0.8) \
	+ 80, create_rgb (0, 0, 0, 0), "Press B to change blue values");
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH * 0.1), (HEIGHT * 0.8) \
	+ 100, create_rgb (0, 0, 0, 0), "Press L to add lines");
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH * 0.1), (HEIGHT * 0.8) \
	+ 120, create_rgb(0, 0, 0, 0), "Press F to go to my favorite values");
}

void	help_koch(t_data *data)
{
	t_point	p1;
	t_point	p2;

	p1.x = (WIDTH * 0.05);
	p1.y = (HEIGHT * 0.9);
	p2.x = (WIDTH * 0.05 + 50);
	p2.y = (HEIGHT * 0.9);
	line(p1, p2, data);
	p1.x = (WIDTH * 0.05 + 25);
	p1.y = (HEIGHT * 0.9 - 25);
	p2.x = (WIDTH * 0.05 + 25);
	p2.y = (HEIGHT * 0.9 + 25);
	line(p1, p2, data);
	p1.x = (WIDTH * 0.05 + 100);
	p1.y = (HEIGHT * 0.9);
	p2.x = (WIDTH * 0.05 + 150);
	p2.y = (HEIGHT * 0.9);
	line(p1, p2, data);
}

void	options_prompt(t_data *data)
{
	if (data->help)
		print_options(data);
	else
		mlx_string_put(data->mlx, data->mlx_win, (WIDTH * 0.05), \
	(HEIGHT * 0.8) + 100, create_rgb(0, 0, 0, 0), "Press O for options");
}
