#include <MLX42/MLX42.h>
#include <stdlib.h>
#include <stdio.h>


// //cursor handler
// void cursor_handler(double xpos, double ypos, void* param) {
//     printf("Posición del cursor: (%.0f, %.0f)\n", xpos, ypos);
// }

// int main() {
//     mlx_t* mlx = mlx_init(800, 600, "Cursor Example", false);
//     if (!mlx) return EXIT_FAILURE;

//     mlx_cursor_hook(mlx, cursor_handler, NULL);
//     mlx_loop(mlx);
//     mlx_terminate(mlx);
//     return EXIT_SUCCESS;
// }

// //scroll handler
// void scroll_handler(double xdelta, double ydelta, void* param) {
//     if (ydelta > 0) {
//         printf("Scroll hacia arriba\n");
//     } else {
//         printf("Scroll hacia abajo\n");
//     }
// }

// int main() {
//     mlx_t* mlx = mlx_init(800, 600, "Scroll Hook Example", true);
//     if (!mlx) return EXIT_FAILURE;

//     mlx_scroll_hook(mlx, scroll_handler, NULL);
//     mlx_loop(mlx);
//     mlx_terminate(mlx);
//     return EXIT_SUCCESS;
// }

//loop handler : generic loop
void loop_handler(void* param) {
    printf("Looping...\n");
}

int main() {
    mlx_t* mlx = mlx_init(800, 600, "Loop Hook Example", true);
    if (!mlx) return EXIT_FAILURE;

    mlx_loop_hook(mlx, loop_handler, NULL);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return EXIT_SUCCESS;
}