/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:24:25 by vflorez           #+#    #+#             */
/*   Updated: 2024/08/14 22:23:40 by vflorez          ###   ########.fr       */
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


void check_map_area(char *map)
{
    int player;
    int exit;
    int collectable;
    int i;
    
    player = 0;
    exit = 0;
    collectable = 0;
    i = 0;
    
    while (map[i])
    {
        if (map[i] == 'P')
            player++;
        else if (map[i] == 'E')
            exit++;
        else if (map[i] == 'C')
            collectable++;
        else if (map[i] != '0' && map[i] != '1' && map[i] != '\n')
            check_invalid_char(map[i]);
        i++;
    }
    if (player != 1 || exit != 1 || collectable < 1)
        error("Map content is not valid");
}

//This function checks if the map is rectangle

void    check_map_rectangle(char **map)
{
    int i;
    int len;
    
    i = 0;
    len = ft_strlen(map[i]);
    while (map[i])
    {
        if (len != ft_strlen(map[i]))
            error("Map is not rectangle");
        i++;
    }
}

//This function verifies the walls horizontal and vertical

void check_