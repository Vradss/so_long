/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_collec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradis <vradis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:24:56 by vflorez           #+#    #+#             */
/*   Updated: 2024/09/03 18:15:42 by vradis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_vec2	*collectibles(char **grid, int count)
{
	t_vec2	*collectibles;
	int		i;
	int		j;
	int		n;

	collectibles = malloc(sizeof(t_vec2) * count);
	if (!collectibles)
		return (NULL);
	i = 0;
	j = 0;
	n = 0;
	while (n < count && grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == 'C')
				collectibles[n++] = vec2(j, i);
			j++;
		}
		i++;
	}
	return (collectibles);
}

void	check_collec(t_aux_map *m, t_disjoint_set *s, t_game *g, int target_rep)
{
	int	collect;
	int	i;

	i = 0;
	collect = m->grid[g->collectibles[0].y][g->collectibles[0].x];
	//put_collectibles(g->collectibles, g->map->collectable);
	while (i < g->map->collectable)
	{
		if (s->rep[collect] == target_rep)
		{
			collect = m->grid[g->collectibles[i].y][g->collectibles[i].x];
			i++;
		}
		else
		{
			error("You can't reach all collectibles");
		}
	}
}

// void	put_collectibles(t_vec2 *c, int n)
// {
// 	printf("COLLECTIBLES\n");
// 	for(int i = 0; i < n; i++)
// 	{
// 		printf(" [%d, %d] ", c[i].x, c[i].y);
// 	}
// 	printf("\n");
// }