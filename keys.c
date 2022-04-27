/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:55:42 by danisanc          #+#    #+#             */
/*   Updated: 2022/04/27 13:38:55 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int my_hook(int keysym, t_data *data)
{
	printf("%d\n", keysym);
	if (keysym == 53 | keysym == 65307)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	if (!data->rgb)
	{
		if (keysym == 6 || keysym == 104)
			data->hue = data->hue + 1;
		if (keysym == 1 | keysym == 115)
			data->sat = data->sat + 1;
		if (keysym == 9 | keysym == 118)
			data->val = data->val + 1;
	}
	if (data->rgb)
	{
		if (keysym == 114 || keysym == 114)
			data->red = data->red + 1;
		if (keysym == 103 | keysym == 103)
			data->green = data->green + 1;
		if (keysym == 98 | keysym == 98)
			data->blue = data->blue + 1;
	}
	if (keysym == 108 | keysym == 108) //l
	{
		if (data->swirl_mode)
			data->swirl_mode = 0;
		else
			data->swirl_mode = 1;
	}
	if (keysym == 109 | keysym == 109) //m
	{
		if (data->rgb)
			data->rgb = 0;
		else
			data->rgb = 1;
	}
	if (keysym == 102 | keysym == 102) //fav
	{
		if (data->favorite)
		{
			data->favorite = 0;
			data->swirl_mode = 0;
		}	
		else
		{
			data->swirl_mode = 1;
			data->favorite = 1;
		}	
	}
	iter_mandelbrot(data);
	return (0);
}

double lerp(double start, double end, double step)
{
	return (start + (end - start) * step);
}

void scr2obj(t_data *data)
{
	data->mx = (double)(data->r_min + (double)data->mx / (double)WIDTH * (data->r_max - data->r_min));
	data->my =(double) (data->i_min + (double)data->my / ((double)HEIGHT)*((data->i_max - data->i_min)));
}

void    zoom(t_data *data, int x, int y, int direction)
{
	double	zoom_v, step;
	step = 1.02;
	zoom_v = 1.02;
	data->mx = x;
	data->my = y;
	scr2obj(data);
	if (direction)
	{
		
		step *= 0.1;
		//data->zoom = zoom_v / data->zoom;
	}
	else
	{
		step /=  0.1;
		//data->zoom = data->zoom / zoom_v;
	}
		data->r_max = lerp(data->mx, data->r_max, step);
    	data->r_min = lerp(data->mx, data->r_min, step);
    	data->i_max = lerp(data->my, data->i_max, step);
   		data->i_min = lerp(data->my, data->i_min, step);
		iter_mandelbrot(data);
}

int mouse_hook(int keynum, int x, int y, void *data)
{
	if (keynum == 5)
		zoom(data, x, y, 1);
	else if(keynum == 4)
		zoom(data, x, y, 0);
	return (0);
}