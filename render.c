/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:30:28 by danisanc          #+#    #+#             */
/*   Updated: 2022/04/28 16:23:26 by danisanc         ###   ########.fr       */
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
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
    while (y < HEIGHT)
	{
		x = 0.0;
		while (x < WIDTH)
		{
			in.re = (double)(data->r_min + (double)x / WIDTH * (data->r_max - data->r_min));
			in.im =(double) (data->i_min + (double)y / HEIGHT*((data->i_max - data->i_min)));
					
			if (data->julia || (!ft_strncmp(data->title, "Julia", 6)))
				m = calculate_julia(in, data);
			else
				m = calculate_mb(in, data);

			if (m == MAX_ITERS)
				my_put_pixel(&data->img, x, y, 0x00000000);
			else
				color(m,  x,  y, data);
			x++;
		}
		y++;
	}
	return (0);
}
