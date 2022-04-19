#include <stdlib.h>
#include <stdio.h>

#include "fractol.h"



// void start()
// {
// 	mlx_t	*mlx;
// 	t_data data;

// 	static mlx_image_t *g_img;
// 	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
// 	if (!mlx)
// 		exit(EXIT_FAILURE);
// 	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);  // Creates a new image.
// 	mlx_image_to_window(mlx, g_img, 0, 0);
// 	boundaries_mandelbrot(&data);
// 	draw_mb(g_img, &data, mlx);
// }

// void drawcircle()
// {
// 	mlx_t	*mlx;

// 	static mlx_image_t *g_img;
// 	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
// 	if (!mlx)
// 		exit(EXIT_FAILURE);
// 	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);  // Creates a new image.
// 	mlx_image_to_window(mlx, g_img, 0, 0);  // Adds an image to the render queue.
// 	float y = 0;
// 	float x = 0;

// 	int h = 500;
// 	int k = 500;

// 	while (y < HEIGHT)
// 	{
// 		x = 0;
// 		while (x < WIDTH)
// 		{
// 			//(pow((x - h), 2)) + (pow((y - k), 2)) == 50000
// 			if ((pow((x - h), 2.0) + (pow((y - k), 2.0))) < 50000)
// 				mlx_put_pixel(g_img, x, y, 0x00000000);
// 			else
// 				mlx_put_pixel(g_img, x, y, 0x01FF4FFF);
// 			x++	;
// 		}
// 		y++;
// 	}
// 	mlx_loop(mlx);
// 	mlx_delete_image(mlx, g_img); // Once the application request an exit, cleanup.
// 	mlx_terminate(mlx);
// }



int	main(int argc, char **argv)
{
	if (argc == 2)
		draw_mb();
	// else
	// 	print_help();
	return (0);
}