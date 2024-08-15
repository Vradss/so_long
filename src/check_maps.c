/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:24:25 by vflorez           #+#    #+#             */
/*   Updated: 2024/08/15 19:48:08 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//This functions checks: 
// 1. Verify that there is one player (P)
// 2. Verify that there is one exit (E)
// 3. Verify that there is at least one collectible (C)
// 4. Make sure there are no invalid characters on the map.

void check_invalid_char(int c)
{
    if (!(ft_strchr("01PEC\n", c)))
        error("Invalid character in map");
}

void check_map_area(t_map *map)
{
    int x;
    int y;

    map->player = 0;
    map->exit = 0;
    map->collectable = 0;
    x = 0;
    y = 0;
    
    while (x < map->height)
    {
        while (y < map->width)
        {
            if (map->grid[x][y] == 'P')
                map->player++;
            else if (map->grid[x][y] == 'E')
                map->exit++;
            else if (map->grid[x][y] == 'C')
                map->collectable++;
            else if (map->grid[x][y] != '0' && map->grid[x][y] != '1' && map->grid[x][y] != '\n')
                check_invalid_char(map->grid[x][y]);
            y++;
        }
        x++;
    }
}

void check_map_char(t_map *map)
{
    map->player = 0;
    map->exit = 0;
    map->collectable = 0;

    if (map->player != 1 || map->exit != 1 || map->collectable < 1)
        error("Map content is not valid");
}
        
//This function checks if the map is rectangle

// void    check_map_rectangle(t_map *map)
// {
//     size_t i;
//     size_t len;
    
//     i = 0;
//     len = ft_strlen(map->grid[i]);
//     while (map->grid[i])
//     {
//         if (len != ft_strlen(map->grid[i]))
//             error("Map is not rectangle");
//         i++;
//     }pwd
// }

//These functions verifies the walls horizontal and vertical

void check_wall(t_map *map)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    while (x < map->width)
    {
        if (map->grid[0][x] != '1' || map->grid[map->height - 1][x] != '1')
            error("Wall error");
        x++;
    }
    while (y < map->height)
    {
        if (map->grid[y][0] != '1' || map->grid[y][map->width - 1] != '1')
            error("Wall error");
        y++;
    }
}

