/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:30:28 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/04 13:00:19 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define pi 3.1416

int iter_koch(t_data *data);

int iter_fractal(t_data *data)
{
	t_complex	in;
	double		x;
    double		y;
    double		m;

	y = 0.0;
    x = 0.0;
    in.re = 0.0;
	in.im = 0.0;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	if (data->help)
		print_options(data);
	else
		mlx_string_put(data->mlx, data->mlx_win, (WIDTH*0.05), (HEIGHT*0.8) + 100, createRGB(0, 0 , 0, 0), "Press O for options");
    while (y < HEIGHT)
	{
		x = 0.0;
		while (x < WIDTH)
		{
			in.re = (double)(data->r_min + x / WIDTH * (data->r_max - data->r_min));
			in.im =(double) (data->i_min + y / HEIGHT*((data->i_max - data->i_min)));	
			if (data->julia || (!ft_strncmp(data->title, "Julia", 6)))
				m = calculate_julia(in, data);
			else
				m = calculate_mb(in, data);
			
			if ((x == y) && data->help)
				my_put_pixel(&data->img, x, y, 0x00000000);

			if (m == MAX_ITERS)
				my_put_pixel(&data->img, x, y, 0x00000000);
			else
				color(m,  x,  y, data);
			if (x >= (WIDTH*0.04) && x <= (WIDTH*0.345) && y >= (HEIGHT*0.78) && y <= (HEIGHT*0.98) && data->help)
				my_put_pixel(&data->img, x, y, createRGB(255, 255, 255, 0));
		
			x++;
		}
		y++;
	}
	return (0);
}

void clear_screen(t_data *data)
{
	int y , x = 0;

	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{	
			my_put_pixel(&data->img, x, y, createRGB(0, 0, 0, 0));
			x++;
		}
		y++;
	}
}


void line(point p1, point p2, t_data *data)
{
	double	x;
	double	y;
	double	temp;
	double line_eq;

	y = 0;
	x = 0;
	if (p1.x > p2.x)
	{
		temp = p2.y;
		p2.y = p1.y;
		p1.y = temp;
		temp = p1.x;
		p1.x = p2.x;
		p2.x = temp;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{	
			line_eq = (y - p1.y) - ((p2.y - p1.y) / (p2.x - p1.x) * (x - p1.x));
			if (abs(line_eq) < 1 && x >= p1.x && x <= p2.x) //&& x > x1 && x < x2
				color(data->color_koch, x, y, data);
			x++;
		}
		y++;
	}
}
	

void koch(point p1, point p2, int i, t_data *data)
{
	double	angle;
	point	p;
	point	p3;
	point	p4;

	angle = 60*pi/180;
	p3.x = (2*p1.x+p2.x)/3;
	p3.y = (2*p1.y+p2.y)/3;
	p4.x = (p1.x+2*p2.x)/3;
	p4.y = (p1.y+2*p2.y)/3;
	p.x = p3.x + (p4.x-p3.x)*cos(angle)+(p4.y-p3.y)*sin(angle);
	p.y = p3.y - (p4.x-p3.x)*sin(angle)+(p4.y-p3.y)*cos(angle);
	if(i > 0)
	{
		koch(p1, p3, i-1, data);
		koch(p3, p, i-1, data);
		koch(p, p4, i-1, data);
		koch(p4, p2, i-1, data);
	}
	else
	{
		line(p1, p3, data); //first edge
 		line(p3, p, data); //left edge
  		line(p, p4, data); //right edge
		line(p4, p2, data); //last edge
	}
}

void set_triangle(point *p1, point *p2, point *p3)
{
	double angle;

	angle = 60*pi/180;
	p1->x = (WIDTH/4) + 150;
	p1->y = (HEIGHT*3/4 ) - 80;
	p2->x = (WIDTH*3/4) - 150;
	p2->y = (HEIGHT*3/4) - 80;
	p3->x = p1->x + (p2->x-p1->x)*cos(angle)+(p2->y-p1->y)*sin(angle);
	p3->y = p1->y - (p2->x-p1->x)*sin(angle)+(p2->y-p1->y)*cos(angle);
}

int iter_koch(t_data *data)
{
	float	i;
	point	p1;
	point	p2;
	point	p3;

	i = 0;
	clear_screen(data);
	set_triangle(&p1, &p2, &p3);

	double	x;
	double	y;
	double	temp;

	y = 0;
	x = 0;

	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{	
			line_eq = (y - p1.y) - ((p2.y - p1.y) / (p2.x - p1.x) * (x - p1.x));
			if (abs(line_eq) < 1 && x >= p1.x && x <= p2.x) //&& x > x1 && x < x2
				color(data->color_koch, x, y, data);
			x++;
		}
		y++;
	}

	// while (i < 10)
	// {
	// 	if (data->koch == -1)
	// 	{
	// 		data->color_koch = 26;
	// 		line(p1, p2,  data);
	// 		data->color_koch = 30;
	// 		line(p1, p3, data);
	// 		data->color_koch = 34;
	// 		line(p3, p2, data);
	// 	}
	// 	// else
	// 	// {
	// 	// 	data->color_koch = 26;
	// 	// 	p2.x += i;
	// 	// 	p2.y += i;
	// 	// 	p1.x += i;
	// 	// 	p1.y += i;
	// 	// 	p3.x += i;
	// 	// 	p3.y += i;
	// 	// 	koch( p2, p1 , data->koch , data); //base
	// 	// 	data->color_koch = 30;
	// 	// 	koch(p1, p3, data->koch , data);
	// 	// 	data->color_koch = 34;
	// 	// 	koch( p3, p2, data->koch, data);
	// 	// }
	// 	i = i + 1;
	// }
	return (0);
}

