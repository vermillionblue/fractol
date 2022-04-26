#include "fractol.h"
#include <stdio.h>

void    boundaries_mandelbrot(t_data *data)
{
    data->r_max = 1.0 ;
    data->r_min = -2.0;
    data->i_max = 1.0;
    data->i_min = -1.0;
	data->swirl_mode = 0;
	data->color = 1;
}


void	init_draw(t_data *data)
{
	if (!ft_strncmp(data->title, "Mandelbrot", 11))
	{
		boundaries_mandelbrot(data);
		mlx_loop_hook(data->mlx, iter_mandelbrot, data);

	}
	else if (!ft_strncmp(data->title, "Julia", 6))
	{
		printf("error 1");
	}
	else
	{
		printf("error 2");
	}
}

void start_win(t_data data)
{
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, data.title);
	if (!data.mlx )
		exit(EXIT_FAILURE);
	data.img.img  = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);



	boundaries_mandelbrot(&data);
	iter_mandelbrot(&data);
	mlx_key_hook(data.mlx_win, &my_hook, &data);
	mlx_mouse_hook(data.mlx_win, &mouse_hook, &data);
    mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.mlx_win);
}
