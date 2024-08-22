/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradis <vradis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:33:01 by vradis            #+#    #+#             */
/*   Updated: 2024/08/22 14:59:29 by vradis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    init_images(t_game *game)
{
    game->wall_img = mlx_load_png("../images/bush_wall.png");
    game->collec_img = mlx_load_png("../images/collect.png");

    game->player.image = mlx_load_png("../images/homer_player.png");
}