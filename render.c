/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:30:28 by danisanc          #+#    #+#             */
/*   Updated: 2022/04/27 22:29:27 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int iter_fractal(t_data *data)
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
					
			if (data->julia || (!ft_strncmp(data->title, "Julia", 6)))
				m = calculate_julia(in, data);
			else
				m = calculate_mb(in, data);
			if (m != MAX_ITERS)
            	color(m,  x,  y, data);
			else
				my_put_pixel(&data->img, x, y, 0xFF000000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	return (0);
}
