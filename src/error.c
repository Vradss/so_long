/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradis <vradis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:32:18 by vflorez           #+#    #+#             */
/*   Updated: 2024/08/27 11:02:46 by vradis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    error(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(message, 2);
	exit(1);
}

// void free_textures(t_game *game, mlx_t *mlx)
// {
//     if (game->wall_img)
//     {
//         mlx_delete_image(mlx, game->wall_img);
//         game->wall_img = NULL;
//     }
// }

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