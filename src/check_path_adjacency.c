/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_adjacency.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:47:03 by vflorez           #+#    #+#             */
/*   Updated: 2024/09/04 10:49:00 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	walkable_tiles(int **grid, int width, int height)
{
	int	n;
	int	i;
	int	j;

	n = 0;
	i = 0;
	j = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (grid[i][j] != -1)
				n++;
			j++;
		}
		i++;
	}
	return (n);
}

int	is_walkable(int square)
{
	return (square != -1);
}

void	mark_relations(t_adjacents *a, t_aux_map m, int i, int j)
{
	int	k;

	k = 0;
	while (k < 4)
		(*a)[k++] = -1;
	if (m.grid[i][maximum(j - 1, 0)] != -1)
		(*a)[LEFT] = m.grid[i][maximum(j - 1, 0)];
	if (m.grid[maximum(i - 1, 0)][j] != -1)
		(*a)[TOP] = m.grid[maximum(i - 1, 0)][j];
	if (m.grid[i][minimum(j + 1, m.width)] != -1)
		(*a)[RIGHT] = m.grid[i][minimum(j + 1, m.width)];
	if (m.grid[minimum(i + 1, m.height)][j] != -1)
		(*a)[BOTTOM] = m.grid[minimum(i + 1, m.height)][j];
}

t_adjacents	*new_adjacency_map(t_aux_map m)
{
	t_adjacents	*adjacency_map;
	int			i;
	int			j;
	int			k;

	adjacency_map = malloc(sizeof(t_adjacents) * m.walkable_tiles_count);
	i = 0;
	j = 0;
	k = 0;
	while (i < m.height)
	{
		j = 0;
		while (j < m.width)
		{
			if (is_walkable(m.grid[i][j]))
			{
				mark_relations(&adjacency_map[k++], m, i, j);
			}
			j++;
		}
		i++;
	}
	return (adjacency_map);
}

int	*new_rep_array(int v_count)
{
	int	*rep;
	int	i;

	i = 0;
	rep = malloc(sizeof(int) * v_count);
	if (rep)
	{
		while (i < v_count)
		{
			rep[i] = i;
			i++;
		}
	}
	return (rep);
}
