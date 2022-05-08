/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_koch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:18:18 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/09 00:55:27 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void    zoom_koch(t_data *data, int x, int y, int direction)
{
    t_point p3;
    t_point p2;
    t_point p1;

	data->mx = x;
	data->my = y;

    direction =0;
    
    double tf_img2mouse[4][4];
    double tf_mouse2img[4][4];
    double scale_factor = 1.1;

    printf("mouse here\n");

    tf_img2mouse[0][0] = 1;
    tf_img2mouse[0][1] = 0;
    tf_img2mouse[0][2] = 0;
    tf_img2mouse[0][3] = x * -1;
    
    tf_img2mouse[1][0] = 0;
    tf_img2mouse[1][1] = 1;
    tf_img2mouse[1][2] = 0;
    tf_img2mouse[1][3] = y * -1;
    
    tf_img2mouse[2][0] = 0;
    tf_img2mouse[2][1] = 0;
    tf_img2mouse[2][2] = 1;
    tf_img2mouse[2][3] = 0;
    
    tf_img2mouse[3][0] = 0;
    tf_img2mouse[3][1] = 0;
    tf_img2mouse[3][2] = 0;
    tf_img2mouse[3][3] = 1;

    
    
    
    tf_mouse2img[0][0] = 1;
    tf_mouse2img[0][1] = 0;
    tf_mouse2img[0][2] = 0;
    tf_mouse2img[0][3] = x;
    
    tf_mouse2img[1][0] = 0;
    tf_mouse2img[1][1] = 1;
    tf_mouse2img[1][2] = 0;
    tf_mouse2img[1][3] = y;
    
    tf_mouse2img[2][0] = 0;
    tf_mouse2img[2][1] = 0;
    tf_mouse2img[2][2] = 1;
    tf_mouse2img[2][3] = 0;
    
    tf_mouse2img[3][0] = 0;
    tf_mouse2img[3][1] = 0;
    tf_mouse2img[3][2] = 0;
    tf_mouse2img[3][3] = 1;
    p1 = transform_point(tf_img2mouse, data->triangle.p1);
    p2 = transform_point(tf_img2mouse, data->triangle.p2);
    p3 = transform_point(tf_img2mouse, data->triangle.p3);
    p1 = scale_point(p1, scale_factor);
    p2 = scale_point(p2, scale_factor);
    p3 = scale_point(p3, scale_factor);
    data->triangle.p1 = transform_point(tf_mouse2img, p1);
    data->triangle.p2 = transform_point(tf_mouse2img, p2);
    data->triangle.p3 = transform_point(tf_mouse2img, p3);
    iter_koch(data);
	// if (direction)
	// {
	// 	step = 1.25 / 1.03;
	// 	data->zoom += (data->zoom * 0.1);
	// }
	// else
	// {
	// 	step =  1.03 / 1.25;
	// 	data->zoom -= (data->zoom * 0.1);
	// }	

}
