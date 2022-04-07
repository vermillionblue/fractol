#include "fractol.h"
#include <stdio.h>

int	ft_numlenhex(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char	*ft_toupperhex(unsigned long n)
{
	int		k;
	int		rem;
	char	*hex;
	int		s;

	k = ft_numlenhex(n);
	s = k;
	hex = malloc(k + 1);
	if (hex == NULL)
		return (NULL);
	while (k > 0)
	{
		rem = n % 16;
		n = n / 16;
		if (rem >= 0 && rem <= 9)
			hex[k - 1] = '0' + rem;
		if (rem >= 10 && rem <= 15)
			hex[k - 1] = 'A' + (rem - 10);
		k--;
	}
	hex[s] = '\0';
	return (hex);
}

void hook(void *param)
{
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
}

void    boundaries_mandelbrot(t_data *data)
{
    data->r_max = 1.0;
    data->r_min = -2.0;
    data->i_max = 1.0;
    data->i_max = -1.0;
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
	//i + 1 - log(log2(magnitute(z)));
    return (i + 1 - log(log2(magnitute(z))));
}

void color(double m, int x, int y, mlx_image_t *img)
{
    if (m > 100)
		m = 50;
    char *r = ft_toupperhex(50 + m);
    char *g = ft_toupperhex(50 + m);
    char *b = ft_toupperhex(50 + m);
    char *t = ft_toupperhex(100);
    char *color = ft_strjoin(r, g);
    color = ft_strjoin(color , b);
    color = ft_strjoin(color , t);
    //printf("//%s//", color);
    mlx_put_pixel(img, x, y, ft_atoi(color));
}

void draw_mb()
{
    t_complex in;
	int x;
    int y;
    double m;

    mlx_t	*mlx;
	t_data data;

	static mlx_image_t *g_img;
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);  
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
			in.re = (double)(data.r_min + (double)x / (double)WIDTH * (data.r_max - data.r_min));
			in.im =(double) (data.i_min + (double)y / ((double)HEIGHT)*((data.i_max - data.i_min)));
			
            m = calculate(in, &data);
			if (m != MAX_ITERS)
            	color( m,  x,  y, g_img);
			else
				mlx_put_pixel(g_img, x, y, 0x000000FF);
			x++	;
		}
		y++;
	}
    mlx_loop_hook(mlx, &hook, mlx);
    mlx_loop(mlx);
	mlx_delete_image(mlx, g_img); // Once the application request an exit, cleanup.
	mlx_terminate(mlx);
    
}
