/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradis <vradis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:01:46 by vflorez           #+#    #+#             */
/*   Updated: 2024/08/22 15:01:48 by vradis           ###   ########.fr       */
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


typedef struct s_vec2 {
    int x;
    int y;
}               t_vec2;

typedef struct s_map {
    char    **grid;
    int     player;
    int     exit;
    int     collectable;
    size_t  width;
    size_t  height;
}t_map;

typedef struct s_player {
    t_vec2          pos;
    mlx_image_t     *image;
}t_player;


typedef struct  s_game {
    t_map           *map;
    t_vec2          player;
    mlx_image_t     *wall_img;
    mlx_image_t     *collec_img;
}               t_game;

// Disjoint and vectos
t_vec2  vec2(int x, int y);
int     vec2_cmp(t_vec2 u, t_vec2 v);
void    check_path_TESTING(t_game *game);

//Check maps
int     check_args(int argc, char **argv);
int     read_map(char *map);
void    check_map_area(t_map *map);
void    check_invalid_char(int c);
void    check_map_char(t_map *map);
void    check_map_rectangle(t_map *map);
void    check_wall(t_map *map);
char   **create_map(char *file);
size_t  map_width(char **map);
size_t  map_height(char **map);
void    parsing(t_map *map);

//Utils

void	error(char *message);
void    free_map(t_map *map);



#endif

