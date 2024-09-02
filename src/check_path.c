/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradis <vradis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:50:21 by vradis            #+#    #+#             */
/*   Updated: 2024/08/17 22:36:52 by vradis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <math.h>

t_vec2 vec2(int x, int y)
{
	t_vec2  u;

	u.x = x;
	u.y = y;
	return (u);
}

int vec2_cmp(t_vec2 u, t_vec2 v)
{
	int p;
	
	p = (u.x == v.x && u.y == v.y);
	return (p);
}

t_vec2  *collectibles(char **grid, int count)
{
	t_vec2  *collectibles;
	int i;
	int j;
	int n;

	collectibles = malloc(sizeof(t_vec2) * count);
	if (!collectibles)
		return (NULL);
	i = 0;
	j = 0;
	n = 0;
	while (n < count && grid[i++])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == 'C')
				collectibles[n++] = vec2(j, i);
			j++;
		}
	}
	return (collectibles);
}

int maximum(int a, int b)
{
	int c;

	c = a;
	if ( a < b)
	{
		c = b;
	}
	return (c);
}

int minimum(int a, int b)
{
	int c;

	c = a;
	if ( a > b)
	{
		c = b;
	}
	return (c);
}

int clamp(int value, int min, int max)
{
	return minimum(maximum(min, value), max);
}

//////////////

typedef struct  s_auxiliary {
	int **grid;
	int width;
	int height;
	int walkable_tiles_count;
}               t_auxiliary_map;

t_auxiliary_map auxiliary_map(char **grid, int width, int height)
{
	t_auxiliary_map m;
	int				i;
	int				j;
	
	m.grid = malloc(sizeof(int *) * height);
	i = 0;
	j = 0;
	m.walkable_tiles_count = 0;
	while (i < height)
	{
		j = 0;
		m.grid[i] = malloc(sizeof(int) * width);
		while( j < width)
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

void put_aux_map(int**m, int width, int height)
{
	printf("AUX MAP\n");
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			if (m[y][x] == -1)
				printf("  %c", 'W');
			else
				printf("%3d", m[y][x]);
		}
		printf("\n");
		printf("\n");
	}
}

typedef int t_adjacents[4];

void put_adjacency_map(t_adjacents *map, int n)
{
	printf("ADJ MAP\n");
	for (int i = 0; i < n; i++)
	{
		printf("[ ");
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("] ");
	}
	printf("\n");
}

int walkable_tiles(int **grid, int width, int height)
{
	int n;
	int i;
	int j;

	n = 0;
	i = 0;
	j = 0;
	while (i < height)
	{
		j = 0;
		while( j < width)
		{
			if (grid[i][j] != -1)
				n++;
			j++;
		}
		i++;
	}
	return (n);
}

int is_walkable(int square)
{
	return (square != -1);
}


enum e_Relations {LEFT, TOP, RIGHT, BOTTOM};

void	mark_relations(t_adjacents *a, t_auxiliary_map m, int i, int j)
{
	int k;

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

t_adjacents *new_adjacency_map(t_auxiliary_map m)
{
	t_adjacents	*adjacency_map;
	int			i;
	int			j;
	int			k;

	adjacency_map = malloc(sizeof(t_adjacents) * m.walkable_tiles_count);
	i = 0;
	j = 0;
	k = 0;
	printf(" h %d w %d\n", m.height,m.width);
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
	int *rep;
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

typedef struct	s_disjoint_set {
	int *rep;
	int	*rank;
	int	v_count;
}				t_disjoint_set;				 

int	find_rep(int * rep, int element)
{

	if (rep[element] == element)
		return rep[element];
	rep[element] = rep[rep[element]];
	return find_rep(rep, rep[element]);
}

void set_union(t_disjoint_set * s, int adjacent_element, int cur_element)
{
	int m;
	int n;

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
	int i;

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

void	put_disjoint_set(t_disjoint_set *s)
{
	printf("DISJOINT SET\n");
	for(int i = 0; i < s->v_count; i++)
	{
		printf(" [%d] ", s->rep[i]);
	}
	printf("\n");
	printf("RANK\n");
	for(int i = 0; i < s->v_count; i++)
	{
		printf(" [%d] ", s->rank[i]);
	}
	printf("\n");
}

void compress_subtrees(t_disjoint_set	*s)
{
	int i = 0;

	while (i < s->v_count)
	{
		find_rep(s->rep, i);
		i++;
	}
}

t_disjoint_set	*new_disjoint_set(t_adjacents *adjacency_map, int element_n)
{
	t_disjoint_set	*s;
	int	i;

	i = 0;
	s = malloc(sizeof(t_disjoint_set));
	if (s)
	{
		s->rep =  new_rep_array(element_n);
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


void    check_path_TESTING(t_game *game)
{
	t_auxiliary_map aux_map;
	t_adjacents		*adjacency_map;
	t_disjoint_set	*disjoint_set;

	printf("pos(%d, %d)\n",game->player.x, game->player.y);
	aux_map = auxiliary_map(game->map->grid, game->map->width, game->map->height);
	adjacency_map = new_adjacency_map(aux_map);
	disjoint_set = new_disjoint_set(adjacency_map, aux_map.walkable_tiles_count);

	put_aux_map(aux_map.grid, aux_map.width, aux_map.height);
	put_adjacency_map(adjacency_map, aux_map.walkable_tiles_count);
	put_disjoint_set(disjoint_set);
}