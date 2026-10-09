/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 18:56:40 by lartes-s          #+#    #+#             */
/*   Updated: 2026/10/09 20:47:54 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <math.h>
# include <errno.h>
# include <stdbool.h>
# include <string.h>
# include <stddef.h>

# define WIDTH 1280
# define HEIGHT 720

# define W 119
# define A 97
# define S 115
# define D 100

# define ERR "Error\n"
# define MALL_ERR "Malloc error\n"
# define MAP_N_LAST "Scene file: all elements must be defined before map\n"
# define MAP_EMPTY_LINE "Map must be at file's end and have no empty lines\n"
# define MAP_CHARS_LIST " 01NSEW\n"
# define MAP_INV_CHAR "Map contains invalid chars. Valid chars are: "
# define MAP_OPEN "Map is not enclosed\n"
# define MAP_NO_PLAYER "No player starting position found in map\n"
# define TEX_EMPTY "No path provided\n"
# define TEX_REP "Repeated texture definition on line: "
# define RGB_EMPTY "No color params provided\n"
# define RGB_FORM_ERR "Wrong format. Expected R,G,B colors in range [0,255]\n"

# define PI 3.14159265359
# define PI_2 1.5707963267

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEAST 3

typedef struct s_vec2
{
	float	x;
	float	y;
}				t_vec2;


typedef struct s_player
{
	t_vec2	pos;
	float	dir;
}				t_player;

typedef struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_color;

typedef struct	s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		n_cols;
	int		n_rows;
	char	**map; 
	t_color	floor;
	t_color	sky;
}				t_map;

typedef enum	enum_line
{
	TEX_N,
	TEX_S,
	TEX_E,
	TEX_O,
	FLOOR,
	SKY,
	MAP,
	ERROR,
	EMPTY
}				e_line;

typedef	struct	s_game
{
	mlx_image_t		*walls[4];
	t_player		player;
	t_map			map;
	mlx_t			*mlx;
	mlx_image_t		*img;
	void			*win;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;

}				t_game;

typedef struct	s_parser
{
	char		*buffer;
	char		*line;
	char		*scene_file;
	int			fd;
	e_line		line_type;
	char		*parsed_elements;
	char		**copy;
	t_game		*game;
}				t_parser;

// get_next_line.c functions
char	*get_next_line(int fd, char **buffer);

// parser.c functions
t_game	*parser(int argc, char **argv);

// parser_utils.c functions
int		parse_wall(t_parser *data);
int		parse_fc(t_parser *data);

// parse_map.c functions
int		parse_map(t_parser *data);

// parser_map_utils.c
int		set_player(t_parser *data);

// flood_fill.c functions
int		flood_fill_check(t_parser *data);
t_vec2	find_in_array(char **map, char c);

// errors_utils.c
void	print_wrong_rgb_format(e_line line_type);
void	print_emtpy_tex_error(e_line line_type);
void	print_emtpy_fc_error(e_line line_type);

// loaders.c funcions
int		load_t_parser(t_parser *data, char *file_name);

// cleaners.c funcions
void	clean_t_map(t_map *map);
void	clean_t_game(t_game *game);
void	clean_t_parser(t_parser *data);

// scene_read.c funcions
void	read_scene_line(t_parser *data);
e_line	get_line_type(char *str);

void	init_structs(t_game *game);

int		run_mlx(t_game *game);
int		close_game(t_game *game);
void	ft_error_msg(char *str, t_game *game);
void	key_hooks(mlx_key_data_t keydata, t_game *game);
void	render_scene(t_game *game);
float	angle_from_x(int x);
void	draw_oob(t_game *game, int x);
void	draw_wall(t_game *game, t_vec2 *ray, int x, char face);
t_vec2	*normalize_vec(t_vec2 *vec);
t_vec2	*subt_from_vec(t_vec2 *orig, t_vec2 *other);
t_vec2	*add_to_vec(t_vec2 *orig, t_vec2 *other);
void	free_structs(t_game *game);
float	abs_vec(t_vec2 *vec);


#endif
