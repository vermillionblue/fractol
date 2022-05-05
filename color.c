/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:28:04 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/05 16:19:14 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_rgb(int r, int g, int b, int a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

void	color(double m, int x, int y, t_data *data)
{
	t_hsv	hsv;
	t_rgb	rgb;
	int		color;

	hsv.h = (data->hue + 7) * m;
	hsv.s = 1 - 0.1 * (data->sat);
	hsv.v = 1 - 0.1 * (data->val);
	rgb = hsv2rgb(hsv);
	if (data->favorite)
		color = create_rgb(200, 20 + 15 * m, 20 + 15 * m, 10);
	else if (data->rgb)
		color = create_rgb(20 + data->red * m * 2, 20 \
		+ data->green * m * 2, 20 + data->blue * m * 2, 0);
	else
		color = create_rgb(rgb.r, rgb.g, rgb.b, 1);
	my_put_pixel(&data->img, x, y, color);
}
