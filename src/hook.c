#include "../include/so_long.h"

//struct define position and dimensions 
typedef struct rect{
    int x;
    int y;
    int width;
    int height;
}t_rect;

#define WIDTH 1000
#define HEIGHT 1000

typedef struct pos{
    int x;
    int y;
}           vector2;

vector2 pos = {0,0};

// static void error(void) 
// {
//     puts(mlx_strerror(mlx_errno));
//     exit(EXIT_FAILURE);
// }
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

//keys d : derecha, s: abajo, a: izquierda, w: arriba

void key_handle(mlx_key_data_t keydata, void* param){
    
    if(keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
        pos.x = pos.x + 64;
    if(keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
        pos.x = pos.x - 64;
    if(keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
        pos.y = pos.y + 64;
    if(keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
        pos.y = pos.y - 64;
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window((mlx_t*)param);

}

//clean image


void mlx_image_clear(mlx_image_t* img, uint32_t color) {
    uint32_t x = 0;
    while (x < img->width) {
        uint32_t y = 0;
        while (y < img->height) {
            mlx_put_pixel(img, x, y, color);
            y++;
        }
        x++;
    }
}

void game_loop(void *param){
    mlx_image_t *img = (mlx_image_t *)param;

    mlx_image_clear(img, 0x000000);
    t_rect rect = {pos.x, pos.y, 64, 64};
    draw_rect(img, rect);

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

    mlx_key_hook(mlx, key_handle, img);
    mlx_loop_hook(mlx, game_loop, img);
    mlx_image_to_window(mlx, img, 0, 0);
    mlx_loop(mlx);
    mlx_terminate(mlx);

    return 0;
}