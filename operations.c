/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:33:28 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/04 22:18:55 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	magnitude(t_complex z)
{
	double	num1;
	double	num2;

	num1 = z.re * z.re;
	num2 = z.im * z.im;
	return (sqrt(num1 + num2));
}

t_complex	add(t_complex f, t_complex s)
{
	t_complex	z;

	z.re = f.re + s.re;
	z.im = f.im + s.im;
	return (z);
}

t_complex	mult(t_complex z)
{
	t_complex	temp;

	temp.re = z.re * z.re - z.im * z.im;
	temp.im = z.im * z.re + z.re * z.im;
	return (temp);
}

t_complex	pow_z(t_complex z, int pow)
{
	t_complex	out;
	float		tetha;

	tetha = atan(z.re / z.im);
	out.re = magnitude(z) * cos(tetha * pow);
	out.im = magnitude(z) * sin(tetha * pow);
	return (out);
}
