/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 19:04:35 by lartes-s          #+#    #+#             */
/*   Updated: 2026/09/24 20:02:59 by lartes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	load_images(t_game *game)
{
	const char *paths[4] = 
}

int	run_mlx(t_game *game)
{
	game->player.pos_x++;
	game->player.pos_y++;
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!game->mlx)
		ft_error_msg("Error initializing mlx", game);
	load_images(game);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img || mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0) < 0))
		ft_error_msg("Error creating game image", game);
	mlx_key_hook(game->mlx, (mlx_keyfunc)ft_key_hook, game);
	render_scene(game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}