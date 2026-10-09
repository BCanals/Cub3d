/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 20:18:17 by becanals          #+#    #+#             */
/*   Updated: 2026/10/09 20:51:16 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

t_vec2	find_in_array(char **map, char c)
{
	t_vec2	pos;
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == c)
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
		}
	}
	pos.x = -1;
	pos.y = -1;
	return (pos);
}

int	set_player(t_parser *data)
{
	t_vec2	pos;
	char	*chars;
	int		i;

	chars = "ESWN";
	i = -1;
	while (chars[++i])
	{
		pos = find_in_array(data->game->map.map, chars[i]);
		if (pos.x != -1)
			break ;
	}
	if (pos.x == -1)
	{
		printf("%s%s", ERR, MAP_NO_PLAYER);
		return (0);
	}
	data->game->player.pos.x = pos.x + 0.5f;
	data->game->player.pos.y = pos.y + 0.5f;
	data->game->player.dir = 0.0f + PI / 2 * i;
	return (1);
}
