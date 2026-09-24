/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 19:11:33 by lartes-s          #+#    #+#             */
/*   Updated: 2026/09/24 19:18:21 by lartes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	free_map_array(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

void	free_textures(t_game *game)
{
	if (game->map.tex_n)
	{
		free(game->map.tex_n);
		game->map.tex_n = NULL;
	}
	if (game->map.tex_s)
	{
		free(game->map.tex_s);
		game->map.tex_s = NULL;
	}
	if (game->map.tex_e)
	{
		free(game->map.tex_e);
		game->map.tex_e = NULL;
	}
	if (game->map.tex_o)
	{
		free(game->map.tex_o);
		game->map.tex_o = NULL;
	}
}

void	free_structs(t_game *game)
{
	if (!game)
		return ;
	if (game->map.map)
	{
		free_map_array(game->map.map);
		game->map.map = NULL;
	}
	free_textures(game);
	if (game->mlx)
	{
		if (game->img)
		{
			mlx_destroy_image(game->mlx, game->img);
			game->img = NULL;
		}
		if (game->win)
		{
			mlx_destroy_window(game->mlx, game->win);
			game->win = NULL;
		}
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

void	ft_error_msg(char *str, t_game *game)
{
	free_structs(game);
	printf("%s\n", str);
	exit(-1);
}

