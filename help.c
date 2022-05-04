/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:11:52 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/04 12:16:17 by danisanc         ###   ########.fr       */
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
	ft_putendl_fd("Koch", 1);
	ft_putendl_fd("e.g: ./fractol Julia -0.4 0.6", 1);
	ft_putendl_fd("++++++++++++++", 1);
	ft_putendl_fd("From the 'Mandelbrot' option 'Julia' option can also "
	"be seen by pressing the right mouse button. The input coordinates are "
	"set by the mouse position", 1);
}

void print_options(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH*0.1) , (HEIGHT*0.8) , createRGB(0, 0 , 0, 0), "Press M to change color mode");
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH*0.05) , (HEIGHT*0.8) + 20, createRGB(0, 0 , 0, 0), "HSV color mode (default):");
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH*0.05), (HEIGHT*0.8) + 40, createRGB(0, 0 , 0, 0), "Press H to change hue");
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH*0.05), (HEIGHT*0.8) + 60, createRGB(0, 0 , 0, 0), "Press S to change saturation");
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH*0.05), (HEIGHT*0.8) + 80, createRGB(0, 0 , 0, 0), "Press V to change dark level");
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH*0.2) , (HEIGHT*0.8) + 20, createRGB(0, 0 , 0, 0), "RGB color mode:");
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH*0.2) , (HEIGHT*0.8) + 40, createRGB(0, 0 , 0, 0), "Press R to change red values");
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH*0.2) , (HEIGHT*0.8) + 60, createRGB(0, 0 , 0, 0), "Press G to change green values");
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH*0.2) , (HEIGHT*0.8) + 80, createRGB(0, 0 , 0, 0), "Press B to change blue values");
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH*0.1), (HEIGHT*0.8) + 100, createRGB(0, 0 , 0, 0), "Press L to add lines");
	mlx_string_put(data->mlx, data->mlx_win, (WIDTH*0.1), (HEIGHT*0.8) + 120, createRGB(0, 0 , 0, 0), "Press F to go to my favorite values");
}


