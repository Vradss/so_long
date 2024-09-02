/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:23:44 by vflorez           #+#    #+#             */
/*   Updated: 2024/08/26 19:48:01 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int read_map(char *map)
{
    int fd;
    char *row_num;
    int i;
    
    i = 0;
    fd = open(map, O_RDONLY);
    if (fd < 0)
        error("Error al abrir el archivo");  
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

t_map *create_map(char *file)
{
    int fd;
    char *row;
    int i;
    t_map *map;

    // Reservar memoria para la estructura t_map
    map = malloc(sizeof(t_map));
    if (!map)
        error("Memory allocation failed");

    i = 0;
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

    // Asignar las dimensiones del mapa
    map->height = i;
    map->width = ft_strlen(map->grid[0]);

    // Imprimir el mapa para verificar si se guardó correctamente
    i = 0;
    while (map->grid[i] != NULL)
    {
        printf("%s\n", map->grid[i]);
        i++;
    }

    return map;
}

