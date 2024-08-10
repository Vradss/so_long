#include "MLX42/MLX42.h"

#define WIDTH 800
#define HEIGHT 800

int main () {
    mlx_t *mlx;
    mlx_image_t *img;

    mlx = mlx_init(WIDTH, HEIGHT, "La Vradsss", 0);
    img = mlx_new_image(mlx, WIDTH, HEIGHT);

    mlx_image_to_window(mlx, img, 0, 0);
    mlx_put_pixel(img, 0, 0, 0x64E9EE);
    mlx_put_pixel(img, 400, 400, 0x64E9EE);

    mlx_loop(mlx);
    mlx_terminate(mlx);
}