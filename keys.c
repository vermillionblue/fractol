/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:55:42 by danisanc          #+#    #+#             */
/*   Updated: 2022/04/25 10:57:19 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int my_hook(int keysym, t_data *data)
{
	if (keysym == 53)
		mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
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
		
		step *= 0.25;
		//data->zoom = zoom_v / data->zoom;
	}
	else
	{
		step /=  0.25;
		//data->zoom = data->zoom / zoom_v;
	}
		data->r_max = lerp(data->mx, data->r_max, step);
    	data->r_min = lerp(data->mx, data->r_min, step);
    	data->i_max = lerp(data->my, data->i_max, step);
   		data->i_min = lerp(data->my, data->i_min, step);
    
}

#include <stdio.h>
//m = 
int mouse_hook(int keynum, int x, int y, void *data)
{
	printf("key %d" , keynum);
	if (keynum == 5)
		zoom(data, x, y, 1);
	if(keynum == 4)
		zoom(data, x, y,0);
	
	return (0);
}