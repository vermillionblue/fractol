#include "fractol.h"
#include "libft/libft.h"

void    print_help(void)
{
	ft_putendl_fd("Usage: ./fractol <name>", 1);
	ft_putendl_fd(NULL, 1);
	ft_putendl_fd("List of available fractals:", 1);
	ft_putendl_fd("Mandelbrot", 1);
	ft_putendl_fd("Julia", 1);
}


