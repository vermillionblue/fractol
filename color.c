#include "fractol.h"
#include <stdio.h>


typedef struct s_rgb
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
}				t_rgb;

typedef struct s_hsv
{
	double H;
	double S;
	double V;
}				t_hsv;

t_rgb hsv2rgb(t_hsv hsv) {
	double r = 0, g = 0, b = 0;
	t_rgb rgb;
	if (hsv.S == 0)
	{
		r = hsv.V;
		g = hsv.V;
		b = hsv.V;
	}
	else
	{
		int i;
		double f, p, q, t;

		if (hsv.H == 360)
			hsv.H = 0;
		else
			hsv.H = hsv.H / 60;

		i = (int)trunc(hsv.H);
		f = hsv.H - i;

		p = hsv.V * (1.0 - hsv.S);
		q = hsv.V * (1.0 - (hsv.S * f));
		t = hsv.V * (1.0 - (hsv.S * (1.0 - f)));

		switch (i)
		{
		case 0:
			r = hsv.V;
			g = t;
			b = p;
			break;

		case 1:
			r = q;
			g = hsv.V;
			b = p;
			break;

		case 2:
			r = p;
			g = hsv.V;
			b = t;
			break;

		case 3:
			r = p;
			g = q;
			b = hsv.V;
			break;

		case 4:
			r = t;
			g = p;
			b = hsv.V;
			break;

		default:
			r = hsv.V;
			g = p;
			b = q;
			break;
		}

	}
	rgb.R = r * 255;
	rgb.G = g * 255;
	rgb.B = b * 255;
	return rgb;
}


int createRGB(int r, int g, int b, int a)
{   
	return (a << 24 | r << 16 | g << 8 | b);
}
void color(double m, int x, int y, t_data *data)
{
	t_hsv hsv;
	t_rgb rgb;
	int	color;
	hsv.H = (1*data->hue) * m;
	hsv.S = 1 - 0.1*(data->sat);
	hsv.V = 1 - 0.1*(data->val);
	rgb = hsv2rgb(hsv);

	if (data->favorite)
		color = createRGB(200 , 20 + 15*m  , 20 + 15*m , 0); // fav
	else if (data->rgb)
		color = createRGB(20 + data->red*m, 20 + data->green*m , 20 + data->blue*m, 0);
	else
    	color = createRGB(rgb.R , rgb.G  , rgb.B , 1); // r g b a
    mlx_pixel_put(data->mlx, data->mlx_win, x, y, color);
}