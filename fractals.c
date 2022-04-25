/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:25:54 by danisanc          #+#    #+#             */
/*   Updated: 2022/04/25 10:54:45 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double  calculate_mb(t_complex in, t_data *data)
{
    t_complex	z;
	int			i;

    z.re = 0.0;
    z.im = 0.0;
	i  = -1;
    while (magnitude(z) <= 2.0 && ++i < MAX_ITERS)
		z = add(mult(z), in);
    if (i == MAX_ITERS)
        return (i);
	if (data->swirl_mode)
		return (i + 1 - logl(log(log(magnitude(z)))));
	else
		return (i  + 1 - log(log((magnitude(z))))/log(2)); 
}

