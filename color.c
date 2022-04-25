#include "fractol.h"
#include <stdio.h>

typedef struct s_color {
	int r;
	int g;
	int b;
	int t;
}	t_color;

int createRGB(int r, int g, int b, int a)
{   
	return (a << 24 | r << 16 | g << 8 | b);
}
void color(double m, int x, int y, t_data *data)
{
    int color = createRGB(50 + 2*m , 20 + 4*m  , 30 + 6*m , 20);// r g b a
   //int color = createRGB(200 , 2 + 20*m  , 2 + 20*m , 200); // fav
    mlx_pixel_put(data->mlx, data->mlx_win, x, y, color);
}