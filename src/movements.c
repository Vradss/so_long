/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:24:14 by vradis            #+#    #+#             */
/*   Updated: 2024/09/01 19:51:24 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// void move_player(t_game *game, int dx, int dy)
// {
//     size_t new_x = game->player.x + dx;
//     size_t new_y = game->player.y + dy;

//     if (new_x < game->map->width && new_y < game->map->height)
//     {
//         char new_tile = game->map->grid[new_y][new_x];

//         if (new_tile != '1')
//         {

//             if (new_tile == 'C')
//             {
//                 game->map->collectable--;
//                 printf("Coleccionables restantes: %d\n", game->map->collectable);
//             }

//             // Actualizar la posición en la cuadrícula
//             game->map->grid[game->player.y][game->player.x] = '0';  // Antiguo lugar ahora vacío
//             game->map->grid[new_y][new_x] = 'P';  // Nuevo lugar con el jugador

//             // Actualizar la posición del jugador en el struct
//             game->player.x = new_x;
//             game->player.y = new_y;

//             // Actualizar la posición gráfica usando TILE_SIZE
//             game->images.player_img->instances[0].x = new_x * TILE_SIZE;
//             game->images.player_img->instances[0].y = new_y * TILE_SIZE;

//             if (new_tile == 'E' && game->map->collectable == 0)
//             {
//                 // Si no quedan coleccionables y el jugador llega a la salida
//                 printf("¡Has ganado!\n");
//                 exit(0);
//             }
//             // Incrementar el contador de pasos
//             game->steps++;
//             printf("Pasos: %d\n", game->steps);

//         }
//     printf("new_tail %c\n", new_tile);

//     }
// }

void move_player_left(t_game *game, int dx, int dy)
{
    size_t new_x;
    size_t new_y;
    
    new_x= game->player.x + dx;
    new_y = game->player.y + dy;

    if (new_x < game->map->width && new_y < game->map->height && game->map->grid[new_y][new_x] != '1')
    {
            if (game->map->grid[new_y][new_x] == 'C')
            {
                game->map->collectable--;
                game->map->grid[new_y][new_x] = '0';
                printf("Coleccionables restantes: %d\n", game->map->collectable);
            }
            if (game->map->grid[game->player.y][game->player.x] != 'E')
                mlx_image_to_window(game->mlx, game->images.floor_img, ((game->player.x) * TILE_SIZE), (game->player.y* TILE_SIZE));
            else
                mlx_image_to_window(game->mlx, game->images.exit_img, game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
            
            //mlx_image_to_window(game->mlx, game->images.floor_img, ((game->player.x - 1) * TILE_SIZE), (game->player.y* TILE_SIZE));
            mlx_image_to_window(game->mlx, game->images.player_img, ((game->player.x-1) * TILE_SIZE), (game->player.y* TILE_SIZE));
            game->player.x = new_x;
            game->player.y = new_y;
            if (game->map->grid[new_y][new_x] == 'E' && game->map->collectable == 0)
            {
                printf("¡Has ganado!\n");
                exit(0);
            }
            game->steps++;
            printf("Pasos: %d\n", game->steps);
    }
}

void move_player_right(t_game *game, int dx, int dy)
{
    size_t new_x;
    size_t new_y;
    
    new_x= game->player.x + dx;
    new_y = game->player.y + dy;

    if (new_x < game->map->width && new_y < game->map->height && game->map->grid[new_y][new_x] != '1')
    {
            if (game->map->grid[new_y][new_x] == 'C')
            {
                game->map->collectable--;
                game->map->grid[new_y][new_x] = '0';
                printf("Coleccionables restantes: %d\n", game->map->collectable);
            }
            if (game->map->grid[game->player.y][game->player.x] != 'E')
                mlx_image_to_window(game->mlx, game->images.floor_img, ((game->player.x) * TILE_SIZE), (game->player.y* TILE_SIZE));
            else
                mlx_image_to_window(game->mlx, game->images.exit_img, game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
                
            //mlx_image_to_window(game->mlx, game->images.floor_img, ((game->player.x + 1) * TILE_SIZE), ((game->player.y)* TILE_SIZE));
            mlx_image_to_window(game->mlx, game->images.player_img, ((game->player.x + 1) * TILE_SIZE), ((game->player.y)* TILE_SIZE));
            game->player.x = new_x;
            game->player.y = new_y;
            if (game->map->grid[new_y][new_x] == 'E' && game->map->collectable == 0)
            {
                printf("¡Has ganado!\n");
                exit(0);
            }
            game->steps++;
            printf("Pasos: %d\n", game->steps);
    }
}

void move_player_up(t_game *game, int dx, int dy)
{
    size_t new_x;
    size_t new_y;
    
    new_x= game->player.x + dx;
    new_y = game->player.y + dy;

    if (new_x < game->map->width && new_y < game->map->height && game->map->grid[new_y][new_x] != '1')
    {
            if (game->map->grid[new_y][new_x] == 'C')
            {
                game->map->collectable--;
                game->map->grid[new_y][new_x] = '0';
                printf("Coleccionables restantes: %d\n", game->map->collectable);
            }
            if (game->map->grid[game->player.y][game->player.x] != 'E')
                mlx_image_to_window(game->mlx, game->images.floor_img, ((game->player.x) * TILE_SIZE), (game->player.y* TILE_SIZE));
            else
                mlx_image_to_window(game->mlx, game->images.exit_img, game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
                
            //mlx_image_to_window(game->mlx, game->images.floor_img, ((game->player.x ) * TILE_SIZE), ((game->player.y-1)* TILE_SIZE));
            mlx_image_to_window(game->mlx, game->images.player_img, ((game->player.x ) * TILE_SIZE), ((game->player.y-1)* TILE_SIZE));
            game->player.x = new_x;
            game->player.y = new_y;
            if (game->map->grid[new_y][new_x] == 'E' && game->map->collectable == 0)
            {
                printf("¡Has ganado!\n");
                exit(0);
            }
            game->steps++;
            printf("Pasos: %d\n", game->steps);
    }
}

void move_player_down(t_game *game, int dx, int dy)
{
    size_t new_x;
    size_t new_y;
    
    new_x= game->player.x + dx;
    new_y = game->player.y + dy;

    if (new_x < game->map->width && new_y < game->map->height && game->map->grid[new_y][new_x] != '1')
    {
            if (game->map->grid[new_y][new_x] == 'C')
            {
                game->map->collectable--;
                game->map->grid[new_y][new_x] = '0';
                printf("Coleccionables restantes: %d\n", game->map->collectable);
            }
            if (game->map->grid[game->player.y][game->player.x] != 'E')
                mlx_image_to_window(game->mlx, game->images.floor_img, ((game->player.x) * TILE_SIZE), (game->player.y* TILE_SIZE));
            else
                mlx_image_to_window(game->mlx, game->images.exit_img, game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
                
            //mlx_image_to_window(game->mlx, game->images.floor_img, ((game->player.x ) * TILE_SIZE), ((game->player.y+1)* TILE_SIZE));
            mlx_image_to_window(game->mlx, game->images.player_img, ((game->player.x ) * TILE_SIZE), ((game->player.y+1)* TILE_SIZE));
            game->player.x = new_x;
            game->player.y = new_y;
            if (game->map->grid[new_y][new_x] == 'E' && game->map->collectable == 0)
            {
                printf("¡Has ganado!\n");
                exit(0);
            }
            game->steps++;
            printf("Pasos: %d\n", game->steps);
    }
}

void handle_input(mlx_key_data_t keydata, void *param)
{
    t_game *game = (t_game *)param;
    if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
    {
        if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP))
            move_player_up(game, 0, -1);
        else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN))
            move_player_down(game, 0, 1);
        else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT))
            move_player_left(game, -1, 0);
        else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT))
            move_player_right(game, 1, 0);
        else if (keydata.key == MLX_KEY_ESCAPE)
            exit(0);   
    }
}