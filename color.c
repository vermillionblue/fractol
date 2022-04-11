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
    return (*(int32_t  *)(unsigned char [4]){a, b, g, r});
}
void color(double m, int x, int y, mlx_image_t *img)
{

    int32_t color = createRGB(50 + 5*m , 20 + 10*m  , 100 , 255); // r g b a
   
    mlx_put_pixel(img, x, y, color);
}