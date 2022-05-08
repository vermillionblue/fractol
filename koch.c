/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:36:30 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/08 22:55:37 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_edges(t_edge *points)
{
	double	angle;

	angle = 60 * M_PI / 180;
	points->p3.x = (2 * points->p1.x + points->p2.x) / 3;
	points->p3.y = (2 * points->p1.y + points->p2.y) / 3;
	points->p5.x = (points->p1.x + 2 * points->p2.x) / 3;
	points->p5.y = (points->p1.y + 2 * points->p2.y) / 3;
	points->p4.x = points->p3.x + (points->p5.x - points->p3.x) * cos(angle) \
	+ (points->p5.y - points->p3.y) * sin(angle);
	points->p4.y = points->p3.y - (points->p5.x - points->p3.x) * sin(angle) \
	+ (points->p5.y - points->p3.y) * cos(angle);
}

void	koch(t_point p1, t_point p2, int i, t_data *data)
{
	t_edge	points;

	points.p1 = p1;
	points.p2 = p2;
	calculate_edges(&points);
	if (i > 0)
	{
		koch(points.p1, points.p3, i - 1, data);
		koch(points.p3, points.p4, i - 1, data);
		koch(points.p4, points.p5, i - 1, data);
		koch(points.p5, points.p2, i - 1, data);
	}
	else
	{
		line(points.p1, points.p3, data);
		line(points.p3, points.p4, data);
		line(points.p4, points.p5, data);
		line(points.p5, points.p2, data);
	}
}

void	set_triangle(t_point *p1, t_point *p2, t_point *p3, t_data *data)
{
	p1->x = data->triangle.p1.x;
	p1->y = data->triangle.p1.y;
	
	p2->x = data->triangle.p2.x;
	p2->y = data->triangle.p2.y;
	
	p3->x = fabs(floor(data->triangle.p3.x));
	p3->y = fabs(floor(data->triangle.p3.y));
}

void	generator(t_point p1, t_point p2, t_point p3, t_data *data)
{
	data->color_koch = 26;
	line(p1, p2, data);
	data->color_koch = 30;
	line(p1, p3, data);
	data->color_koch = 34;
	line(p3, p2, data);
}

void	start_edges(t_point p1, t_point p2, t_point p3, t_data *data)
{
	data->color_koch = 26;
	koch(p2, p1, data->koch, data);
	data->color_koch = 30;
	koch(p1, p3, data->koch, data);
	data->color_koch = 34;
	koch(p3, p2, data->koch, data);
}
