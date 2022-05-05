/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:09:03 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/05 16:35:35 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	arrow_keys(int key, t_data *data)
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

void	mode_hook(int keysym, t_data *data)
{
	if (keysym == 46 | keysym == 109)
		switch_value(&data->rgb);
	if (keysym == 3 | keysym == 102)
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
