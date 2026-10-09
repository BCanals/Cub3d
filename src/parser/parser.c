/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 18:31:47 by becanals          #+#    #+#             */
/*   Updated: 2026/10/09 21:07:23 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static int	check_file_ext(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len < 4)
		return (0);
	if (ft_strcmp(&file_name[len - 4], ".cub"))
		return (0);
	return (1);
}

static int	load_scene(t_parser *data)
{
	while (data->line)
	{
		read_scene_line(data);
		if (data->line_type == ERROR)
			return (clean_t_parser(data), 0);
		free(data->line);
		data->line = get_next_line(data->fd, &data->buffer);
	}
	return (1);
}

t_game	*parser(int argc, char **argv)
{
	t_parser	p_data;
	t_game		*game;

	if (argc < 2)
		return (printf("Usage: %s [map]\n", argv[0]), NULL);
	if (!check_file_ext(argv[1]))
		return (printf("The scene file must be in '*.cub' format\n"), NULL);
	if (!load_t_parser(&p_data, argv[1]))
		return (0);
	if (!load_scene(&p_data))
		return (0);
	game = p_data.game;
	p_data.game = NULL;
	clean_t_parser(&p_data);
	return (game);
}
