/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:55:42 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/09 18:58:15 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	destroy_n_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}

void	switch_value(int *n)
{
	if (*n)
		*n = 0;
	else
		*n = 1;
}

int	my_hook(int keysym, t_data *data)
{
	color_hook(keysym, data);
	mode_hook(keysym, data);
	if (!ft_strncmp (data->title, "Koch", 5))
		arrows_koch(keysym, data);
	else
		arrows_complex(keysym, data);
	if (keysym == 31 || keysym == 111)
		switch_value(&data->help);
	if (keysym == 30 || keysym == 65451)
		data->koch = data->koch + 1;
	if (keysym == 44 || keysym == 65453)
	{
		if (data->koch >= 0)
			data->koch = data->koch - 1;
	}
	if (keysym == 53 || keysym == 65307)
		destroy_n_exit(data);
	if (keysym == 37 || keysym == 108)
		switch_value(&data->swirl_mode);
	return (0);
}

void	mandelbrot2julia(t_data *data, int x, int y)
{
	if (data->julia)
	{
		data->julia = 0;
		boundaries_mandelbrot (data);
	}
	else
	{
		data->julia = 1;
		data->const_im = (double)(data->i_min + y / \
		((double) HEIGHT) * ((data->i_max - data->i_min)));
		data->const_re = (double)(data->r_min + x / \
		(double) WIDTH * (data->r_max - data->r_min));
		boundaries_julia(data);
	}
}

int	mouse_hook(int keynum, int x, int y, void *data)
{
	t_data	*data_;

	data_ = (t_data *)data;
	if (keynum == 1 && ft_strncmp (data_->title, "Julia", 6))
		mandelbrot2julia (data, x, y);
	if (!ft_strncmp (data_->title, "Koch", 5))
	{
		if (keynum == 5 && data_->triangle.p3.y >= 23.0
			&& data_->triangle.p1.x >= 23.0)
			zoom_koch(data, x, y, 0);
		else if (keynum == 4)
			zoom_koch(data, x, y, 1);
	}
	else
	{
		if (keynum == 5)
			zoom(data, x, y, 0);
		else if (keynum == 4)
			zoom(data, x, y, 1);
	}
	return (0);
}
