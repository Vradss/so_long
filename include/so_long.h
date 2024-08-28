/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:01:46 by vflorez           #+#    #+#             */
/*   Updated: 2024/08/28 19:00:05 by vflorez          ###   ########.fr       */
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
}               t_map;

typedef struct s_player {
    t_vec2          pos;
}               t_player;

typedef struct s_images
{
	mlx_texture_t	*wall_text;
    mlx_image_t     *wall_img;
    mlx_texture_t   *floor_text;
    mlx_image_t     *floor_img;
    mlx_texture_t   *player_text;
    mlx_image_t     *player_img;
    mlx_texture_t   *exit_text;
    mlx_image_t     *exit_img;
    mlx_texture_t   *coll_text;
    mlx_image_t     *coll_img;
}               t_images;

typedef struct	s_game {
    t_map           *map;
    t_vec2          player;
    int             steps;
    t_images        images;
    mlx_t           *mlx;
    mlx_instance_t  *player_instance;
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
t_map   *create_map(char *file);
size_t  map_width(char **map);
size_t  map_height(char **map);
void    parsing(t_map *map);


//Build textures & images
void    render_map(t_game *game);
void    render_tile(t_game *game, size_t y, size_t x);
void    cleanup_images(t_game *game);
void    load_textures(t_game *game);

//Movements
void render_player(t_game *game);
void    move_player(t_game *game, int new_x, int new_y);
void    handle_input(mlx_key_data_t keydata, void *param);

//Utils
void	error(char *message);
void    free_map(t_map *map);


# define TILE_SIZE  64


# define WALLS_SRC "./textures/bush_wall.png"
# define COLLECT_SRC "./textures/collect.png"
# define EXIT_SRC "./textures/exit.png"
# define FLOOR_SRC "./textures/floor.png"
# define PLAYER_SRC "./textures/homer_player.png"


#endif

