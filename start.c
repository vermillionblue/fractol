#include "MLX42/include/MLX42/MLX42.h"

#include <stdlib.h>
#include <stdio.h>
#define WIDTH 256
#define HEIGHT 256

static mlx_image_t *g_img;


int32_t	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
        g_img = mlx_new_image(mlx, 128, 128);    // Creates a new image.
        mlx_image_to_window(mlx, g_img, 0, 0);   // Adds an image to the render queue.
        mlx_put_pixel(g_img, 64, 64, 0xFFFFFFFF); // Single white pixel in the middle.
	mlx_loop(mlx);
	mlx_delete_image(mlx, g_img); // Once the application request an exit, cleanup.
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}