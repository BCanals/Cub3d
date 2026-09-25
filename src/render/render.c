/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 19:03:11 by lartes-s          #+#    #+#             */
/*   Updated: 2026/09/25 19:55:29 by lartes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	set_hit_side(t_hit *hit, t_vec2 prev, t_vec2 ray, t_vec2 step)
{
	if ((int)prev.x != (int)ray.x)
	{
		hit->wall_x = ray.y - floorf(ray.y);
		if (step.x > 0)
			hit->side = 3;
		else
			hit->side = 2;
	}
	else
	{
		hit->wall_x = ray.x - floorf(ray.x);
		if (step.y > 0)
			hit->side = 0;
		else
			hit->side = 1;
	}
}

static t_hit	cast_single_ray(t_game *game, float ray_angle)
{
	t_hit	hit;
	t_vec2	ray;
	t_vec2	prev;
	t_vec2	step;

	ray.x = game->player.pos_x;
	ray.y = game->player.pos_y;
	prev = ray; // <-- Afegeix aquesta línia per evitar el warning de no inicialitzat
	step.x = cosf(ray_angle) * 0.005f;
	step.y = sinf(ray_angle) * 0.005f;
	hit.dist = 0.0f;
	while (game->map.map[(int)ray.y][(int)ray.x] != '1')
	{
		prev = ray;
		ray.x += step.x;
		ray.y += step.y;
		hit.dist += 0.005f;
	}
	set_hit_side(&hit, prev, ray, step);
	return (hit);
}

static void	init_draw_params(t_draw *d, t_hit hit, t_tex *tex, float angle)
{
	d->line_h = (int)(HEIGHT / hit.dist);
	d->start = (HEIGHT / 2) - (d->line_h / 2);
	d->end = (HEIGHT / 2) + (d->line_h / 2);
	d->tex_x = (int)(hit.wall_x * (float)tex->width);
	if ((hit.side == 0 && cosf(angle) > 0)
		|| (hit.side == 3 && sinf(angle) < 0))
		d->tex_x = tex->width - d->tex_x - 1;
}

static void	draw_column(t_game *game, int x, t_hit hit, float angle)
{
	t_draw	d;
	t_tex	*tex;
	int		y;

	hit.dist *= cosf(angle - game->player.dir);
	if (hit.dist < 0.1f)
		hit.dist = 0.1f;
	tex = &game->walls[hit.side];
	init_draw_params(&d, hit, tex, angle);
	y = 0;
	while (y < HEIGHT)
	{
		if (y < d.start)
			put_pixel(game, x, y, (game->map.sky.r << 16)
				| (game->map.sky.g << 8) | game->map.sky.b);
		else if (y <= d.end)
		{
			d.tex_y = (int)((y - d.start) * (float)tex->height / d.line_h);
			put_pixel(game, x, y, get_tex_pixel(tex, d.tex_x, d.tex_y));
		}
		else
			put_pixel(game, x, y, (game->map.floor.r << 16)
				| (game->map.floor.g << 8) | game->map.floor.b);
		y++;
	}
}

void	render_scene(t_game *game)
{
	t_hit	hit;
	float	fov;
	float	angle;
	int		x;

	fov = PI / 3.0f;
	x = 0;
	while (x < WIDTH)
	{
		angle = (game->player.dir - (fov / 2.0f))
			+ ((float)x / (float)WIDTH) * fov;
		hit = cast_single_ray(game, angle);
		draw_column(game, x, hit, angle);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}