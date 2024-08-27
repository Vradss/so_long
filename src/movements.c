/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:24:14 by vradis            #+#    #+#             */
/*   Updated: 2024/08/27 19:54:44 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


// //move player
// void    move_player(t_game *game, int dx, int dy)
// {
    
// }

// //directions
// void key_hook(mlx_key_data_t keydata, void *param)
// {
//     t_game *game;

//     game = (t_game *)param;

//     if(keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
//         move_player(game, game->player.x, game->player.y - 1); //up
//     if(keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
//         move_player(game, game->player.x, game->player.y + 1); //down
//     if(keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
//         move_player(game, game->player.x - 1, game->player.y); //left
//     if(keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
//         move_player(game, game->player.x + 1, game->player.y); //right
//     if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
//     {
//         mlx_terminate(game->mlx);
//         exit(0);
//     }    
//     render_map(game);
// }

void move_player(t_game *game, int dx, int dy)
{
    size_t new_x = game->player.x + dx;
    size_t new_y = game->player.y + dy;

        char new_tile = game->map->grid[new_y][new_x];

        // Comprobar que no es una pared
        if (new_tile != '1')
        {
            // Actualizar la posición en la cuadrícula
            game->map->grid[game->player.y][game->player.x] = '0';  // Antiguo lugar ahora vacío
            game->map->grid[new_y][new_x] = 'P';  // Nuevo lugar con el jugador

            // Actualizar la posición del jugador en el struct
            game->player.x = new_x;
            game->player.y = new_y;

            // Actualizar la posición gráfica usando TILE_SIZE
            game->images.player_img->instances[0].x = new_x * TILE_SIZE;
            game->images.player_img->instances[0].y = new_y * TILE_SIZE;

            // Manejar otros elementos como coleccionables o la salida
            if (new_tile == 'C')
            {
                // Recoger coleccionable, reducir su cantidad
                game->map->collectable--;
            }
            else if (new_tile == 'E' && game->map->collectable == 0)
            {
                // Si no quedan coleccionables y el jugador llega a la salida
                printf("¡Has ganado!\n");
                exit(0);
            }

            // Incrementar el contador de pasos
            // game->player.steps++;
            // printf("Pasos: %d\n", game->player.steps);
        }
}


void handle_input(mlx_key_data_t keydata, void *param)
{
    t_game *game = (t_game *)param;

    if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
        move_player(game, 0, -1);  // Mover hacia arriba
    else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
        move_player(game, 0, 1);  // Mover hacia abajo
    else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
        move_player(game, -1, 0);  // Mover hacia la izquierda
    else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
        move_player(game, 1, 0);  // Mover hacia la derecha
    else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        exit(0);  // Salir del juego
}