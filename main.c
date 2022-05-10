/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:30:14 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/05 16:34:40 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(char **args)
{
	t_data	data;

	data.title = args[1];
	if (!ft_strncmp(args[1], "Julia", 6))
	{
		data.const_re = atof(args[2]);
		data.const_im = atof(args[3]);
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
	t_data	data;

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
