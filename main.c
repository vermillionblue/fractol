/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:30:14 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/02 20:14:24 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//tasks
//rewrite atof
//adjust hsv to rgb function

#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>

void	init_julia(char **args)
{
	t_data data;
	data.title = args[1];
	if (!ft_strncmp(args[1], "Julia", 6))
	{
		data.const_re = atof(args[2]); //x
		data.const_im = atof(args[3]);
		printf("%f x and %f y", data.const_re, data.const_im);
		start_win(data);
	}
	
	else
	{
		ft_putstr_fd("Invalid entry\n", 2);
		print_help();
	}
		
	
}
void	init_name(char *name)
{
	t_data data;
	data.title = name;
	if (!ft_strncmp(name, "Mandelbrot", 11))
		start_win(data);
	else if (!ft_strncmp(name, "Koch", 5))
		start_win(data);
	else
	{
		ft_putstr_fd("Invalid entry\n", 2);
		print_help();
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		init_name(argv[1]);
	else if (argc == 4)
		init_julia(argv);
	else
		print_help();
	return (0);
}