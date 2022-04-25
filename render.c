/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:30:28 by danisanc          #+#    #+#             */
/*   Updated: 2022/04/25 10:52:34 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int iter_mandelbrot(t_data *data)
{
	t_complex	in;
	int			x;
    int			y;
    double		m;

	y = 0.0;
    x = 0.0;
    in.re = 0.0;
	in.im = 0.0;
    while (y < HEIGHT)
	{
		x = 0.0;
		while (x < WIDTH)
		{
			in.re = (double)(data->r_min + (double)x / (double)WIDTH * (data->r_max - data->r_min));
			in.im =(double) (data->i_min + (double)y / ((double)HEIGHT)*((data->i_max - data->i_min)));
            m = calculate_mb(in, data);
			if (m != MAX_ITERS)
            	color(m,  x,  y, data);
			else
				mlx_pixel_put(data->mlx, data->mlx_win, x, y, 0xFF000000);
			x++;
		}
		y++;
	}
	return (0);
}