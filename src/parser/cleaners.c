/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 22:17:49 by bizcru            #+#    #+#             */
/*   Updated: 2026/09/28 01:37:12 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

void	clean_t_map(t_map *map)
{
	//free((*map)->floor);
	//free((*map)->sky);
	free(map->tex_n);
	free(map->tex_s);
	free(map->tex_e);
	free(map->tex_o);
	if (map->map)
		ft_free_array(map->map);
	map->map = NULL;
	//free(*map);
	//*map = NULL;
}

void	clean_t_game(t_game *game)
{
	//free((*game)->player);
	//if((*game)->map)
	clean_t_map(&game->map);
	//FALTA DESTRUIR LES COSES DE MLX: mlx, img, win, data!
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
