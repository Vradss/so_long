/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:28:38 by vradis            #+#    #+#             */
/*   Updated: 2024/08/26 20:05:55 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
            render_tile(game, y, x);
            x++;
        }
        y++;
    }
}

void render_tile(t_game *game, size_t y, size_t x)
{
    int tile_x;
    int tile_y;
    char tile;
    
    tile_x = x * TILE_SIZE;
    tile_y = y * TILE_SIZE;
    tile = game->map->grid[y][x];
    
    if (tile == '1')
        mlx_image_to_window(game->mlx, game->images.wall_img, tile_x, tile_y);
    else if (tile == '0')
        mlx_image_to_window(game->mlx, game->images.floor_img, tile_x, tile_y);
    else if (tile == 'C')
        mlx_image_to_window(game->mlx, game->images.coll_img, tile_x, tile_y);
    else if (tile == 'E')
        mlx_image_to_window(game->mlx, game->images.exit_img, tile_x, tile_y);
    else if (tile == 'P')
        mlx_image_to_window(game->mlx, game->images.player_img, tile_x, tile_y);
}
void cleanup_images(t_game game)
{
    if (game.images.floor_img)
        mlx_delete_image(game.mlx, game.images.floor_img);
    if (game.images.wall_img)
        mlx_delete_image(game.mlx, game.images.wall_img);
    if (game.images.coll_img)
        mlx_delete_image(game.mlx, game.images.coll_img);
    if (game.images.exit_img)
        mlx_delete_image(game.mlx, game.images.exit_img);
    if (game.images.player_img)
        mlx_delete_image(game.mlx, game.images.player_img);
}

int main(int argc, char **argv)
{

    if (argc != 2)
    {
        error("Usage: ./text2 map.ber");
        return EXIT_FAILURE;
    }

    t_game game;
    
    game.map = create_map(argv[1]);
    if (!game.map)
        error("Failed to load map");

        
    int width =game.map->width * TILE_SIZE;
    int height = game.map->height * TILE_SIZE;

    
    game.mlx = mlx_init(width, height, "Vrads testing", true);
    if (!game.mlx)
        error("Failed to initialize MLX");

    game.images.floor_img = load_png(game.mlx, FLOOR_SRC);
    game.images.wall_img = load_png(game.mlx, WALLS_SRC);
    game.images.coll_img = load_png(game.mlx, COLLECT_SRC);
    game.images.exit_img = load_png(game.mlx, EXIT_SRC);
    game.images.player_img = load_png(game.mlx, PLAYER_SRC);

    render_map(&game);
    mlx_loop(game.mlx);
    cleanup_images(game);
    mlx_terminate(game.mlx);
    free_map(game.map);

    return EXIT_SUCCESS;
}
