#include "fractol.h"
#include <stdio.h>

typedef struct s_color {
	int r;
	int g;
	int b;
	int t;
}	t_color;

int32_t createRGB(int r, int g, int b, int a)
{   
	return (a << 24 | r << 16 | g << 8 | b);
}
void color(double m, int x, int y, t_data *data)
{

    int32_t color = createRGB(50 + 5*m , 20 + 10*m  , 100 , 20); // r g b a
   
    mlx_pixel_put(data->mlx, data->mlx_win, x, y, color);
}