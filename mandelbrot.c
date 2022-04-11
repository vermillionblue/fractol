#include "fractol.h"
#include <stdio.h>

void iter_mb(t_data *data);

void my_hook(void *param)
{
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
}

void    zoom(t_data *data, int direction)
{
	if (direction)
	{
		data->r_max = data->r_max  + (0.1 * 1.02);
    	data->r_min = data->r_min - (0.1 * 1.02);
    	data->i_max = data->i_max + (0.1 * 1.02);
   		data->i_min = data->i_min - (0.1 * 1.02);
	}
	else
	{
		data->r_max = data->r_max - (0.1 * 1.02);
    	data->r_min = data->r_min + (0.1 * 1.02);
    	data->i_max = data->i_max - (0.1 * 1.02);
   		data->i_min = data->i_min + (0.1 * 1.02);
	}
    
}
void my_scroll(double xdelta, double ydelta, void* data)
{
	int i = 0;
	if (ydelta > 0)
	{
		zoom(data, 1);
		iter_mb(data);
	}
	else
	{
		zoom(data, 0);
		iter_mb(data);
	}
	
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
	//return ( i  + 1 - log(log((magnitute(z))))/log(2));
    return ( i  + 1 - log(log((magnitute(z))))/log(2));
}

void iter_mb(t_data *data)
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
            	color( m,  x,  y, data->g_img);
			else
				mlx_put_pixel(data->g_img, x, y, 0x000000FF);
			x++	;
		}
		y++;
	}
}

void draw_mb()
{
    mlx_t	*mlx;
	t_data	data;
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false);
	if (!mlx)
		exit(EXIT_FAILURE);
	data.g_img = mlx_new_image(mlx, WIDTH, HEIGHT);  
	mlx_image_to_window(mlx, data.g_img, 0, 0);
	boundaries_mandelbrot(&data);

    iter_mb(&data);
	
	mlx_scroll_hook(mlx, &my_scroll, &data);
    mlx_loop_hook(mlx, &my_hook, mlx);
	//mlx_resize_hook(mlx, &my_resize, g_img);
    mlx_loop(mlx);
	mlx_delete_image(mlx, data.g_img); 
	mlx_terminate(mlx);
    
}
