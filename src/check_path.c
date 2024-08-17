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

int **auxilliary_map(char **grid, int width, int height)
{
    int **m;
    int i;
    int j;
    int new_index;
    
    m = malloc(sizeof(int *) * height);
    i = 0;
    j = 0;
    new_index = 0;
    while (i < height)
    {
        j = 0;
        m[i] = malloc(sizeof(int) * width);
        while( j < width)
        {
            m[i][j] = -1;
            if (grid[i][j] != '1')
                m[i][j] = new_index++;       
            j++;
        }
        i++;
    }
    printf("AUX MAP\n");
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            printf("%d", m[y][x]);
        }
        printf("\n");
    }
    return (m);
}

int walkable_tiles(int **auxilliary_map, int width, int height)
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
            if (auxilliary_map[i][j] != -1)
                n++;
            j++;
        }
        i++;
    }
    return (n);
}

int **adjacency_map(int **auxilliary_map, int width, int height)
{
    int **m;
    
    m =  malloc(sizeof(int *) * walkable_tiles(auxilliary_map, width, height));
    return (m);
}

 //disjoint_set(int **adjacency_map, int rep_count)
 //{
 //    ///+      
 //}


void    check_path_TESTING(t_game *game)
{
    printf("pos(%d, %d)\n",game->player.x, game->player.y);
    auxilliary_map(game->map->grid, game->map->width, game->map->height);
}