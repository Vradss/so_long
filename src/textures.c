/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:28:38 by vradis            #+#    #+#             */
/*   Updated: 2024/08/28 18:27:06 by vflorez          ###   ########.fr       */
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
            if (game->map->grid[y][x] != 'P')
                render_tile(game, y, x);
            x++;
        }
        y++;
    }
    render_player(game);
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
}
void render_player(t_game *game)
{
    int player_x;
    int player_y;
    
    player_x = game->player.x * TILE_SIZE;
    player_y = game->player.y * TILE_SIZE;
    mlx_image_to_window(game->mlx, game->images.player_img, player_x, player_y);
    
}
void cleanup_images(t_game *game)
{
    if (game->images.floor_img)
        mlx_delete_image(game->mlx, game->images.floor_img);
    if (game->images.wall_img)
        mlx_delete_image(game->mlx, game->images.wall_img);
    if (game->images.coll_img)
        mlx_delete_image(game->mlx, game->images.coll_img);
    if (game->images.exit_img)
        mlx_delete_image(game->mlx, game->images.exit_img);
    if (game->images.player_img)
        mlx_delete_image(game->mlx, game->images.player_img);
}


void load_textures(t_game *game)
{
    game->images.floor_img = load_png(game->mlx, FLOOR_SRC);
    game->images.wall_img = load_png(game->mlx, WALLS_SRC);
    game->images.coll_img = load_png(game->mlx, COLLECT_SRC);
    game->images.exit_img = load_png(game->mlx, EXIT_SRC);
    game->images.player_img = load_png(game->mlx, PLAYER_SRC);
    
    if (!game->images.floor_img || !game->images.wall_img || !game->images.coll_img || 
        !game->images.exit_img || !game->images.player_img)
    {
        error("Failed to load one or more images");
    }
}
