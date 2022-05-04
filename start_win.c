/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:19:28 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/03 22:19:36 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_koch(t_data *data)
{
	data->color_koch = 0;
	data->koch = -1;
	data->i_max = 0;
}

void	boundaries_julia(t_data *data)
{
	data->r_max = 1.5 ;
    data->r_min = -1.5;
    data->i_max = 1.0;
    data->i_min = -1.0;
}

void default_data(t_data *data)
{
	data->swirl_mode = 0;
	data->hue = 1;
	data->sat = 1;
	data->val = 1;
	data->red = 1;
	data->green = 1;
	data->blue = 1;
	data->favorite = 0;
	data->julia = 0;
	data->zoom = 1;
	data->help = 0;
}

void    boundaries_mandelbrot(t_data *data)
{
	if (!ft_strncmp(data->title, "Julia", 6))
		boundaries_julia(data);
	if (!ft_strncmp(data->title, "Koch", 5))
		data_koch(data);
	else
	{
		data->r_max = 1.0 ;
		data->r_min = -2.0;
		data->i_max = 1.0;
		data->i_min = -1.0;
	}
	default_data(data);
}

void start_win(t_data data)
{
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, data.title);
	if (!data.mlx )
		exit(EXIT_FAILURE);
	data.img.img  = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);

	boundaries_mandelbrot(&data);
	if (!ft_strncmp(data.title, "Koch", 5))
		mlx_loop_hook(data.mlx, &iter_koch, &data);
	else
		mlx_loop_hook(data.mlx, &iter_fractal, &data);
	mlx_key_hook(data.mlx_win, &my_hook, &data);
	mlx_mouse_hook(data.mlx_win, &mouse_hook, &data);
    mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.mlx_win);
}
