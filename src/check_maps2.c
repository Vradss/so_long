/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:48:55 by vflorez           #+#    #+#             */
/*   Updated: 2024/09/04 12:47:48 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//This function checks number of rows , existe un numero min de filas?

size_t	map_height(char **map)
{
	size_t	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

//This function checks lenght of the map
size_t	map_width(char **map)
{
	int		i;
	size_t	len;
	size_t	len2;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		len2 = ft_strlen(map[i]);
		if (len != len2)
			error("Differentes lenghts in the map");
		i++;
	}
	return (len);
}

void	parsing(t_map *map)
{
	if (!map->height)
		error("Map is empty");
	map->width = map_width(map->grid);
	map->height = map_height(map->grid);
	check_map_area(map);
	check_map_char(map);
	check_map_rectangle(map);
	check_wall(map);
}
