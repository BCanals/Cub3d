/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 22:17:49 by bizcru            #+#    #+#             */
/*   Updated: 2026/10/30 20:08:10 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	clean_t_map(t_map *map)
{
	if (!map)
		return ;
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->ea)
		free(map->ea);
	if (map->we)
		free(map->we);
	if (map->map)
		ft_free_array(map->map);
	map->map = NULL;
}

void	clean_t_game(t_game *game)
{
	int	i;

	clean_t_map(&game->map);
	i = -1;
	if (game->mlx)
	{
		while (++i < 4)
			if (game->walls[i])
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
	if (data->copy)
		ft_free_array(data->copy);
	free(data->parsed_elements);
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
