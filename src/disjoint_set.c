/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disjoint_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradis <vradis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:50:21 by vradis            #+#    #+#             */
/*   Updated: 2024/08/17 20:37:00 by vradis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
    
    p = (u.x == v.x && u.y == v.y)
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
int (t_map *map)
{
  //union find and check wether things are accessible   
}