/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:30:14 by danisanc          #+#    #+#             */
/*   Updated: 2022/04/25 10:27:19 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_name(char *name)
{
	t_data data;
	data.title = name;
	if (!ft_strncmp(name, "Mandelbrot", 11))
		start_win(data);
	else if (!ft_strncmp(name, "Julia", 6))
		start_win(data);
	else if (!ft_strncmp(name, "Extra", 6))
		start_win(data);
	else
		ft_putstr_fd("Invalid name\n", 2);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		init_name(argv[1]);
	else
		print_help();
	return (0);
}