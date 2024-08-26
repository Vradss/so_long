#include "../include/so_long.h"

mlx_image_t* load_png(mlx_t *mlx, const char *path)
{
    mlx_texture_t *texture = mlx_load_png(path);
    if (!texture)
        error("Failed to load PNG texture");
    
    mlx_image_t *img = mlx_texture_to_image(mlx, texture);
    if (!img)
    {
        mlx_delete_texture(texture);
        error("Failed to convert texture to image");
    }
    mlx_delete_texture(texture);
    return img;
}

void render_map(mlx_t *mlx, mlx_image_t *floor_img, mlx_image_t *wall_img, char **map)
{
    size_t y = 0;
    size_t x;

    while (map[y] != NULL)
    {
        x = 0;
        while (map[y][x] != '\0')
        {
            int tile_x = x * TILE_SIZE;
            int tile_y = y * TILE_SIZE;

            if (map[y][x] == '1')
                mlx_image_to_window(mlx, wall_img, tile_x, tile_y);
            else if (map[y][x] == '0' || map[y][x] == 'P' || map[y][x] == 'E' || map[y][x] == 'C')
                mlx_image_to_window(mlx, floor_img, tile_x, tile_y);

            x++;
        }
        y++;
    }
}

int32_t main(int argc, char **argv)
{
    if (argc != 2)
    {
        error("Usage: ./text2 map.ber");
        return EXIT_FAILURE;
    }
    t_game game;

    game.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Vrads testing", true);

    mlx_t *mlx;
    mlx_image_t *floor_img, *wall_img;
    char **map;

    mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Vrads testing", true);
    if (!mlx)
        error("Failed to initialize MLX");

    floor_img = load_png(mlx, FLOOR_SRC);
    wall_img = load_png(mlx, WALLS_SRC);

    map = create_map(argv[1]);
    render_map(mlx, floor_img, wall_img, map);

    mlx_loop(mlx);

    mlx_delete_image(mlx, floor_img);
    mlx_delete_image(mlx, wall_img);
    mlx_terminate(mlx);

    // Free map memory
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);

    return EXIT_SUCCESS;
}
