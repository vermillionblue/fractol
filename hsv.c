/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:18:35 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/05 16:23:00 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	rgb_from_temp_(t_double_rgb *temp, double hsv_v, int i)
{
	if (i == 3)
	{
		temp->r = temp->p;
		temp->g = temp->q;
		temp->b = hsv_v;
	}
	else if (i == 4)
	{
		temp->r = temp->t;
		temp->g = temp->p;
		temp->b = hsv_v;
	}
	else
	{
		temp->r = hsv_v;
		temp->g = temp->p;
		temp->b = temp->q;
	}
}

void	rgb_from_temp(t_double_rgb *temp, double hsv_v, int i)
{
	if (i == 0)
	{
		temp->r = hsv_v;
		temp->g = temp->t;
		temp->b = temp->p;
	}
	else if (i == 1)
	{
		temp->r = temp->q;
		temp->g = hsv_v;
		temp->b = temp->p;
	}
	else if (i == 2)
	{
		temp->r = temp->p;
		temp->g = hsv_v;
		temp->b = temp->t;
	}
	else
		rgb_from_temp_(temp, hsv_v, i);
}

void	set_temp_values(t_double_rgb *temp, t_hsv hsv, int i)
{
	temp->f = hsv.h - i;
	temp->p = hsv.v * (1.0 - hsv.s);
	temp->q = hsv.v * (1.0 - (hsv.s * temp->f));
	temp->t = hsv.v * (1.0 - (hsv.s * (1.0 - temp->f)));
}

t_rgb	set_rgb(t_double_rgb temp)
{
	t_rgb	rgb;

	rgb.r = temp.r * 255;
	rgb.g = temp.g * 255;
	rgb.b = temp.b * 255;
	return (rgb);
}

t_rgb	hsv2rgb(t_hsv hsv)
{
	t_double_rgb	temp;

	if (hsv.s == 0)
	{
		temp.r = hsv.v;
		temp.g = hsv.v;
		temp.b = hsv.v;
	}
	else
	{
		if (hsv.h == 360)
			hsv.h = 0;
		else
			hsv.h = hsv.h / 60;
		set_temp_values(&temp, hsv, (int)trunc(hsv.h));
		rgb_from_temp(&temp, hsv.v, (int)trunc(hsv.h));
	}
	return (set_rgb(temp));
}
