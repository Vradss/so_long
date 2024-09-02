/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:32:18 by vflorez           #+#    #+#             */
/*   Updated: 2024/09/02 16:03:17 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    error(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(message, 2);
	exit(1);
}

void free_map(t_map *map)
{
    size_t i;

    if (map->grid)
    {
        for (i = 0; i < map->height; i++)
        {
            free(map->grid[i]);
        }
        free(map->grid);
    }
}