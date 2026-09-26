/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 18:56:40 by lartes-s          #+#    #+#             */
/*   Updated: 2026/09/26 11:29:57 by bizcru           ###   ########.fr       */
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

int		parser(int argc, char **argv);
char	*get_next_line(int fd, char **buffer);

#endif
