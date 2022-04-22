#include "fractol.h"
#include <stdio.h>

int my_hook(int keysym, t_data *data)
{
	if (keysym == 53)
		mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
	return (0);
}


double lerp(double start, double end, double step)
{
	return (start + (end - start) * step);
}

void scr2obj(t_data *data)
{
	data->mx = (double)(data->r_min + (double)data->mx / (double)WIDTH * (data->r_max - data->r_min));
	data->my =(double) (data->i_min + (double)data->my / ((double)HEIGHT)*((data->i_max - data->i_min)));
}

void    zoom(t_data *data, int x, int y, int direction)
{
	double	zoom_v, step;
	step = 1.02;
	zoom_v = 1.02;
	data->mx = x;
	data->my = y;
	scr2obj(data);
	if (direction)
	{
		
		step *= 0.25;
		//data->zoom = zoom_v / data->zoom;
	}
	else
	{
		step /=  0.25;
		//data->zoom = data->zoom / zoom_v;
	}
		data->r_max = lerp(data->mx, data->r_max, step);
    	data->r_min = lerp(data->mx, data->r_min, step);
    	data->i_max = lerp(data->my, data->i_max, step);
   		data->i_min = lerp(data->my, data->i_min, step);
    
}
int mouse_hook(int keynum, int x, int y, void *data)
{
	if (keynum == 5)
		zoom(data, x, y, 1);
	if(keynum == 4)
		zoom(data, x, y,0);
	
	return (0);
}

void    boundaries_mandelbrot(t_data *data)
{
    data->r_max = 1.0 ;
    data->r_min = -2.0;
    data->i_max = 1.0;
    data->i_min = -1.0;
}

double  magnitute(t_complex z)
{
    double num1 = z.re * z.re;
    double num2  = z.im * z.im;
    return (sqrt(num1 + num2));
}

t_complex	add(t_complex f, t_complex s)
{
	t_complex z;
	z.re = f.re + s.re;
	z.im = f.im + s.im;
	return (z);
}

t_complex	mult(t_complex z)
{
	t_complex temp;
	
	temp.re = z.re*z.re - z.im*z.im;
	temp.im = z.im*z.re + z.re*z.im;
	return (temp);
}

double  calculate(t_complex in, t_data *data)
{
    t_complex z;
    z.re = 0.0;
    z.im = 0.0;

    int i = 0;
    while (magnitute(z) <= 2.0 && i < MAX_ITERS)
    {
		z = add(mult(z), in);
        i++;
    }
    if (i == MAX_ITERS)
        return (i);
	return ( i  + 1 - log(log((magnitute(z))))/log(2)); 
    //return ( i + 1 - logl(log(log(magnitute(z))))); //swirl mode
}

int iter_mb(t_data *data)
{
	t_complex in;
	int x;
    int y;
    double m;
	y = 0.0;
    x = 0.0;
    in.re = 0.0;
	in.im = 0.0;
    while (y < HEIGHT)
	{
		x = 0.0;
		while (x < WIDTH)
		{
			in.re = (double)(data->r_min + (double)x / (double)WIDTH * (data->r_max - data->r_min));
			in.im =(double) (data->i_min + (double)y / ((double)HEIGHT)*((data->i_max - data->i_min)));
            m = calculate(in, data);
			if (m != MAX_ITERS)
            	color( m,  x,  y, data);
			else
				mlx_pixel_put(data->mlx, data->mlx_win, x, y, 0xFF000000);
			x++	;
		}
		y++;
	}
	return (0);
}

void draw_mb()
{
	t_data	data;
	t_img	img;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "MLX42");
	if (!data.mlx )
		exit(EXIT_FAILURE);
	
	data.img.img  = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);

	boundaries_mandelbrot(&data);
	
	// mlx_hook(data.win_ptr, 17, 0, &destroy_exit, &data);
	mlx_loop_hook(data.mlx, iter_mb, &data);
	// mlx_mouse_hook(data.win_ptr, &handle_mouse, &data);
	//mlx_loop_hook(data.mlx, iter_mb, &data);

	mlx_key_hook(data.mlx_win, &my_hook, &data);
	mlx_mouse_hook(data.mlx_win, &mouse_hook, &data);

    mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.mlx_win);
}
