/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:30:26 by danisanc          #+#    #+#             */
/*   Updated: 2022/04/26 13:56:57 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <math.h>
# include "mlx/mlx.h"

# define WIDTH (1280)
# define HEIGHT (720)
# define MAX_ITERS 50

typedef struct 		s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}					t_img;


typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_data
{
	char			*title;
	double			zoom;
	double			maxiters;
	double			r_max;
	double			r_min;
	double			i_max;
	double			i_min;
	int				hue;
	int				sat;
	int				val;
	int				mx; //mouse position
	int				my;
	int				swirl_mode;
	t_img			img;
	void			*mlx;
	void			*mlx_win;
	void			*img_addr;
}					t_data;

//operations
double  magnitude(t_complex z);
t_complex	add(t_complex f, t_complex s);
t_complex	mult(t_complex z);

//calculate values for each fractal
double  calculate_mb(t_complex in, t_data *data);
double calculate_julia(t_complex in, t_data *data);


int mouse_hook(int keynum, int x, int y, void *data);
void    print_help();
void    boundaries_mandelbrot(t_data *data);
void start_win(t_data data);
//double  calculate(t_complex in, t_data *data);
void color(double m, int x, int y, t_data *data);
int createRGB(int r, int g, int b, int a);
int my_hook(int keysym, t_data *data);
int iter_mandelbrot(t_data *data);

t_complex pow_z(t_complex z, int pow);

#endif