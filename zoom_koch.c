/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_koch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:18:18 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/09 19:07:49 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_identity_matrix(double matrix[4][4])
{
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void	fill_transform(double tf_img2mouse[4][4], double tf_mouse2img[4][4], \
	t_data *data)
{
	fill_identity_matrix(tf_img2mouse);
	tf_img2mouse[0][3] = -data->mx;
	tf_img2mouse[1][3] = -data->my;
	fill_identity_matrix(tf_mouse2img);
	tf_mouse2img[0][3] = data->mx;
	tf_mouse2img[1][3] = data->my;
}

void	zoom_in_out(t_data *data, double *scale_factor, int direction)
{
	if (!direction)
	{
		*scale_factor = 1.25 / 1.03;
		data->zoom += (data->zoom * 0.1);
	}
	else
	{
		*scale_factor = 1.03 / 1.25;
		data->zoom -= (data->zoom * 0.1);
	}
}

void	zoom_koch(t_data *data, int x, int y, int direction)
{
	t_point	p2;
	t_point	p1;
	double	scale_factor;
	double	tf_img2mouse[4][4];
	double	tf_mouse2img[4][4];

	data->mx = x;
	data->my = y;
	fill_transform(tf_img2mouse, tf_mouse2img, data);
	p1 = transform_point(tf_img2mouse, data->triangle.p1);
	p2 = transform_point(tf_img2mouse, data->triangle.p2);
	zoom_in_out(data, &scale_factor, direction);
	data->triangle.p1 = transform_point(tf_mouse2img, \
	scale_point(p1, scale_factor));
	data->triangle.p2 = transform_point(tf_mouse2img, \
	scale_point(p2, scale_factor));
	calculate_p3(data);
}
