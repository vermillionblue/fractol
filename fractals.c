/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:25:54 by danisanc          #+#    #+#             */
/*   Updated: 2022/04/27 22:20:35 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int *)pixel = color;
}

double  calculate_mb(t_complex in, t_data *data)
{
    t_complex	z;
	int			i;

    z.re = 0.0;
    z.im = 0.0;
	i  = -1;
    while (magnitude(z) <= 2.0 && ++i < MAX_ITERS)
		z = add(mult(z), in);
    if (i == MAX_ITERS)
        return (i);
	if (data->swirl_mode)
		return (i + 1 - logl(log(log(magnitude(z)))));
	else
		return (i  + 1 - log(log((magnitude(z))))/log(2)); 
}



double  calculate_julia(t_complex in, t_data *data)
{
	t_complex	static_z;
	int			i;
	
	static_z.im = data->const_im;
	static_z.re = data->const_re;
 
	i  = -1;
    while (magnitude(in) <= 2.0 && ++i < MAX_ITERS)
		in = add(mult(in), static_z);
	if (i == MAX_ITERS)
        return (i);
    return (i  + 1 - log((magnitude(in)))/log(2)); 
}

double  calculate_extra(t_complex in, t_data *data)
{
    t_complex	z;
	int			i;

    z.re = 0.0;
    z.im = 0.0;
	i  = -1;
    while (magnitude(z) <= 2.0 && ++i < MAX_ITERS)
		z = add(mult(z), in);
    if (i == MAX_ITERS)
        return (i);
	if (data->swirl_mode)
	return (i + 1 - logl(log(log(magnitude(z)))));
	else
		return (i  + 1 - log(log((magnitude(z))))/log(2)); 
}