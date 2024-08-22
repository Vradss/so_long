/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradis <vradis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:38:48 by vflorez           #+#    #+#             */
/*   Updated: 2024/08/21 12:19:41 by vradis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void print_map(t_map *map)
{
    if (!map || !map->grid)
    {
        printf("El mapa no está inicializado o es nulo.\n");
        return;
    }
   // ft_printf("Número de filas: %d\n", map->height);
    //ft_printf("Número de columnas: %d\n", map->width);
    
    for (size_t i = 0; i < map->height; i++)
    {
        printf("%s\n", map->grid[i]);
    }
}

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
    return (g);
}

int main(int argc, char **argv)
{ 
    t_map   map;
    t_game  game;

    printf("Comenzando el programa...\n");
    
    if (!check_args(argc, argv)) {
        printf("Argumentos inválidos\n");
        return (1);
    }
    
    map.grid = create_map(argv[1]);
    if (!map.grid) {
        printf("Error al crear el mapa\n");
        return (1);
    }
    parsing(&map);
    game = initialize_game(&map);
    check_path_TESTING(&game);
    printf("Liberando el mapa...\n");
    //free_map(&map);
    
    printf("Finalizando el programa...\n");
    return (0);
}
