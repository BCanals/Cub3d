/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 13:39:37 by lartes-s          #+#    #+#             */
/*   Updated: 2026/10/04 17:46:30 by lartes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	load_images(t_game *game)
{
	const char		*paths[4] = {game->map.no, game->map.so, game->map.ea,
		game->map.we};
	mlx_texture_t	*texture;
	int				i;

	i = -1;
	texture = NULL;
	while (++i < 4)
	{
		if (ft_strlen(paths[i]) >= 4 && ft_strcmp(paths[i]
				+ (ft_strlen(paths[i]) - 4), ".png") == 0)
			texture = mlx_load_png(paths[i]);
		else
			ft_error_msg("Invalid texture path\n", game);
		if (!texture)
			ft_error_msg("Error opening texture\n", game);
		game->walls[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_delete_texture(texture);
		if (!game->walls[i])
			ft_error_msg("Error creating image\n", game);
	}
}

int	run_mlx(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!game->mlx)
		ft_error_msg("Error initialising mlx", game);
	load_images(game);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img || (mlx_image_to_window(game->mlx, game->img, 0, 0) < 0))
		ft_error_msg("Error creating game image", game);
	mlx_key_hook(game->mlx, (mlx_keyfunc)key_hooks, game);
	render_scene(game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
