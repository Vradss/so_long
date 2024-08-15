/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:23:44 by vflorez           #+#    #+#             */
/*   Updated: 2024/08/15 19:53:55 by vflorez          ###   ########.fr       */
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

t_map *create_map(char *file_path)
{
    t_map *map;
    int fd;
    int i;
    char *row;
    
    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
        error("Error al asignar memoria para el mapa");
    map->height = read_map(file_path);
    
    fd = open(file_path, O_RDONLY);
    if (fd < 0)
        error("Error al abrir el archivo");
    
    map->grid = (char **)malloc(sizeof(char *) * map->height);
    if (!map->grid)
    {
        ft_printf("Error al asignar memoria para las filas del mapa\n");
        free_map(map);
        close(fd);
        exit(1);
    }
    i = 0;
    while ((row = get_next_line(fd)) != NULL && i < map->height)
    {
        map->grid[i] = ft_strdup(row); //copiamos la linea al map
        //map->width = ft_strlen(row) -1 ; //guardamos el ancho de la linea
        free(row);
        i++;
    }
    close(fd);
    return(map);
}
