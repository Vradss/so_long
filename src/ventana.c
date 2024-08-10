#include <MLX42/MLX42.h>
#include <stdlib.h>
#include <stdio.h>



int main(int argc, char **argv) {

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);

    mlx_t *mlx = mlx_init(width, height, "La Vradss", 0);
    if (!mlx) {
        return 1;
    }

    printf("W:%d\n", width);
    printf("H:%d\n", height);

    mlx_loop(mlx);
    mlx_terminate(mlx);

    return 0;
}
