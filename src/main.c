/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradis <vradis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:38:48 by vflorez           #+#    #+#             */
/*   Updated: 2024/08/26 13:35:35 by vradis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_vec2  determine_square_coordinates(char **grid, char element)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (grid[i])
    {
        j = 0;
        while (grid[i][j])
        {
            if (grid[i][j] == element)
                return (vec2(j, i));
            j++;
        }
        i++;
    }
    return (vec2(-1, -1));
}

t_game  initialize_game(t_map *map)
{
    t_game  g;

    g.map = map;
    g.player = determine_square_coordinates(map->grid, 'P');
    return g;
}

// int main(int argc, char **argv)
// { 
//     t_map   map;
//     t_game  game;
//     mlx_t *mlx;

//     mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Vrads", false);
//     if (!mlx)
//         error ("Faile to initialize");

//     if (!check_args(argc, argv)) {
//         return (1);
//     }
    
//     printf("Comenzando el programa...\n");
    
//     map.grid = create_map(argv[1]);
//     if (!map.grid) {
//         printf("Error al crear el mapa\n");
//         return (1);
//     }
//     //parsing(&map);
//     game = initialize_game(&map);
    
//     init_textures(&game, mlx);
//     render_map(&game, mlx);

//     //check_path_TESTING(&game);

//     mlx_loop(mlx);
//     printf("Liberando el mapa...\n");
//     free_map(&map);
//     free_textures(&game, mlx);
    
//     printf("Finalizando el programa...\n");
//     mlx_terminate(mlx);
//     return (0);
// }
