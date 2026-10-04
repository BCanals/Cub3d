/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:39:49 by lartes-s          #+#    #+#             */
/*   Updated: 2026/10/04 15:48:55 by lartes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	ft_mov_key_hook(mlx_key_data_t keydata, t_game *game)
{
	float	mov_speed;

	mov_speed = 0.05;
	if (keydata.key == MLX_KEY_W)
	{
		game->player.pos.x += cos(game->player.dir) * mov_speed;
		game->player.pos.y += sin(game->player.dir) * mov_speed;
	}
	else if (keydata.key == MLX_KEY_S)
	{
		game->player.pos.x -= cos(game->player.dir) * mov_speed;
		game->player.pos.y -= sin(game->player.dir) * mov_speed;
	}
	else if (keydata.key == MLX_KEY_A)
	{
		game->player.pos.x -= cos(game->player.dir + PI_2) * mov_speed;
		game->player.pos.y -= sin(game->player.dir + PI_2) * mov_speed;
	}
	else if (keydata.key == MLX_KEY_D)
	{
		game->player.pos.x += cos(game->player.dir + PI_2) * mov_speed;
		game->player.pos.y += sin(game->player.dir + PI_2) * mov_speed;
	}
	printf("Player position: (%f, %f)\n", game->player.pos.x,
		game->player.pos.y);
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
	printf("Player direction: %F\n", game->player.dir * 180 / PI);
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