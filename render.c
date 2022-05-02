/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:30:28 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/02 17:58:49 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int iter_fractal(t_data *data)
// {
// 	t_complex	in;
// 	int			x;
//     int			y;
//     double		m;

// 	y = 0.0;
//     x = 0.0;
//     in.re = 0.0;
// 	in.im = 0.0;
// 	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
//     while (y < HEIGHT)
// 	{
// 		x = 0.0;
// 		while (x < WIDTH)
// 		{
// 			in.re = (double)(data->r_min + (double)x / WIDTH * (data->r_max - data->r_min));
// 			in.im =(double) (data->i_min + (double)y / HEIGHT*((data->i_max - data->i_min)));
					
// 			if (data->julia || (!ft_strncmp(data->title, "Julia", 6)))
// 				m = calculate_julia(in, data);
// 			else
// 				m = calculate_mb(in, data);

// 			if (m == MAX_ITERS)
// 				my_put_pixel(&data->img, x, y, 0x00000000);
// 			else
// 				color(m,  x,  y, data);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (0);
// }


#include<stdlib.h>
#include<stdio.h>
#include<math.h>
 
#define pi M_PI


typedef struct s_point
{
	double	x;
	double	y;
}				point;

void draw_line(point p1, point p2, t_data *data, int x, int y)
{
	// if (y == p1.y && x >= p1.x && x<= p2.x) //base
	// 			my_put_pixel(&data->img, x, y, createRGB(255, 100, 200, 0));

	if ((y - p1.y )== ((p2.y -p1.y) * (x - p1.x) / ((p2.x - p1.x))  )) //
			my_put_pixel(&data->img, x, y, createRGB(255, 100, 200, 0));
	

}

//a = b*a/2
int iter_fractal(t_data *data)
{
	int			x;
    int			y;
	point p1, p2, p3;

	
	p1.x = (WIDTH/4);
	p1.y = (HEIGHT*3/4);

	p2.x = (WIDTH*3/4);
	p2.y = (HEIGHT*3/4);

	p3.x = (WIDTH/2);
	p3.y = (HEIGHT/2);

	int times = 5;

 //vertices , base  (WIDHT/4 , HEIGHT/4)  | (WIDHT*3/4, HEIGHT/4)) , end  (WIDHT/2, HEIGHT*3/4)

	y = 0.0;
    x = 0.0;

	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
    while (y < HEIGHT)
	{
		x = 0.0;
		while (x < WIDTH)
		{	
			//draw_line(p1, p3, data, x, y);
			//y1 = p3  
			if ((y - p3.y == ((p2.y - p3.y) * (x - p3.x)) / ((p2.x - p3.x)) ))
				my_put_pixel(&data->img, x, y, createRGB(255, 100, 200, 0));
			x++;
		}
		y++;
	}
	return (0);
}

