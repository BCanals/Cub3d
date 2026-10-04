/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 22:12:43 by bizcru            #+#    #+#             */
/*   Updated: 2026/10/04 19:01:10 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

/* 
   This file contains the functions for the creations of the neceesary structs.
   You may wonder wether having one function per struct is overkill. Probably.
   The only benefit is to directly prin err msg instead of managing it.
   Plus, easier to add stuff in the future if needed.
   Again, probably unnecessary but it is how we chose to built it..
 */

/*
static t_player	*load_t_player()
{
	t_player	*player;

	player = ft_calloc(sizeof(t_player), 1);
	if (!player)
		printf("Error on malloc: %s\n", strerror(errno));
	return (player);
}

static t_color	*load_t_color()
{
	t_color	*color;

	color = ft_calloc(sizeof(t_color), 1);
	if (!color)
		printf("Error on malloc: %s\n", strerror(errno));
	return (color);
}

static t_map	*load_t_map()
{
	t_map	*map;

	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
	{
		printf("Error on malloc: %s\n", strerror(errno));
		return (NULL);
	}
	map->floor = load_t_color();
	map->sky = load_t_color();
	if (!map->floor || !map->sky)
		return (clean_t_map(&map), NULL);
	return (map);
}
*/

static t_game	*load_t_game(void)
{
	t_game	*game;

	game = calloc(sizeof(t_game), 1);
	if (!game)
	{
		printf("Error on malloc: %s\n", strerror(errno));
		return (NULL);
	}
	/*game->player = init_t_player();
	if (!game->player)
		return (clean_t_game(game), NULL);
	game->map = init_t_map();
	if (!game->map)
		return (clean_t_game(game), NULL);*/
	return (game);
}

int	load_t_parser(t_parser *data, char *file_name)
{
	data->fd = open(file_name, O_RDONLY);
	if (data->fd == -1)
		return (printf("Error on open: %s\n", strerror(errno)), 0);
	data->buffer = NULL;
	data->line = NULL;
	data->line = get_next_line(data->fd, &data->buffer);
	if (!data->line)
	{
		printf("Scene file not readable or empty.\n");
		return (clean_t_parser(data), 0);
	}
	data->scene_file = file_name;
	data->game = NULL;
	data->parsed_elements = 0;
	data->game = load_t_game();
	if (!data->game)
		return (clean_t_parser(data), 0);
	return (1);
}
