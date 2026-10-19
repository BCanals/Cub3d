/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 20:18:17 by becanals          #+#    #+#             */
/*   Updated: 2026/10/19 20:16:52 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

t_vint2	find_in_array(char **map, char c)
{
	t_vint2	pos;
	int		i;
	int		j;

	i = -1;
	pos.x = -1;
	pos.y = -1;
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
	return (pos);
}

static void	find_player(char **map, char c, int *count, t_vint2 *pos)
{
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
				*count += 1;
				pos->x = j;
				pos->y = i;
			}
		}
	}
}

int	set_player(t_parser *data)
{
	t_vint2	pos;
	char	*chars;
	int		i;
	int		players;

	pos.x = -1;
	pos.y = -1;
	chars = "ESWN";
	players = 0;
	i = -1;
	while (chars[++i])
		find_player(data->game->map.map, chars[i], &players, &pos);
	if (players == 0)
		return (printf("%s%s", ERR, MAP_NO_PLAYER), 0);
	if (players > 1)
		return (printf("%s%s%i\n", ERR, MAP_TWO_PLAYERS, players), 0);
	data->game->player.pos.x = pos.x + 1.5f;
	data->game->player.pos.y = pos.y + 1.5f;
	data->game->player.dir = 0.0f + PI / 2 * i;
	data->game->map.map[pos.y][pos.x] = '0';
	return (1);
}
