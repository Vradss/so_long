/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:38:48 by vflorez           #+#    #+#             */
/*   Updated: 2024/09/02 18:06:46 by vflorez          ###   ########.fr       */
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
    g.exit = determine_square_coordinates(map->grid, 'E');
    g.collectibles = collectibles(map->grid, map->collectable); 
    return g;
}


int main(int argc, char **argv)
{
    t_game game;
    game.steps = 0;
    
    if (!check_args(argc, argv)) 
        return (1);
    
    printf("Comenzando el programa...\n");
    
    game.map = create_map(argv[1]);
    if (!game.map)
        error("Failed to load map");
    
    int width = game.map->width * TILE_SIZE;
    int height = game.map->height * TILE_SIZE;
    
    parsing(game.map);
    game = initialize_game(game.map);
    ft_printf("DIVIDER\n");
    check_path_TESTING(&game);
    check_path_validity(&game);
    game.mlx = mlx_init(width, height, "Vrads testing", false);
    if (!game.mlx)
        error("Failed to initialize MLX");
    

    load_textures(&game);
    render_map(&game);
    mlx_key_hook(game.mlx, &handle_input, &game);
    mlx_loop(game.mlx);
   // cleanup_images(&game);
    
    ft_printf("Finalizando el programa...\n");
    mlx_terminate(game.mlx);
    free_map(game.map);
    return EXIT_SUCCESS;
}
