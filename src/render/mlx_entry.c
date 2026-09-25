/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 19:04:35 by lartes-s          #+#    #+#             */
/*   Updated: 2026/09/25 18:47:06 by lartes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static bool	check_xpm_ext(const char *path)
{
	int	len;

	if (!path)
		return (false);
	len = ft_strlen(path);
	if (len < 5)
		return (false);
	return (ft_strcmp(path + (len - 4), ".xpm") == 0);
}

void	load_textures(t_game *game)
{
	char	*paths[4];
	int		i;

	paths[0] = game->map.tex_n;
	paths[1] = game->map.tex_s;
	paths[2] = game->map.tex_e;
	paths[3] = game->map.tex_o;
	i = -1;
	while (++i < 4)
	{
		if (!check_xpm_ext(paths[i]))
			ft_error_msg("Error: Texture extension must be .xpm\n", game);
		game->walls[i].img = mlx_xpm_file_to_image(game->mlx, paths[i],
				&game->walls[i].width, &game->walls[i].height);
		if (!game->walls[i].img)
			ft_error_msg("Error: Failed to load XPM file\n", game);
		game->walls[i].addr = mlx_get_data_addr(game->walls[i].img,
				&game->walls[i].bpp,
				&game->walls[i].line_len,
				&game->walls[i].endian);
		if (!game->walls[i].addr)
			ft_error_msg("Error: failed to get the data addr\n", game);
	}

}

int	run_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error_msg("Error initializing mlx", game);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3d");
	if (!game->win)
		ft_error_msg("Error creating window", game);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
		ft_error_msg("Error creating game image", game);
	game->data = mlx_get_data_addr(game->img, &game->bpp,
			&game->size_line, &game->endian);
	if (!game->data)
		ft_error_msg("Error getting image data address", game);
	load_textures(game);
	mlx_key_hook(game->win, ft_key_hook, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	render_scene(game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}

