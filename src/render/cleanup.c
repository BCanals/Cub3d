/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 14:49:46 by lartes-s          #+#    #+#             */
/*   Updated: 2026/10/04 15:37:40 by lartes-s         ###   ########.fr       */
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
	if (game->map.no)
	{
		free(game->map.no);
		game->map.no = NULL;
	}
	if (game->map.so)
	{
		free(game->map.so);
		game->map.so = NULL;
	}
	if (game->map.ea)
	{
		free(game->map.ea);
		game->map.ea = NULL;
	}
	if (game->map.ea)
	{
		free(game->map.we);
		game->map.we = NULL;
	}
}

void	free_structs(t_game *game)
{
	int	i;

	if (!game)
		return ;
	if (game->map.map)
	{
		free_map_array(game->map.map);
		game->map.map = NULL;
	}
	free_textures(game);
	i = -1;
	if (game->mlx)
	{
		while (++i < 4)
			mlx_delete_image(game->mlx, game->walls[i]);
		mlx_terminate(game->mlx);
		game->mlx = NULL;
	}
}

void	ft_error_msg(char *str, t_game *game)
{
	free_structs(game);
	printf("%s\n", str);
	exit(-1);
}

int	close_game(t_game *game)
{
	if (game)
		free_structs(game);
	exit(EXIT_SUCCESS);
	return (0);
}
