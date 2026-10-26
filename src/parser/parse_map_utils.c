/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 20:18:17 by becanals          #+#    #+#             */
/*   Updated: 2026/10/23 16:24:14 by lartes-s         ###   ########.fr       */
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

static void	find_player(t_game *game, char c, int *count, t_vint2 *pos)
{
	int		i;
	int		j;

	i = -1;
	while (game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (game->map.map[i][j] == c)
			{
				*count += 1;
				game->player.c = c;
				pos->x = j;
				pos->y = i;
			}
		}
	}
}

void	set_direction(t_player *player)
{
	if (player->c == 'N')
		player->dir = PI + PI_2;
	if (player->c == 'S')
		player->dir = PI_2;
	if (player->c == 'E')
		player->dir = 0;
	if (player->c == 'W')
		player->dir = PI;
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
		find_player(data->game, chars[i], &players, &pos);
	if (players == 0)
		return (printf("%s%s", ERR, MAP_NO_PLAYER), 0);
	if (players > 1)
		return (printf("%s%s%i\n", ERR, MAP_TWO_PLAYERS, players), 0);
	data->game->player.pos.x = pos.x + 1.5f;
	data->game->player.pos.y = pos.y + 1.5f;
	set_direction(&data->game->player);
	data->game->map.map[pos.y][pos.x] = '0';
	return (1);
}
