/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 18:56:40 by lartes-s          #+#    #+#             */
/*   Updated: 2026/10/04 16:06:32 by lartes-s         ###   ########.fr       */
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

# define WIDTH 1280
# define HEIGHT 720

# define W 119
# define A 97
# define S 115
# define D 100

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
}		t_color;

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

int		run_mlx(t_game *game);
int		close_game(t_game *game);
void	ft_error_msg(char *str, t_game *game);
void	key_hooks(mlx_key_data_t keydata, t_game *game);


#endif
