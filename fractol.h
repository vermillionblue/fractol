/*
**  Complex number
*/

/*
** re — real part
** im — imaginary part
*/
#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <math.h>
# include "mlx/mlx.h"

# define WIDTH (1280*2)
# define HEIGHT (720*2)
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
	int32_t			mx; //mouse position
	int32_t			my;
	t_img			img;
	void			*mlx;
	void			*mlx_win;
	void			*img_addr;
}					t_data;



//void    print_help(void);
void    boundaries_mandelbrot(t_data *data);
void draw_mb();
//double  calculate(t_complex in, t_data *data);
void color(double m, int x, int y, t_data *data);
int createRGB(int r, int g, int b, int a);
char	*ft_toupperhex(unsigned long n);
#endif