/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 16:05:24 by lartes-s          #+#    #+#             */
/*   Updated: 2026/10/04 17:52:31 by lartes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

uint32_t	get_colour(t_color c)
{
	uint32_t	colour;

	colour = (255 << 24) + ((c.r) << 16) + ((c.g << 8)) + c.b;
	return (colour);
}

uint32_t	get_wall_pixel(t_game *game, t_vec2 *impact, char orientation)
{
	mlx_image_t	*wall;
	int			x;
	int			y;
	uint32_t	inv;

	if (orientation == 'N')
		wall = game->walls[NORTH];
	else if (orientation == 'S')
		wall = game->walls[SOUTH];
	else if (orientation == 'W')
		wall = game->walls[WEAST];
	else
		wall = game->walls[EAST];
	x = fmin(impact->x * wall->width, wall->width - 1);
	y = fmin(impact->y * wall->height, wall->height - 1);
	inv = ((uint32_t *)wall->pixels)[y * wall->width + x];
	return (((inv & 0xFF) << 24) | ((inv & 0xFF00) << 8)
		| ((inv & 0xFF0000) >> 8) | (inv >> 24));
}

void	draw_wall(t_game *game, t_vec2 *ray, int x, char face)
{
	int		y;
	float	view;
	float	dist;
	float	step;
	t_vec2	impact;

	if (face == 'N' || face == 'S')
		impact.x = ray->x - (int)ray->x;
	else
		impact.x = ray->y - (int)ray->y;
	dist = abs_vec(subt_from_vec(ray, &game->player.pos));
	y = -1;
	view = HEIGHT / dist / cosf(angle_from_x(x));
	step = 1 / view;
	impact.y = (-HEIGHT + view) / 2 * step;
	while (++y < HEIGHT)
	{
		if (y < (HEIGHT - view) / 2)
			mlx_put_pixel(game->img, x, y, get_colour(game->map.sky));
		else if (y < (HEIGHT + view) / 2)
			mlx_put_pixel(game->img, x, y, get_wall_pixel(game, &impact, face));
		else
			mlx_put_pixel(game->img, x, y, get_colour(game->map.floor));
		impact.y += step;
	}
}

void	draw_oob(t_game *game, int x)
{
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		mlx_put_pixel(game->img, x, y, 0xFF00FFFF);
	}
}

float	angle_from_x(int x)
{
	float	normal_x;

	normal_x = ((float)x * 2.0f) / WIDTH - 1.0f;
	return (atan2f(normal_x, 1.0f));
}
