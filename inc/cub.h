/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 18:56:40 by lartes-s          #+#    #+#             */
/*   Updated: 2026/09/28 23:51:39 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"

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

# define PI 3.14159265359

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	float	dir;
}				t_player;

typedef struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}		t_color;

typedef struct	s_map
{
	char	*tex_n;
	char	*tex_s;
	char	*tex_e;
	char	*tex_o;
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
	ERROR
}				e_line;

typedef	struct	s_game
{
	t_player	player;
	t_map		map;
	void		*mlx;
	void		*img;
	void		*win;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;

}				t_game;

typedef struct	s_parser
{
	char		*buffer;
	char		*line;
	int			fd;
	e_line		line_type;
	t_game		*game;
}				t_parser;

// get_next_line.c functions
char	*get_next_line(int fd, char **buffer);

// parser.c functions
int		parser(int argc, char **argv);

// loaders.c funcions
int		load_t_parser(t_parser *data, char *file_name);

// cleaners.c funcions
void	clean_t_map(t_map *map);
void	clean_t_game(t_game *game);
void	clean_t_parser(t_parser *data);

// scene_read.c funcions
void	read_scene_line(t_parser *data);

#endif
