/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:49:40 by lartes-s          #+#    #+#             */
/*   Updated: 2026/10/04 17:52:16 by lartes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	find_next_edge(t_vec2 *current, float angle)
{
	t_vec2	dest;
	t_vec2	steps;

	if (cosf(angle) > 0)
		dest.x = floorf(current->x + 1);
	else
		dest.x = ceilf(current->x - 1);
	if (sinf(angle) > 0)
		dest.y = floorf(current->y + 1);
	else
		dest.y = ceilf(current->y - 1);
	if (!cosf(angle))
		steps.x = 10000;
	else
		steps.x = (dest.x - current->x) / cosf(angle);
	if (!sinf(angle))
		steps.y = 10000;
	else
		steps.y = (dest.y - current->y) / sinf(angle);
	current->x += cosf(angle) * fmin(steps.x, steps.y);
	current->y += sinf(angle) * fmin(steps.x, steps.y);
}

char	get_hit_face(int x, int y, t_vec2 *point, float angle)
{
	char	face;

	face = 1;
	if ((float)x + 1 == point->x)
	{
		face = 'W';
		if (cosf(angle) < 0)
			face = 'E';
	}
	if ((float)y + 1 == point->y)
	{
		face = 'N';
		if (sinf(angle) < 0)
			face = 'S';
	}
	return (face);
}

char	get_map_element(t_game *game, t_vec2 *point, float angle)
{
	int		x;
	int		y;
	char	face;

	x = floorf(point->x) - 1;
	y = floorf(point->y) - 1;
	face = get_hit_face(x, y, point, angle);
	if (face == 'E')
		x--;
	if (face == 'S')
		y--;
	if (y >= game->map.n_rows || y < 0)
		return (0);
	if (x >= game->map.n_cols || x < 0)
		return (0);
	if (game->map.map[y][x] == '1')
		return (face);
	return (game->map.map[y][x]);
}

char	raycast(t_game *game, t_vec2 *ray, float angle)
{
	find_next_edge(ray, angle);
	while (get_map_element(game, ray, angle) == '0')
		find_next_edge(ray, angle);
	return (get_map_element(game, ray, angle));
}

void	render_scene(t_game *game)
{
	int		x;
	t_vec2	ray;
	char	face;

	x = -1;
	while (++x < WIDTH)
	{
		ray = (t_vec2){game->player.pos.x, game->player.pos.y};
		face = raycast(game, &ray, angle_from_x(x) + game->player.dir);
		if (face)
			draw_wall(game, &ray, x, face);
		else
			draw_oob(game, x);
	}
}
