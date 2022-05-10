/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:36:55 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/09 18:55:47 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int *)pixel = color;
}

void	clear_screen(t_data *data)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{	
			my_put_pixel(&data->img, x, y, create_rgb(0, 0, 0, 0));
			x++;
		}
		y++;
	}
}

void	swap_values(t_point *p1, t_point *p2)
{
	double	temp;

	temp = p2->y;
	p2->y = p1->y;
	p1->y = temp;
	temp = p1->x;
	p1->x = p2->x;
	p2->x = temp;
}

void	line(t_point p1, t_point p2, t_data *data)
{
	double	x;
	double	y;
	double	line_eq;

	y = 0;
	x = 0;
	if (p1.x > p2.x)
		swap_values(&p1, &p2);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{	
			if ((p2.x == p1.x) && (y >= p1.y && y <= p2.y))
				color(data->color_koch, p2.x, y, data);
			line_eq = (y - p1.y) - ((p2.y - p1.y) / (p2.x - p1.x) * (x - p1.x));
			if (fabs(line_eq) < 1 && x >= p1.x && x <= p2.x)
				color(data->color_koch, x, y, data);
			x++;
		}
		y++;
	}
}

void	init_triangle(t_data *data)
{
	double	angle;

	angle = 60 * M_PI / 180;
	data->triangle.p1.x = (WIDTH / 4) + 150;
	data->triangle.p1.y = (HEIGHT * 3 / 4) - 80;
	data->triangle.p2.x = (WIDTH * 3 / 4) - 150;
	data->triangle.p2.y = (HEIGHT * 3 / 4) - 80;
	calculate_p3(data);
}
