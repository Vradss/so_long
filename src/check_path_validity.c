/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_validity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:37:49 by vflorez           #+#    #+#             */
/*   Updated: 2024/09/04 12:04:19 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_aux_map	auxiliary_map(char **grid, int width, int height)
{
	t_aux_map	m;
	int			i;
	int			j;

	m.grid = malloc(sizeof(int *) * height);
	i = 0;
	j = 0;
	m.walkable_tiles_count = 0;
	while (i < height)
	{
		j = 0;
		m.grid[i] = malloc(sizeof(int) * width);
		while (j < width)
		{
			m.grid[i][j] = -1;
			if (grid[i][j] != '1')
				m.grid[i][j] = m.walkable_tiles_count++;
			j++;
		}
		i++;
	}
	m.width = width;
	m.height = height;
	return (m);
}

void	check_path_validity(t_game *game)
{
	t_disjoint_set	*disjoint_set;
	t_aux_map		aux_map;

	aux_map = auxiliary_map(game->map->grid, game->map->width, \
	game->map->height);
	disjoint_set = build_disjoint_set(aux_map);
	check_rep(&aux_map, disjoint_set, game);
	free_aux_map(&aux_map);
	free_disjoint_set(disjoint_set);
}

void	check_rep(t_aux_map *a, t_disjoint_set *s, t_game *game)
{
	int	player;
	int	exit;

	player = a->grid[game->player.y][game->player.x];
	exit = a->grid[game->exit.y][game->exit.x];
	if (s->rep[player] == s->rep[exit])
	{
		check_collec(a, s, game, s->rep[player]);
	}
	else
	{
		error("Player and exit dont have the same rep");
	}
}

// void    check_path_TESTING(t_game *game)
// {
// 	t_aux_map aux_map;
// 	t_adjacents		*adjacency_map;
// 	t_disjoint_set	*disjoint_set;

// 	printf("pos player(%d, %d)\n",game->player.x, game->player.y);
// 	printf("pos exit(%d, %d)\n",game->exit.x, game->exit.y);
// 	put_collectibles(collectibles(game->map->grid, game->map->collectable), game->map->collectable);
// 	aux_map = auxiliary_map(game->map->grid, game->map->width, game->map->height);
// 	adjacency_map = new_adjacency_map(aux_map);
// 	disjoint_set = new_disjoint_set(adjacency_map, aux_map.walkable_tiles_count);
// 	put_aux_map(aux_map.grid, aux_map.width, aux_map.height);
// 	put_adjacency_map(adjacency_map, aux_map.walkable_tiles_count);
// 	put_disjoint_set(disjoint_set);
// }

// void put_aux_map(int**m, int width, int height)
// {
// 	printf("AUX MAP\n");
// 	for(int y = 0; y < height; y++)
// 	{
// 		for(int x = 0; x < width; x++)
// 		{
// 			if (m[y][x] == -1)
// 				printf("  %c", 'W');
// 			else
// 				printf("%3d", m[y][x]);
// 		}
// 		printf("\n");
// 		printf("\n");
// 	}
// }