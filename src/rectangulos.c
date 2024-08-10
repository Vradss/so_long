#include <MLX42/MLX42.h>
#include <stdlib.h>
#include <stdio.h>

//struct define position and dimensions 
typedef struct rect{
    int x;
    int y;
    int width;
    int height;
}t_rect;

static void error(void) {
    puts(mlx_strerror(mlx_errno));
    exit(EXIT_FAILURE);
}

void draw_pix(mlx_image_t *img, int x, int y){
    mlx_put_pixel(img, x, y, 0xFFFFFF);
}

void draw_rect(mlx_image_t *img, t_rect rect){
    int i;
    i = 0;
    while (i < rect.width){ //itera en width
        int j = 0;
        while ( j < rect.height){ //itera en height
            draw_pix(img, rect.x + i, rect.y + j);
            j++;
        }
        i++;
    }

}

int main (int argc, char **argv){
    mlx_t *mlx;
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    mlx_image_t *img;

    mlx = mlx_init(width, height, "vradss", 0);
    img = mlx_new_image(mlx, width, height); //crea y aloja el buffer de la imagen

    if (!mlx) {
        error();
    }

    t_rect rect = {100, 100, 200, 120}; //crear funcion , no acepta norma
    draw_rect(img, rect);
    mlx_image_to_window(mlx, img, 0, 0);

    mlx_loop(mlx);
    mlx_terminate(mlx);

    return 0;
}