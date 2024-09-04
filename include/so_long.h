/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradis <vradis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:01:46 by vflorez           #+#    #+#             */
/*   Updated: 2024/09/04 19:28:53 by vradis           ###   ########.fr       */
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

enum e_Relations
{LEFT, TOP, RIGHT, BOTTOM};

typedef int	t_adjacents[4];

typedef struct s_vec2
{
	int	x;
	int	y;
}				t_vec2;

typedef struct s_map
{
	char	**grid;
	int		player;
	int		exit;
	int		collectable;
	size_t	width;
	size_t	height;
}				t_map;

typedef struct s_auxiliary
{
	int	**grid;
	int	width;
	int	height;
	int	walkable_tiles_count;
}			t_aux_map;


typedef struct	s_disjoint_set {
	int *rep;
	int	*rank;
	int	v_count;
}				t_disjoint_set;		

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
	t_vec2          exit;
	t_vec2          *collectibles;
}               t_game;

//Coordinates
t_vec2	vec2(int x, int y);
int     vec2_cmp(t_vec2 u, t_vec2 v);
t_vec2	determine_square_coordinates(char **grid, char element);
//void    check_path_TESTING(t_game *game);

//Parsing Maps
int     check_args(int argc, char **argv);
void    check_invalid_char(int c);
void    check_map_area(t_map *map);
void    check_map_char(t_map *map);
void    check_map_rectangle(t_map *map);
void    check_wall(t_map *map);
size_t  map_width(char **map);
size_t  map_height(char **map);
void    parsing(t_map *map);

//Initialize Maps
int     read_map(char *map);
t_map	*init_map(char *file, int fd);
t_map   *create_map(char *file);
void	print_map(t_map *map);

//Build textures & images
void    render_map(t_game *game);
void    render_tile(t_game *game, size_t y, size_t x);
void	render_player(t_game *game);
void    load_textures(t_game *game);
void    cleanup_images(t_game *game);

//Movements & handle input
void	move_player_left(t_game *game, int dx, int dy);
void	move_player_right(t_game *game, int dx, int dy);
void	move_player_up(t_game *game, int dx, int dy);
void	move_player_down(t_game *game, int dx, int dy);
void    handle_input(mlx_key_data_t keydata, void *param);

//Check adjacency
int		maximum(int a, int b);
int		minimum(int a, int b);
int		clamp(int value, int min, int max);
int		walkable_tiles(int **grid, int width, int height);
int		is_walkable(int square);
void	mark_relations(t_adjacents *a, t_aux_map m, int i, int j);
t_adjacents	*new_adjacency_map(t_aux_map m);
int		*new_rep_array(int v_count);

//Union-find (Disjoint set)
void			compress_subtrees(t_disjoint_set	*s);
t_disjoint_set	*new_disj_set(t_adjacents *adjacency_map, int element_n);
t_disjoint_set	*build_disjoint_set(t_aux_map aux_map);
int		find_rep(int *rep, int element);
void	set_union(t_disjoint_set *s, int adjacent_element, int cur_element);
void	union_find(t_disjoint_set *s, t_adjacents relations, int cur_element);

//Check collect
t_vec2  *collectibles(char **grid, int count);
void	check_collec(t_aux_map *m, t_disjoint_set *s, t_game *g, int target_rep);

//Check validity path
t_aux_map	auxiliary_map(char **grid, int width, int height);
void		check_path_validity(t_game *game);
void		check_rep(t_aux_map *a, t_disjoint_set *s, t_game *game);

//Main
t_game  setup_game(t_map *map);
void	initialize_game(t_game *game, int argc , char **argv);

//Utils
void	error(char *message);
void	free_map(t_map *map);
void	success(char *message);
void 	free_disjoint_set(t_disjoint_set *s);
void	free_aux_map(t_aux_map *m);

# define TILE_SIZE  64

# define WALLS_SRC "./textures/bush_wall.png"
# define COLLECT_SRC "./textures/collect.png"
# define EXIT_SRC "./textures/exit.png"
# define FLOOR_SRC "./textures/floor.png"
# define PLAYER_SRC "./textures/homer_player.png"

#endif
