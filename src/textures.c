/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradis <vradis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:28:38 by vradis            #+#    #+#             */
/*   Updated: 2024/08/26 13:34:29 by vradis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

mlx_image_t* load_png(mlx_t *mlx, const char *path)
{
    // Load the PNG texture
    mlx_texture_t *texture = mlx_load_png(path);
    if (!texture)
        error("Failed to load PNG texture");
    
    mlx_image_t *img = mlx_texture_to_image(mlx, texture);
    if (!img)
    {
        mlx_delete_texture(texture);
        error("Failed to convert texture to image");
    }
    // Clean up the texture as we only need the image now
    mlx_delete_texture(texture);
    return img;
}
t_images load_images(mlx_t *mlx)
{
    t_images images;

    images.wall_img = mlx_load_png()
}


void render_map(t_game *game)
{
    size_t  y;
    size_t  x;

    y = 0;
    while (game->map->grid[y] != NULL)
    {
        x = 0;
        while (game->map->grid[y][x] != '\0')
        {
            render_tile(game, y, x)
            x++;
        }
        y++;
    }
}

void render_tile(t_game, size_t y, size_t x)
{
    int tile_x;
    int tile_y;
    char tile;
    
    tile_x = x * TILE_SIZE;
    tile_y = x * TILE_SIZE;
    tile = game->map->grid[y][x];
    
    if (tile == '1')
        mlx_image_to_window(game->mlx, game->images.wall_img, tile_x, tile_y);
    else if (tile == '0')
        mlx_image_to_window(game->mlx, game->images.floor_img, tile_x, tile_y);
    else if (tile = 'C')
        mlx_image_to_window(game->mlx, game->images.coll_img, tile_x, tile_y);
    else if (tile = 'E')
        mlx_image_to_window(game->mlx, game->images.exit_img, tile_x, tile_y);
}



// void render_map(mlx_t *mlx, mlx_image_t *floor_img, mlx_image_t *wall_img, char **map)
// {
//     size_t y = 0;
//     size_t x;

//     while (map[y] != NULL)
//     {
//         x = 0;
//         while (map[y][x] != '\0')
//         {
//             int tile_x = x * TILE_SIZE;
//             int tile_y = y * TILE_SIZE;

//             if (map[y][x] == '1')
//                 mlx_image_to_window(mlx, wall_img, tile_x, tile_y);
//             else if (map[y][x] == '0' || map[y][x] == 'P' || map[y][x] == 'E' || map[y][x] == 'C')
//                 mlx_image_to_window(mlx, floor_img, tile_x, tile_y);

//             x++;
//         }
//         y++;
//     }
// }

// int32_t main(int argc, char **argv)
// {
//     if (argc != 2)
//     {
//         ft_printf(stderr, "Usage: %s <map_file>\n", argv[0]);
//         return EXIT_FAILURE;
//     }

//     mlx_t *mlx;
//     mlx_image_t *floor_img, *wall_img;
//     char **map;

//     // Initialize MLX
//     mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Vrads testing", true);
//     if (!mlx)
//         error("Failed to initialize MLX");

//     // Load textures
//     floor_img = load_png(mlx, FLOOR_SRC);
//     wall_img = load_png(mlx, WALLS_SRC);

//     // Load map and render it
//     map = create_map(argv[1]);
//     render_map(mlx, floor_img, wall_img, map);

//     // Start the MLX loop
//     mlx_loop(mlx);

//     // Clean up
//     mlx_delete_image(mlx, floor_img);
//     mlx_delete_image(mlx, wall_img);
//     mlx_terminate(mlx);

//     // Free map memory
//     for (int i = 0; map[i] != NULL; i++)
//         free(map[i]);
//     free(map);

//     return EXIT_SUCCESS;
// }

int32_t main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_printf(stderr, "Usage: %s <map_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    t_game game;
    game.map = create_map(argv[1]);
    if (!game.map)
    {
        ft_printf(stderr, "Failed to create map\n");
        return EXIT_FAILURE;
    }

    // Inicializa MLX42
    game.mlx = mlx_init(WIDTH, HEIGHT, "Texture Example", true);
    if (!game.mlx)
    {
        ft_printf(stderr, "Failed to initialize MLX42\n");
        free_map(game.map);
        return EXIT_FAILURE;
    }

    // Carga las imágenes
    game.images.wall_img = load_png(game.mlx, WALL_SRC);
    game.images.floor_img = load_png(game.mlx, FLOOR_SRC);
   //game.images.player_img = load_png(game.mlx, PLAYER_SRC);
    game.images.exit_img = load_png(game.mlx, EXIT_SRC);
    game.images.collectible_img = load_png(game.mlx, COLLECTIBLE_SRC);

    // Verifica si las imágenes se cargaron correctamente
    if (!game.images.wall_img || !game.images.floor_img || !game.images.player_img ||
        !game.images.exit_img || !game.images.collectible_img)
    {
        fprintf(stderr, "Failed to load one or more images\n");
        
        // Limpieza de imágenes cargadas
        if (game.images.wall_img) mlx_delete_image(game.mlx, game.images.wall_img);
        if (game.images.floor_img) mlx_delete_image(game.mlx, game.images.floor_img);
        //if (game.images.player_img) mlx_delete_image(game.mlx, game.images.player_img);
        if (game.images.exit_img) mlx_delete_image(game.mlx, game.images.exit_img);
        if (game.images.collectible_img) mlx_delete_image(game.mlx, game.images.collectible_img);

        mlx_terminate(game.mlx);
        free_map(game.map);
        return EXIT_FAILURE;
    }

    // Renderiza el mapa
    render_map(&game);

    // Inicia el bucle de MLX42
    mlx_loop(game.mlx);

    // Limpia
    mlx_delete_image(game.mlx, game.images.wall_img);
    mlx_delete_image(game.mlx, game.images.floor_img);
    //mlx_delete_image(game.mlx, game.images.player_img);
    mlx_delete_image(game.mlx, game.images.exit_img);
    mlx_delete_image(game.mlx, game.images.collectible_img);
    mlx_terminate(game.mlx);

    free_map(game.map);

    return EXIT_SUCCESS;
}


    // int32_t main(int argc, char **argv)
// {
//     if (argc != 2)
//     {
//         ft_printf(stderr, "Usage: %s <map_file>\n", argv[0]);
//         return EXIT_FAILURE;
//     }

//     mlx_t *mlx;
//     mlx_image_t *floor_img, *wall_img;
//     char **map;

//     // Initialize MLX
//     mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Vrads testing", true);
//     if (!mlx)
//         error("Failed to initialize MLX");

//     // Load textures
//     floor_img = load_png(mlx, FLOOR_SRC);
//     wall_img = load_png(mlx, WALLS_SRC);

//     // Load map and render it
//     map = create_map(argv[1]);
//     render_map(mlx, floor_img, wall_img, map);

//     // Start the MLX loop
//     mlx_loop(mlx);

//     // Clean up
//     mlx_delete_image(mlx, floor_img);
//     mlx_delete_image(mlx, wall_img);
//     mlx_terminate(mlx);

//     // Free map memory
//     for (int i = 0; map[i] != NULL; i++)
//         free(map[i]);
//     free(map);

//     return EXIT_SUCCESS;
// }

