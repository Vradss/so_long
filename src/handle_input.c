/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:18:30 by vflorez           #+#    #+#             */
/*   Updated: 2024/09/02 19:18:45 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	handle_input(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP))
			move_player_up(game, 0, -1);
		else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN))
			move_player_down(game, 0, 1);
		else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT))
			move_player_left(game, -1, 0);
		else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT))
			move_player_right(game, 1, 0);
		else if (keydata.key == MLX_KEY_ESCAPE)
			exit(0);
	}
}
