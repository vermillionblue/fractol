/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:30:28 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/03 16:37:45 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int iter_koch(t_data *data);

int iter_fractal(t_data *data)
{
	t_complex	in;
	int			x;
    int			y;
    double		m;

	y = 0.0;
    x = 0.0;
    in.re = 0.0;
	in.im = 0.0;
	
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	if (data->help)
		mlx_string_put(data->mlx, data->mlx_win, (WIDTH/2), (HEIGHT/2), createRGB(255,255,255,0), "HELP");
    while (y < HEIGHT)
	{
		x = 0.0;
		while (x < WIDTH)
		{
			in.re = (double)(data->r_min + (double)x / WIDTH * (data->r_max - data->r_min));
			in.im =(double) (data->i_min + (double)y / HEIGHT*((data->i_max - data->i_min)));
					
			if (data->julia || (!ft_strncmp(data->title, "Julia", 6)))
				m = calculate_julia(in, data);
			else
				m = calculate_mb(in, data);

			if (m == MAX_ITERS)
				my_put_pixel(&data->img, x, y, 0x00000000);
			else
				color(m,  x,  y, data);
			x++;
		}
		y++;
	}
	return (0);
}


 
#define pi 3.1416


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


void line(double x1, double y1, double x2, double y2, t_data *data)
{
	double y , x;
	double temp;
	y = 0;
	x = 0;

	if (x1 > x2)
	{
		temp = y2;
		y2 = y1;
		y1 = temp;
		temp = x1;
		x1 = x2;
		x2 = temp;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);

	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{	
			
			double line_eq = (y - y1) - ((y2 - y1) / (x2 - x1) * (x - x1));
			if (abs(line_eq) < 1 && x >= x1 && x <= x2) //&& x > x1 && x < x2
				color(data->color_koch, x, y, data);
			x++;
		}
		y++;
	}
}
	

void koch(double x1, double y1, double x2, double y2, double 
it, t_data *data)
{
	double angle = 60*pi/180;


	double x3 = (2*x1+x2)/3;
	double y3 = (2*y1+y2)/3;

	double x4 = (x1+2*x2)/3;
	double y4 = (y1+2*y2)/3;

	

	double x = x3 + (x4-x3)*cos(angle)+(y4-y3)*sin(angle);
	double y = y3 - (x4-x3)*sin(angle)+(y4-y3)*cos(angle);

	if(it > 0)
	{
		koch(x1, y1, x3, y3, it-1, data);
		koch(x3, y3, x, y, it-1, data);
		koch(x, y, x4, y4, it-1, data);
		koch(x4, y4, x2, y2, it-1, data);
	}

	else
	{
		line(x1, y1, x3, y3, data); //first edge
 		line(x3, y3, x, y , data); //left edge
  		line(x, y, x4, y4, data); //right edge
		line(x4, y4 , x2, y2,data); //last edge

	}
	
}

int iter_koch(t_data *data)
{

	double			x;
    double			y;
	point p1, p2, p3;

	clear_screen(data); //try int	mlx_clear_window(void *mlx_ptr, void *win_ptr);
	p1.x = (WIDTH/4) + 150;
	p1.y = (HEIGHT*3/4 ) - 80;

	p2.x = (WIDTH*3/4) - 150;
	p2.y = (HEIGHT*3/4) - 80;



	double angle = 60*pi/180;

	p3.x = p1.x + (p2.x-p1.x)*cos(angle)+(p2.y-p1.y)*sin(angle);
	p3.y = p1.y - (p2.x-p1.x)*sin(angle)+(p2.y-p1.y)*cos(angle);

	
	

	float i = 0;

	
		while (i <= 25)
		{
			if (data->koch == -1)
			{
				data->color_koch = 26;
				line(p1.x, p1.y, p2.x, p2.y,  data);
				data->color_koch = 30;
				line(p1.x, p1.y, p3.x, p3.y, data);
				data->color_koch = 34;
				line(p3.x, p3.y,p2.x, p2.y, data);
			}
			else
			{
				data->color_koch = 26;
				koch( p2.x + i, p2.y + i, p1.x + i , p1.y + i, data->koch , data); //base
				data->color_koch = 30;
				koch(p1.x + i , p1.y + i, p3.x + i, p3.y + i, data->koch , data);
				data->color_koch = 34;
				koch( p3.x + i, p3.y + i,p2.x + i, p2.y + i, data->koch, data);
			}
			i = i + 5;
		}
	return (0);
}

