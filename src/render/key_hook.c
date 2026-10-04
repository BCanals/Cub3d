/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 18:11:34 by lartes-s          #+#    #+#             */
/*   Updated: 2026/10/02 17:22:22 by lartes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	move_player(t_game *game, float angle_offset)
{
	float	move_angle;
	t_vec2	new;

	move_angle = game->player.dir + angle_offset;
	new.x = game->player.pos.x + cosf(move_angle) * MOVE_SPEED;
	new.y = game->player.pos.y + sinf(move_angle) * MOVE_SPEED;
	if (game->map.map[(int)game->player.pos.y][(int)new.x] != '1')
		game->player.pos.x = new.x;
	if (game->map.map[(int)new.y][(int)game->player.pos.x] != '1')
		game->player.pos.y = new.y;
}

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_game(game);
	else if (keycode == W || keycode == ARROW_UP)
		move_player(game, 0.0f);
	else if (keycode == S || keycode == ARROW_DOWN)
		move_player(game, PI);
	else if (keycode == A)
		move_player(game, -PI / 2.0f);
	else if (keycode == D)
		move_player(game, PI / 2.0f);
	else if (keycode == ARROW_LEFT)
		game->player.dir -= ROT_SPEED;
	else if (keycode == ARROW_RIGHT)
		game->player.dir += ROT_SPEED;
	render_scene(game);
	return (0);
}
