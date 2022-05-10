/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:09:03 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/10 23:16:19 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	arrows_complex(int key, t_data *data)
{
	if (key == 126)
	{	
		data->i_max = data->i_max - (data->zoom * 0.1);
		data->i_min = data->i_min - (data->zoom * 0.1);
	}
	if (key == 125)
	{
		data->i_max = data->i_max + (data->zoom * 0.1);
		data->i_min = data->i_min + (data->zoom * 0.1);
	}
	if (key == 123)
	{
		data->r_max = data->r_max - (data->zoom * 0.1);
		data->r_min = data->r_min - (data->zoom * 0.1);
	}
	if (key == 124)
	{
		data->r_max = data->r_max + (data->zoom * 0.1);
		data->r_min = data->r_min + (data->zoom * 0.1);
	}
}

void	calculate_p3(t_data *data)
{
	double	angle;

	angle = 60 * M_PI / 180;
	data->triangle.p3.x = data->triangle.p1.x + (data->triangle.p2.x \
	- data->triangle.p1.x) * cos(angle) + (data->triangle.p2.y \
	- data->triangle.p1.y) * sin(angle);
	data->triangle.p3.y = data->triangle.p1.y - (data->triangle.p2.x \
	- data->triangle.p1.x) * sin(angle) + (data->triangle.p2.y - \
	data->triangle.p1.y) * cos(angle);
}

void	arrows_koch(int key, t_data *data)
{
	if (key == 126 || key == 65362)
	{	
		data->triangle.p1.y -= 30;
		data->triangle.p2.y -= 30;
	}
	if (key == 125 || key == 65364)
	{
		data->triangle.p1.y += 30;
		data->triangle.p2.y += 30;
	}
	if (key == 123 || key == 65361)
	{
		data->triangle.p1.x -= 30;
		data->triangle.p2.x -= 30;
	}
	if (key == 124 || key == 65363)
	{
		data->triangle.p1.x += 30;
		data->triangle.p2.x += 30;
	}
	calculate_p3(data);
}

void	mode_hook(int keysym, t_data *data)
{
	if (keysym == 46 || keysym == 109)
		switch_value(&data->rgb);
	if (keysym == 3 || keysym == 102)
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

void	color_hook(int keysym, t_data *data)
{
	if (data->rgb)
	{
		if (keysym == 15 || keysym == 114)
			data->red = data->red + 1;
		if (keysym == 5 || keysym == 103)
			data->green = data->green + 1;
		if (keysym == 11 || keysym == 98)
			data->blue = data->blue + 1;
	}
	else
	{
		if (keysym == 4 || keysym == 104)
			data->hue = data->hue + 1;
		if (keysym == 1 || keysym == 115)
			data->sat = data->sat + 1;
		if (keysym == 9 || keysym == 118)
			data->val = data->val + 1;
	}
}
