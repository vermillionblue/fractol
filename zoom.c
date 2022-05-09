/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:14:44 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/09 19:02:59 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	lerp(double start, double end, double step)
{
	return (start + (end - start) * step);
}

double	screen2real(double num, t_data *data)
{
	return ((data->r_min + num / WIDTH * (data->r_max - \
	data->r_min)));
}

double	screen2imaginary(double num, t_data *data)
{
	return ((data->i_min + num / HEIGHT * (data->i_max - \
	data->i_min)));
}

void	zoom(t_data *data, int x, int y, int direction)
{
	double	step;

	data->mx = screen2real(x, data);
	data->my = screen2imaginary(y, data);
	if (direction)
	{
		step = 1.1 / 1.0;
		data->zoom += (data->zoom * 0.1);
	}
	else
	{
		step = 1.0 / 1.1;
		data->zoom -= (data->zoom * 0.1);
	}
	data->r_max = lerp(data->mx, data->r_max, step);
	data->r_min = lerp(data->mx, data->r_min, step);
	data->i_max = lerp(data->my, data->i_max, step);
	data->i_min = lerp(data->my, data->i_min, step);
}
