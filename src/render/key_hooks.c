/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:39:49 by lartes-s          #+#    #+#             */
/*   Updated: 2026/10/27 19:30:42 by lartes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	set_margin(t_game *game, t_vec2 *new, t_vint2 *map)
{
	float	margin;

	margin = 0.2;
	if (new->x > game->player.pos.x)
		map->x = floorf(new->x + margin) - 1;
	else
		map->x = floorf(new->x - margin) - 1;
	if (new->y > game->player.pos.y)
		map->y = floorf(new->y + margin) - 1;
	else
		map->y = floorf(new->y - margin) - 1;
}

static void	apply_movement(t_game *game, t_vec2 *new)
{
	t_vint2	map;
	t_vint2 curr_map;
	float 	margin;

	margin = 0.2;
	map.x = floorf(new->x) - 1;
	map.y = floorf(new->y) - 1;
	set_margin(game, new, &map);
	curr_map.x = floorf(game->player.pos.x) - 1;
	curr_map.y = floorf(game->player.pos.y) - 1;
	if (map.y >= 0 && map.y < game->map.n_rows
		&& map.x >= 0 && map.x < game->map.n_cols)
	{
		if (game->map.map[curr_map.y][map.x] != '1')
			game->player.pos.x = new->x;
		if (game->map.map[map.y][curr_map.x] != '1')
			game->player.pos.y = new->y;
	}
}

void	ft_mov_key_hook(mlx_key_data_t keydata, t_game *game)
{
	t_vec2	new;
	float	ang;

	new.x = game->player.pos.x;
	new.y = game->player.pos.y;
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
		new.x += cos(ang) * 0.08;
		new.y += sin(ang) * 0.08;
		apply_movement(game, &new);
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
