/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:01:46 by vflorez           #+#    #+#             */
/*   Updated: 2024/08/15 19:21:53 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../src/libft/libft.h"
# include "../src/Printf/ft_printf.h"
# include "../src/libft/get_next_line.h"
# include "../src/MLX42/include/MLX42/MLX42.h"


typedef struct s_map {
    char **grid;
    int player;
    int exit;
    int collectable;
    int width;
    int height;
}t_map;

typedef struct s_player {
    int x;
    int y;
}t_player;

typedef struct s_game {
    t_map *map;
    t_player *player;
}t_game;

//Check maps

int     check_args(int argc, char **argv);
int     read_map(char *map);
void    check_map_area(t_map *map);
void    check_invalid_char(int c);
void    check_map_char(t_map *map);
void    check_map_rectangle(t_map *map);
void    check_wall(t_map *map);
t_map   *create_map(char *file_path);

//Utils

void	error(char *message);
void    free_map(t_map *map);



#endif

