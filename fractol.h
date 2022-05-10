/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:30:26 by danisanc          #+#    #+#             */
/*   Updated: 2022/05/10 23:05:29 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <math.h>
# include "mlx/mlx.h"
# define WIDTH (1280*2)
# define HEIGHT (720*2)
# define MAX_ITERS 50
# define _USE_MATH_DEFINES

typedef struct s_point
{
	double	x;
	double	y;
}				t_point;

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_rgb;

typedef struct s_double_rgb
{
	double	r;
	double	g;
	double	b;
	double	f;
	double	p;
	double	q;
	double	t;
}				t_double_rgb;

typedef struct s_hsv
{
	double	h;
	double	s;
	double	v;
}				t_hsv;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}					t_img;

typedef struct s_triangle
{
	t_point	p1;
	t_point	p2;
	t_point	p3;
}				t_triangle;

typedef struct s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct s_edge
{
	t_point	p1;
	t_point	p2;
	t_point	p3;
	t_point	p4;
	t_point	p5;
}				t_edge;

typedef struct s_data
{
	char			*title;
	double			zoom;
	double			maxiters;
	double			r_max;
	double			r_min;
	double			i_max;
	double			i_min;
	double			const_im;
	double			const_re;
	int				julia;
	int				hue;
	int				sat;
	int				val;
	int				mx;
	int				my;
	int				swirl_mode;
	int				rgb;
	int				red;
	int				green;
	int				blue;
	int				favorite;
	int				color_koch;
	int				koch;
	int				help;
	t_img			img;
	void			*mlx;
	void			*mlx_win;
	void			*img_addr;
	t_triangle		triangle;
}					t_data;
//operations
double		magnitude(t_complex z);
t_complex	add(t_complex f, t_complex s);
t_complex	mult(t_complex z);
//calculate values for each fractal
double		calculate_mb(t_complex in, t_data *data);
double		calculate_julia(t_complex in, t_data *data);
int			mouse_hook(int keynum, int x, int y, void *data);
void		print_help(void);
void		boundaries_mandelbrot(t_data *data);
void		start_win(t_data data);
void		color(double m, int x, int y, t_data *data);
int			create_rgb(int r, int g, int b, int a);
int			my_hook(int keysym, t_data *data);
int			iter_koch(t_data *data);
int			iter_fractal(t_data *data);
void		boundaries_julia(t_data *data);
t_complex	pow_z(t_complex z, int pow);
void		my_put_pixel(t_img *img, int x, int y, int color);
void		print_options(t_data *data);
void		mode_hook(int keysym, t_data *data);
void		color_hook(int keysym, t_data *data);
int			iter_koch(t_data *data);
void		clear_screen(t_data *data);
void		line(t_point p1, t_point p2, t_data *data);
void		zoom(t_data *data, int x, int y, int direction);
void		calculate_edges(t_edge *points);
void		koch(t_point p1, t_point p2, int i, t_data *data);
void		set_triangle(t_point *p1, t_point *p2, t_point *p3, t_data *data);
void		generator(t_point p1, t_point p2, t_point p3, t_data *data);
void		start_edges(t_point p1, t_point p2, t_point p3, t_data *data);
void		help_koch(t_data *data);
void		switch_value(int *n);
t_rgb		hsv2rgb(t_hsv hsv);
void		options_prompt(t_data *data);
double		screen2imaginary(double num, t_data *data);
double		screen2real(double num, t_data *data);
void		options_box(double x, double y, t_data *data);
void		zoom_koch(t_data *data, int x, int y, int direction);
t_point		transform_point(double transform[4][4], t_point p);
t_point		scale_point(t_point p1, double scale_factor);
void		arrows_koch(int key, t_data *data);
void		arrows_complex(int key, t_data *data);
void		init_triangle(t_data *data);
void		calculate_p3(t_data *data);
#endif
