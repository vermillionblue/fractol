#include "fractol.h"
#include <stdio.h>

void    boundaries_mandelbrot(t_data *data)
{
    data->r_max = 2.0;
    data->r_min = -2.0;
    data->i_max = 2.0;
    data->i_max = -2.0;
}

double  magnitute(t_complex z)
{
    double num1 = z.re * z.re;
    double num2  = z.im * z.im;
    return (sqrt(num1 + num2));
}

double  calculate(t_complex in, t_data *data)
{
    t_complex z;
    z.re = 0.0;
    z.im = 0.0;

    int i = 0;
    while (magnitute(z) <=2 && i < MAX_ITERS)
    {
        z.re  = z.re *z.re + in.re;
        z.im = z.im *z.im + in.im;
        printf("--%f---", magnitute(z));
        i++;
    }
    
 
    return ();
}

void draw_mb()
{
    t_complex in;
    double x;
    double y;
    double m;

    mlx_t	*mlx;
	t_data data;

	static mlx_image_t *g_img;
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);  // Creates a new image.
	mlx_image_to_window(mlx, g_img, 0, 0);
	boundaries_mandelbrot(&data);


    y = 0.0;
    x = 0.0;
    in.re = 0.0;
	in.im = 0.0;
    while (y < HEIGHT)
	{
		x = 0.0;
		while (x < WIDTH)
		{
            in.re = (data.r_min+ x) / ((double)WIDTH * (data.r_max - data.r_min));
            in.im = (data.i_min+ y) / ((double)HEIGHT * (data.i_max - data.i_min));
            m = calculate(in, &data);
            
			if (m == MAX_ITERS)
				mlx_put_pixel(g_img, x, y, 0x000000);
			else
				mlx_put_pixel(g_img, x, y, 0x9BB1FF);
			x++	;
		}
		y++;
	}
    mlx_loop(mlx);
	mlx_delete_image(mlx, g_img); // Once the application request an exit, cleanup.
	mlx_terminate(mlx);
}
