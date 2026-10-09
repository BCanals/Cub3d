/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 22:12:43 by bizcru            #+#    #+#             */
/*   Updated: 2026/10/09 20:57:15 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static t_game	*load_t_game(void)
{
	t_game	*game;

	game = calloc(sizeof(t_game), 1);
	if (!game)
	{
		printf("Error on malloc: %s\n", strerror(errno));
		return (NULL);
	}
	return (game);
}

int	load_t_parser(t_parser *data, char *file_name)
{
	data->fd = open(file_name, O_RDONLY);
	if (data->fd == -1)
		return (printf("Error on open: %s\n", strerror(errno)), 0);
	data->parsed_elements = ft_calloc(10, 1);
	if (!data->parsed_elements)
		return (printf("%s", MALL_ERR));
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
	data->copy = NULL;
	data->game = load_t_game();
	if (!data->game)
		return (clean_t_parser(data), 0);
	return (1);
}
