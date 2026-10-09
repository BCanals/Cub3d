/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:39:49 by lartes-s          #+#    #+#             */
/*   Updated: 2026/10/09 20:57:28 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	apply_movement(t_game *game, float new_x, float new_y)
{
	int	map_x;
	int	map_y;

	map_x = floorf(new_x) - 1;
	map_y = floorf(new_y) - 1;
	if (map_y >= 0 && map_y < game->map.n_rows
		&& map_x >= 0 && map_x < game->map.n_cols)
	{
		if (game->map.map[map_y][map_x] != '1')
		{
			game->player.pos.x = new_x;
			game->player.pos.y = new_y;
		}
	}
}

void	ft_mov_key_hook(mlx_key_data_t keydata, t_game *game)
{
	float	nx;
	float	ny;
	float	ang;

	nx = game->player.pos.x;
	ny = game->player.pos.y;
	ang = game->player.dir;
	if (keydata.key == MLX_KEY_S)
		ang += PI;
	else if (keydata.key == MLX_KEY_A)
		ang -= PI_2;
	else if (keydata.key == MLX_KEY_D)
		ang += PI_2;
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S
		|| keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
	{
		nx += cos(ang) * 0.05;
		ny += sin(ang) * 0.05;
		apply_movement(game, nx, ny);
	}
}

void	ft_rot_key_hook(mlx_key_data_t keydata, t_game *game)
{
	float	rot_speed;

	rot_speed = PI / 90;
	if (keydata.key == MLX_KEY_LEFT)
		game->player.dir -= rot_speed;
	else if (keydata.key == MLX_KEY_RIGHT)
		game->player.dir += rot_speed;
	game->player.dir += PI * 2;
	game->player.dir = fmod(game->player.dir, PI * 2);
}

void	key_hooks(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	else if (ft_isascii(keydata.key))
		ft_mov_key_hook(keydata, game);
	else
		ft_rot_key_hook(keydata, game);
	render_scene(game);
}
