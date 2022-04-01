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
# include "MLX42/include/MLX42/MLX42.h"

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITERS 50

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_data
{
	char			*title;
	double				maxiters;
	double			r_max;
	double			r_min;
	double			i_max;
	double			i_min;	
}					t_data;

void    print_help(void);
void    boundaries_mandelbrot(t_data *data);
void draw_mb();
//double  calculate(t_complex in, t_data *data);

#endif