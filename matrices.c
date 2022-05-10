/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:24:41 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/09 18:26:43 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	matrix_vector_multiplication(double transform[4][4], double vector[4], \
		double r_vector[4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		r_vector[i] = 0.0;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			r_vector[i] += transform[i][j] * vector[j];
			j++;
		}
		i++;
	}
}

t_point	transform_point(double transform[4][4], t_point p)
{
	t_point	transformed_point;
	double	vector[4];
	double	r_vector[4];

	vector[0] = p.x;
	vector[1] = p.y;
	vector[2] = 0.0;
	vector[3] = 1.0;
	matrix_vector_multiplication(transform, vector, r_vector);
	transformed_point.x = r_vector[0];
	transformed_point.y = r_vector[1];
	return (transformed_point);
}

void	scale_transform(double transform[4][4], double scale_factor)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			transform[i][j] *= scale_factor;
			j++;
		}
		i++;
	}
}

t_point	scale_point(t_point p1, double scale_factor)
{
	t_point	temp_point;

	temp_point.x = scale_factor * p1.x;
	temp_point.y = scale_factor * p1.y;
	return (temp_point);
}
