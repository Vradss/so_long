/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradis <vradis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:23:44 by vflorez           #+#    #+#             */
/*   Updated: 2024/08/17 19:11:29 by vradis           ###   ########.fr       */
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

char    **create_map(char *file)
{
    int     fd;
    char    *row;
    int     i;
    char    **map;
    
    i = 0;
    map = ft_calloc(read_map(file) + 1, sizeof(char *));
    fd = open(file, O_RDONLY);
    if (fd < 0)
        error("File error");
    row = get_next_line(fd);
    while (row != NULL)
    {
        map[i] = ft_strtrim(row, "\n \t\f\v\r");
        row = get_next_line(fd);
        i++;
    }
    map[i] = NULL;
    close(fd);
    
     // Imprimir el mapa para verificar si se guardó correctamente
    i = 0;
    while (map[i] != NULL)
    {
        printf("%s\n", map[i]);
        i++;
    }
    return(map);
}

