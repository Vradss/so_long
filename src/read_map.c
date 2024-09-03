/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradis <vradis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:23:44 by vflorez           #+#    #+#             */
/*   Updated: 2024/09/03 17:46:34 by vradis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	read_map(char *map)
{
	int		fd;
	char	*row_num;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		error("Problem opening the file");
	row_num = get_next_line(fd);
	while (row_num != NULL)
	{
		free(row_num);
		row_num = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

t_map	*create_map(char *file)
{
	int		fd;
	char	*row;
	int		i;
	t_map	*map;

	map = malloc(sizeof(t_map));
	i = 0;
	if (!map)
		error("Memory allocation failed");
	map->grid = ft_calloc(read_map(file) + 1, sizeof(char *));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("File error");
	row = get_next_line(fd);
	while (row != NULL)
	{
		map->grid[i] = ft_strtrim(row, "\n \t\f\v\r");
		row = get_next_line(fd);
		i++;
	}
	map->grid[i] = NULL;
	close(fd);
	map->height = i;
	map->width = ft_strlen(map->grid[0]);
	return (map);
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->grid[i] != NULL)
	{
		printf("%s\n", map->grid[i]);
		i++;
	}
}
