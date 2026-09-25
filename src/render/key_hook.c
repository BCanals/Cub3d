/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 18:11:34 by lartes-s          #+#    #+#             */
/*   Updated: 2026/09/25 18:15:50 by lartes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	move_player(t_game *game, float angle_offset)
{
	float	move_angle;
	float	new_x;
	float	new_y;

	move_angle = game->player.dir + angle_offset;
	new_x = game->player.pos_x + cosf(move_angle) * MOVE_SPEED;
	new_y = game->player.pos_y + sinf(move_angle) * MOVE_SPEED;
	if (game->map.map[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	if (game->map.map[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
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
