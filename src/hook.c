#include <MLX42/MLX42.h>
#include <stdlib.h>
#include <stdio.h>

// struct define position and dimensions 
// typedef struct rect{
//     int x;
//     int y;
//     int width;
//     int height;
// }t_rect;

#define WIDTH 500
#define HEIGHT 500

typedef struct pos{
    int x;
    int y;
}vector2;

vector2 pos = {50, 50};

static void error(void) {
    puts(mlx_strerror(mlx_errno));
    exit(EXIT_FAILURE);
}

void draw_pix(mlx_image_t *img, int x, int y){
    mlx_put_pixel(img, x, y, 0xFFFFFF);
}

void draw_rect(mlx_image_t *img, vector2 pos){
    int i;
    i = 0;
    while (i < 250){ //itera en width
        int j = 0;
        while ( j < 200){ //itera en height
            draw_pix(img, pos.x + i, pos.y + j);
            j++;
        }
        i++;
    }

}

//keys d : derecha, s: abajo, a: izquierda, w: arriba

void key_handle(mlx_key_data_t keydata, void* param){
    mlx_image_t *img = (mlx_image_t *)param; //casteamos param para que sea un mlx_image_t
    
    if(keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
        pos.x = pos.x + 10;
    if(keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
        pos.x = pos.x - 10;
    if(keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
        pos.y = pos.y + 10;
    if(keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
        pos.y = pos.y - 10;

    draw_rect(img, pos);
}



int main (){
    mlx_t *mlx;
    mlx_image_t *img;

    mlx = mlx_init(WIDTH, HEIGHT, "vradss", 0);
    img = mlx_new_image(mlx, WIDTH, HEIGHT); //crea y aloja el buffer de la imagen

    if(!mlx) {
        error();
    }

    if(!img) {
        error();
    }

    draw_rect(img, pos);
    mlx_key_hook(mlx, key_handle, img);
    mlx_image_to_window(mlx, img, 0, 0);
    mlx_loop(mlx);
    mlx_terminate(mlx);

    return 0;
}