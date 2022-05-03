/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:55:42 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/03 14:30:08 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void mode_hook(int keysym, t_data *data)
{
	if (keysym == 46 | keysym == 109) //m
	{
		if (data->rgb)
			data->rgb = 0;
		else
			data->rgb = 1;
	}
	if (keysym == 3 | keysym == 102) //fav
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
}

void color_hook(int keysym, t_data *data)
{
	
	if (data->rgb)
	{
		if (keysym == 15 || keysym == 114)
			data->red = data->red + 1;
		if (keysym == 5 | keysym == 103)
			data->green = data->green + 1;
		if (keysym == 11 | keysym == 98)
			data->blue = data->blue + 1;
	}
	else
	{
		if (keysym == 4 || keysym == 104)
			data->hue = data->hue + 1;
		if (keysym == 1 | keysym == 115)
			data->sat = data->sat + 1;
		if (keysym == 9 | keysym == 118)
			data->val = data->val + 1;
	}
}

int my_hook(int keysym, t_data *data)
{

	if (keysym == 111 | keysym == 111)
	{
		if (data->help)
			data->help = 0;
		else
			data->help = 1;
	} //options
	
	
	if (keysym == 65451 | keysym == 65451) 
		data->koch = data->koch + 1;
			
	if (keysym == 65453 | keysym == 65453)
	{
		if (data->koch >= 0)
			data->koch = data->koch - 1;
	} 
			
	if (keysym == 53 | keysym == 65307)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	color_hook(keysym, data);
	mode_hook(keysym, data);
	if (keysym == 37 | keysym == 108) //l
	{
		if (data->swirl_mode)
			data->swirl_mode = 0;
		else
			data->swirl_mode = 1;
	}
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
	
	zoom_v = 1.02;
	data->mx = x;
	data->my = y;
	scr2obj(data);
	if (direction)
	{
		
		step = 1.25 / 1.0 ;
	}
	else
	{
		step =  1.0 / 1.25;
	}
		data->r_max = lerp(data->mx, data->r_max, step);
    	data->r_min = lerp(data->mx, data->r_min, step);
    	data->i_max = lerp(data->my, data->i_max, step);
   		data->i_min = lerp(data->my, data->i_min, step);
}

void mandelbrot2julia(t_data *data, int x, int y)
{
	if (data->julia)
	{
		data->julia = 0;
		boundaries_mandelbrot(data);
	}
	else
	{
		data->julia = 1;
		data->const_im = (double) (data->i_min + y / ((double)HEIGHT)*((data->i_max - data->i_min)));
		data->const_re = (double)(data->r_min + x / (double)WIDTH * (data->r_max - data->r_min));
		boundaries_julia(data);
	}
}

int mouse_hook(int keynum, int x, int y, void *data)
{
	t_data *s;
	s = (t_data *)data;
	if (keynum == 1 && ft_strncmp(s->title, "Julia", 6)) //change to respective julia set 
		mandelbrot2julia(data, x, y);
	else if (keynum == 5)
		zoom(data, x, y, 0);
	else if(keynum == 4)
		zoom(data, x, y, 1);
	return (0);
}