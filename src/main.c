/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:38:48 by vflorez           #+#    #+#             */
/*   Updated: 2024/08/15 19:53:23 by vflorez          ###   ########.fr       */
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

    for (int i = 0; i < map->height; i++)
    {
        printf("%s", map->grid[i]);
    }
}

int main(int argc, char **argv)
{ 
    t_map *map;
    
    
    if (!check_args(argc, argv))
        return (1);

    map = create_map(argv[1]);
    if (!map)
        return (1);
        
    print_map(map);
    check_map_area(map);
    //check_map_rectangle(map);
    check_wall(map);

    free_map(map);
    
    return (0);
}