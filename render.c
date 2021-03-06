/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:30:28 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/09 18:37:51 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	current_magnitude(t_data *data, t_complex in)
{
	if (data->julia || (!ft_strncmp(data->title, "Julia", 6)))
		return (calculate_julia(in, data));
	else
		return (calculate_mb(in, data));
}

void	black_or_other(double x, double y, t_data *data, t_complex in)
{
	if (current_magnitude(data, in) == MAX_ITERS)
		my_put_pixel(&data->img, x, y, 0x00000000);
	else
		color(current_magnitude(data, in), x, y, data);
}

int	iter_fractal(t_data *data)
{
	t_complex	in;
	double		x;
	double		y;

	y = -1.0;
	x = -1.0;
	in.re = 0.0;
	in.im = 0.0;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	options_prompt(data);
	while (y++ < HEIGHT)
	{
		x = 0.0;
		while (x++ < WIDTH)
		{
			in.re = screen2real(x, data);
			in.im = screen2imaginary(y, data);
			if ((x == y) && data->help)
				my_put_pixel(&data->img, x, y, 0x00000000);
			black_or_other(x, y, data, in);
			options_box(x, y, data);
		}
	}
	return (0);
}

void	repeat_shape(t_point *p1, t_point *p2, t_point *p3, int i)
{
	p2->x += i;
	p2->y += i;
	p1->x += i;
	p1->y += i;
	p3->x += i;
	p3->y += i;
}

int	iter_koch(t_data *data)
{
	double	i;
	t_point	p1;
	t_point	p2;
	t_point	p3;

	i = 0;
	clear_screen(data);
	set_triangle(&p1, &p2, &p3, data);
	help_koch(data);
	while (i < 5)
	{
		if (data->koch == -1)
			generator(p1, p2, p3, data);
		else
			start_edges(p1, p2, p3, data);
		if (data->koch <= 2)
			repeat_shape(&p1, &p2, &p3, i);
		i = i + 0.5;
	}
	return (0);
}
