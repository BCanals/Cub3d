/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 22:17:49 by bizcru            #+#    #+#             */
/*   Updated: 2026/10/08 19:54:06 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	clean_t_map(t_map *map)
{
	//free((*map)->floor);
	//free((*map)->sky);
	free(map->no);
	free(map->so);
	free(map->ea);
	free(map->we);
	if (map->map)
		ft_free_array(map->map);
	map->map = NULL;
	//free(*map);
	// *map = NULL;
}

void	clean_t_game(t_game *game)
{
	int i;

	//free((*game)->player);
	//if((*game)->map)
	clean_t_map(&game->map);
	i = -1;
	if (game->mlx)
	{
		while (++i < 4)
			mlx_delete_image(game->mlx, game->walls[i]);
		mlx_terminate(game->mlx);
		game->mlx = NULL;
	}
	free(game);
}

void	clean_t_parser(t_parser *data)
{
	if (!data)
		return ;
	if (data->fd > 2)
		close(data->fd);
	free(data->buffer);
	free(data->line);
	if (data->game)
	{
		clean_t_game(data->game);
		data->game = NULL;
	}
}

int	close_game(t_game *game)
{
	if (game)
		clean_t_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}
