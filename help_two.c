/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:56:56 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/09 18:57:09 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	options_box(double x, double y, t_data *data)
{
	if (x >= (WIDTH * 0.04) && x <= (WIDTH * 0.38)
		&& y >= (HEIGHT * 0.78) && y <= (HEIGHT * 0.98) && data->help)
		my_put_pixel(&data->img, x, y, create_rgb(255, 255, 255, 0));
}
