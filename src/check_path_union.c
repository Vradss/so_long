/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_union.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:49:33 by vflorez           #+#    #+#             */
/*   Updated: 2024/09/02 20:57:05 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	find_rep(int *rep, int element)
{
	if (rep[element] == element)
		return (rep[element]);
	rep[element] = rep[rep[element]];
	return (find_rep(rep, rep[element]));
}

void	set_union(t_disjoint_set *s, int adjacent_element, int cur_element)
{
	int	m;
	int	n;

	m = find_rep(s->rep, cur_element);
	n = find_rep(s->rep, adjacent_element);
	if (s->rank[m] < s->rank[n])
	{
		s->rep[m] = n;
		s->rank[n]++;
	}
	else
	{
		s->rep[n] = m;
		s->rank[m]++;
	}
}

void	union_find(t_disjoint_set *s, t_adjacents relations, int cur_element)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (relations[i] != -1)
		{
			set_union(s, relations[i], cur_element);
		}
		i++;
	}
}
