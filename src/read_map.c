/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:23:44 by vflorez           #+#    #+#             */
/*   Updated: 2024/08/13 19:12:33 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int read_map(char *map)
{
    int fd;
    char *line;

    int i = 0;
    fd = open(map, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error al abrir el archivo\n");
        exit(1);
    }
    line = get_next_line(fd);
    while (line != NULL)
    {
        ft_printf("%s", line);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    //free(line);
    close(fd);
    return (i);
}
