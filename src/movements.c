/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:24:14 by vradis            #+#    #+#             */
/*   Updated: 2024/09/02 19:19:36 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	decrease_collectible(t_game *game, size_t new_x, size_t new_y)
{
	game->map->collectable--;
	game->map->grid[new_y][new_x] = '0';
	printf("Remaining collectibles: %d\n", game->map->collectable);
}

void	move_player_left(t_game *game, int dx, int dy)
{
	size_t	new_x;
	size_t	new_y;

	new_x = game->player.x + dx;
	new_y = game->player.y + dy;
	if (new_x < game->map->width && new_y < game->map->height \
	&& game->map->grid[new_y][new_x] != '1')
	{
		if (game->map->grid[new_y][new_x] == 'C')
			decrease_collectible(game, new_x, new_y);
		if (game->map->grid[game->player.y][game->player.x] != 'E')
			mlx_image_to_window(game->mlx, game->images.floor_img, \
			((game->player.x) * TILE_SIZE), (game->player.y * TILE_SIZE));
		else
			mlx_image_to_window(game->mlx, game->images.exit_img, \
		game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
		mlx_image_to_window(game->mlx, game->images.player_img, \
		((game->player.x - 1) * TILE_SIZE), (game->player.y * TILE_SIZE));
		game->player.x = new_x;
		game->player.y = new_y;
		if (game->map->grid[new_y][new_x] == 'E' && game->map->collectable == 0)
			success("You help Rick to become a pickle!");
		game->steps++;
		printf("Steps: %d\n", game->steps);
	}
}

void	move_player_right(t_game *game, int dx, int dy)
{
	size_t	new_x;
	size_t	new_y;

	new_x = game->player.x + dx;
	new_y = game->player.y + dy;
	if (new_x < game->map->width && new_y < game->map->height \
	&& game->map->grid[new_y][new_x] != '1')
	{
		if (game->map->grid[new_y][new_x] == 'C')
			decrease_collectible(game, new_x, new_y);
		if (game->map->grid[game->player.y][game->player.x] != 'E')
			mlx_image_to_window(game->mlx, game->images.floor_img, \
			((game->player.x) * TILE_SIZE), (game->player.y * TILE_SIZE));
		else
			mlx_image_to_window(game->mlx, game->images.exit_img, \
		game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
		mlx_image_to_window(game->mlx, game->images.player_img, \
		((game->player.x + 1) * TILE_SIZE), (game->player.y * TILE_SIZE));
		game->player.x = new_x;
		game->player.y = new_y;
		if (game->map->grid[new_y][new_x] == 'E' && game->map->collectable == 0)
			success("You help Rick to become a pickle!");
		game->steps++;
		printf("Steps: %d\n", game->steps);
	}
}

void	move_player_up(t_game *game, int dx, int dy)
{
	size_t	new_x;
	size_t	new_y;

	new_x = game->player.x + dx;
	new_y = game->player.y + dy;
	if (new_x < game->map->width && new_y < game->map->height \
	&& game->map->grid[new_y][new_x] != '1')
	{
		if (game->map->grid[new_y][new_x] == 'C')
			decrease_collectible(game, new_x, new_y);
		if (game->map->grid[game->player.y][game->player.x] != 'E')
			mlx_image_to_window(game->mlx, game->images.floor_img, \
			((game->player.x) * TILE_SIZE), (game->player.y * TILE_SIZE));
		else
			mlx_image_to_window(game->mlx, game->images.exit_img, \
		game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
		mlx_image_to_window(game->mlx, game->images.player_img, \
		((game->player.x) * TILE_SIZE), ((game->player.y - 1) * TILE_SIZE));
		game->player.x = new_x;
		game->player.y = new_y;
		if (game->map->grid[new_y][new_x] == 'E' && game->map->collectable == 0)
			success("You help Rick to become a pickle!");
		game->steps++;
		printf("Steps: %d\n", game->steps);
	}
}

void	move_player_down(t_game *game, int dx, int dy)
{
	size_t	new_x;
	size_t	new_y;

	new_x = game->player.x + dx;
	new_y = game->player.y + dy;
	if (new_x < game->map->width && new_y < game->map->height \
	&& game->map->grid[new_y][new_x] != '1')
	{
		if (game->map->grid[new_y][new_x] == 'C')
			decrease_collectible(game, new_x, new_y);
		if (game->map->grid[game->player.y][game->player.x] != 'E')
			mlx_image_to_window(game->mlx, game->images.floor_img, \
			((game->player.x) * TILE_SIZE), (game->player.y * TILE_SIZE));
		else
			mlx_image_to_window(game->mlx, game->images.exit_img, \
		game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
		mlx_image_to_window(game->mlx, game->images.player_img, \
		((game->player.x) * TILE_SIZE), ((game->player.y + 1) * TILE_SIZE));
		game->player.x = new_x;
		game->player.y = new_y;
		if (game->map->grid[new_y][new_x] == 'E' && game->map->collectable == 0)
			success("You help Rick to become a pickle!");
		game->steps++;
		printf("Steps: %d\n", game->steps);
	}
}
