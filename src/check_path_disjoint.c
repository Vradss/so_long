/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_disjoint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradis <vradis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:50:19 by vflorez           #+#    #+#             */
/*   Updated: 2024/09/03 18:01:41 by vradis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	compress_subtrees(t_disjoint_set	*s)
{
	int	i;

	i = 0;
	while (i < s->v_count)
	{
		find_rep(s->rep, i);
		i++;
	}
}

t_disjoint_set	*new_disj_set(t_adjacents *adjacency_map, int element_n)
{
	t_disjoint_set	*s;
	int				i;

	i = 0;
	s = malloc(sizeof(t_disjoint_set));
	if (s)
	{
		s->rep = new_rep_array(element_n);
		s->rank = ft_calloc(element_n, sizeof(int));
		s->v_count = element_n;
		while (i < element_n)
		{
			union_find(s, adjacency_map[i], i);
			i++;
		}
	}
	compress_subtrees(s);
	return (s);
}

t_disjoint_set	*build_disjoint_set(t_aux_map aux_map)
{
	t_adjacents		*adjacency_map;
	t_disjoint_set	*disjoint_set;

	adjacency_map = new_adjacency_map(aux_map);
	disjoint_set = new_disj_set(adjacency_map, aux_map.walkable_tiles_count);
	free(adjacency_map);
	return (disjoint_set);
}

// void	put_disjoint_set(t_disjoint_set *s)
// {
// 	printf("DISJOINT SET\n");
// 	for(int i = 0; i < s->v_count; i++)
// 	{
// 		printf(" [%d] ", s->rep[i]);
// 	}
// 	printf("\n");
// 	printf("RANK\n");
// 	for(int i = 0; i < s->v_count; i++)
// 	{
// 		printf(" [%d] ", s->rank[i]);
// 	}
// 	printf("\n");
// }