/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:32:18 by vflorez           #+#    #+#             */
/*   Updated: 2024/09/04 21:48:12 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(message, 2);
	exit(1);
}

void	free_map(t_map *map)
{
	size_t	i;

	if (map->grid)
	{
		i = 0;
		while (i < map->height)
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	free(map);
}

void	success(char *message)
{
	ft_putendl_fd(message, 1);
	exit(0);
}

void	free_disjoint_set(t_disjoint_set *s)
{
	if (s)
	{
		if (s->rep)
		{
			free(s->rep);
			s->rep = NULL;
		}
		if (s->rank)
		{
			free(s->rank);
			s->rank = NULL;
		}
		free(s);
		s = NULL;
	}
}

void	free_aux_map(t_aux_map *m)
{
	int	i;

	if (m->grid)
	{
		i = 0;
		while (i < m->height)
		{
			free(m->grid[i]);
			i++;
		}
		free(m->grid);
	}
}
