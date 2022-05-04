/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:30:28 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/04 14:31:41 by danisanc         ###   ########.fr       */
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
		mlx_string_put(data->mlx, data->mlx_win, (WIDTH*0.05), \
		(HEIGHT*0.8) + 100, createRGB(0, 0 , 0, 0), "Press O for options");
    while (y < HEIGHT)
	{
		x = 0.0;
		while (x < WIDTH)
		{
			in.re = (double)(data->r_min + x / WIDTH * (data->r_max - \
			data->r_min));
			in.im =(double) (data->i_min + y / HEIGHT*((data->i_max - \
			data->i_min)));	
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
			if (x >= (WIDTH*0.04) && x <= (WIDTH*0.345) && y >= (HEIGHT*0.78)
				&& y <= (HEIGHT*0.98) && data->help)
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
			if (p2.x == p1.x && y >= p1.y && y <= p2.y)
				color(data->color_koch, p2.x, y, data);
			if (abs(line_eq) < 0.1 && x >= p1.x && x <= p2.x) //&& x > x1 && x < x2
				color(data->color_koch, x, y, data);
			x++;
		}
		y++;
	}
}

typedef struct	s_edge
{
	point	p1;
	point	p2;
	point	p3;
	point	p4;
	point	p5;
	
}				t_edge;

void calculate_edges(t_edge *points)
{
	double	angle;


	angle = 60*pi/180;
	points->p3.x = (2*points->p1.x+points->p2.x)/3;
	points->p3.y = (2*points->p1.y+points->p2.y)/3;
	points->p5.x = (points->p1.x+2*points->p2.x)/3;
	points->p5.y = (points->p1.y+2*points->p2.y)/3;
	points->p4.x = points->p3.x + (points->p5.x-points->p3.x)*cos(angle) \
	+(points->p5.y-points->p3.y)*sin(angle);
	points->p4.y = points->p3.y - (points->p5.x-points->p3.x)*sin(angle) \
	 + (points->p5.y-points->p3.y)*cos(angle);
}

void koch(point p1, point p2, int i, t_data *data)
{
	t_edge points;

	points.p1 =  p1;
	points.p2 =  p2;
	calculate_edges(&points);
	if(i > 0)
	{
		koch(points.p1, points.p3, i-1, data);
		koch(points.p3, points.p4, i-1, data);
		koch(points.p4, points.p5, i-1, data);
		koch(points.p5, points.p2, i-1, data);
	}
	else
	{
		line(points.p1, points.p3, data); //first edge
 		line(points.p3, points.p4, data); //left edge
  		line(points.p4, points.p5, data); //right edge
		line(points.p5, points.p2, data); //last edge
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

void help_koch(t_data *data)
{
	point	p1;
	point	p2;

	p1.x = (WIDTH*0.05);
	p1.y = (HEIGHT*0.9);
	p2.x = (WIDTH*0.05 + 50);
	p2.y = (HEIGHT*0.9);
	line(p1, p2,  data); //plus

	p1.x = (WIDTH*0.05 + 25);
	p1.y = (HEIGHT*0.9 - 25);
	p2.x = (WIDTH*0.05 + 25);
	p2.y = (HEIGHT*0.9 + 25);
	line(p1, p2,  data);

	p1.x = (WIDTH*0.05 + 100);
	p1.y = (HEIGHT*0.9);
	p2.x = (WIDTH*0.05 + 150);
	p2.y = (HEIGHT*0.9);
	line(p1, p2,  data); //minus
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
	help_koch(data);
	while (i < 5)
	{
		if (data->koch == -1)
		{
			data->color_koch = 26;
			line(p1, p2,  data);
			data->color_koch = 30;
			line(p1, p3, data);
			data->color_koch = 34;
			line(p3, p2, data);
		}
		else
		{
			data->color_koch = 26;
			koch( p2, p1 , data->koch , data); //base
			data->color_koch = 30;
			koch(p1, p3, data->koch , data);
			data->color_koch = 34;
			koch( p3, p2, data->koch, data);
		}
		p2.x += i;
		p2.y += i;
		p1.x += i;
		p1.y += i;
		p3.x += i;
		p3.y += i;
		i = i + 0.5;
	}
	return (0);
}

