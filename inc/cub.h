/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 18:56:40 by lartes-s          #+#    #+#             */
/*   Updated: 2026/09/17 19:59:57 by lartes-s         ###   ########.fr       */
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

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
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
	t_mlx		*mlx; // ho omple la Laia
	
}				t_game;

#endif
