#include "fractol.h"
#include <stdio.h>

double  magnitute(t_complex z)
{
    double num1 = z.re * z.re;
    double num2  = z.im * z.im;
    return (sqrt(num1 + num2));
}

double map(int x, int y)
{
    int width = 1000;
    int height = 1000;
    int re_max = 2;
    int re_min = -2;
    int im_min = -2;
    int im_max = 2;
    
}

double  calculate(t_complex in)
{
    t_complex z;
    z.re = 0.0;
    z.im = 0.0;

    int i = 0;
    while (i < 10)
    {
        z.re  = z.re *z.re + in.re;
        z.im = z.im *z.im + in.im;
        printf("//%f//", magnitute(z));
        i++;
    }
    
    
    return ();
}



int main()
{
    t_complex in;
    in.im = 0;
    in.re = 1;
    int x, y;
    x = -2;
    y = 2;
    map(x, y);
    //calculate(in);

}
