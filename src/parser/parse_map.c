/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 22:22:30 by bizcru            #+#    #+#             */
/*   Updated: 2026/10/04 17:55:00 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static int	set_fd_to_map(t_parser *data, int *fd, char **line, char **buffer)
{
	*fd = open(data->scene_file, O_RDONLY);
	if (*fd == -1)
		return (printf("Error on open: %s\n", strerror(errno)), 0);
	*buffer = NULL;
	*line = get_next_line(*fd, buffer);
	while (*line)
	{
		if (get_line_type(*line) == MAP)
			break ;
		free(*line);
		*line = get_next_line(*fd, buffer);
	}
	return (1);
}

static int	check_map_line(char *line)
{
	if (*line == '\n')
		return (printf("%s%s", ERR, MAP_EMPTY_LINE), 0);
	while (*line && *line == ' ')
		line++;
	if (*line == '\n')
		return (printf("%s%s", ERR, MAP_EMPTY_LINE), 0);
	while (*line)
	{
		if (!ft_strchr(MAP_CHARS_LIST, *line))
			return (printf("%s%s%s", ERR, MAP_INV_CHAR, MAP_CHARS_LIST), 0);
		line++;
	}
	return (1);
}

static int	count_map_lines(t_parser *data)
{
	int		fd;
	char	*line;
	char	*buffer;
	int		count;

	if (!set_fd_to_map(data, &fd, &line, &buffer))
		return (0);
	count = 0;
	while (line)
	{
		count++;
		if (!check_map_line(line))
			return (free(line), free(buffer), close(fd), -1);
		free(line);
		line = get_next_line(fd, &buffer);
	}
	free(buffer);
	close(fd);
	return (count);
}

/*
	puts a copy of the map from the scene file in the relevant struct,
	provided it passes the checks (above functions).
	Return 1 on success or 0 on error.
*/

int	parse_map(t_parser *data)
{
	int		lines;
	int		i;
	char	*nl_pos;

	lines = count_map_lines(data);
	if (lines == -1)
		return (0);
	data->game->map.map = ft_calloc(sizeof(char *), lines + 1);
	if (!data->game->map.map)
		return (printf("%s%s", ERR, MALL_ERR), 0);
	i = 0;
	while (data->line)
	{
		nl_pos = ft_strchr(data->line, '\n');
		if (nl_pos)
			*nl_pos = '0';
		data->game->map.map[i++] = data->line;
		data->line = get_next_line(data->fd, &data->buffer);
	}
	if (!flood_fill_check(data))
		return (0);
	return (1);
}
