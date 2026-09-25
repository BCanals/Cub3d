/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 18:56:40 by lartes-s          #+#    #+#             */
/*   Updated: 2026/09/25 19:54:53 by lartes-s         ###   ########.fr       */
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

# define WIDTH 1280
# define HEIGHT 720

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363

# define MOVE_SPEED 0.1f
# define ROT_SPEED 0.05f

# define PI 3.14159265359

typedef struct s_vec2
{
	float	x;
	float	y;
}				t_vec2;

typedef struct s_hit
{
	float	dist;
	float	wall_x;
	int		side;
}				t_hit;

typedef struct s_draw
{
	int				line_h;
	int				start;
	int				end;
	int				tex_x;
	int				tex_y;
}				t_draw;

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

typedef struct s_tex
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}				t_tex;

typedef	struct	s_game
{
	t_player	player;
	t_map		map;
	t_tex		walls[4];
	void		*mlx;
	void		*img;
	void		*win;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;

}				t_game;

void			init_structs(t_game *game);
void			ft_error_msg(char *str, t_game *game);
void			free_structs(t_game *game);
int				ft_key_hook(int keycode, t_game *game);
int				close_game(t_game *game);
int				run_mlx(t_game *game);
void			render_scene(t_game *game);
void			put_pixel(t_game *game, int x, int y, int color);
unsigned int	get_tex_pixel(t_tex *tex, int x, int y);

#endif
