/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 16:13:35 by becanals          #+#    #+#             */
/*   Updated: 2026/10/27 21:55:32 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

// coordinates references: (0,0) is top left, only positive values.

static char	**copy_array(char **array)
{
	char	**copy;
	int		i;

	i = -1;
	while (array[++i])
		;
	copy = ft_calloc(sizeof(char *), i + 1);
	if (!copy)
		return (NULL);
	i = -1;
	while (array[++i])
	{
		copy[i] = strdup(array[i]);
		if (!copy[i])
		{
			ft_free_array(copy);
			return (NULL);
		}
	}
	return (copy);
}

static int	flood_fill(t_parser *data, int x, int y)
{
	if (!data->copy[y])
		return (0);
	if (ft_strlen(data->copy[y]) <= (unsigned int)x)
		return (0);
	if (data->copy[y][x] == ' ')
		return (0);
	if (data->copy[y][x] == '1')
		return (1);
	data->copy[y][x] = '1';
	if (y == 0 || x == 0)
		return (0);
	if (!flood_fill(data, x + 1, y))
		return (0);
	if (!flood_fill(data, x - 1, y))
		return (0);
	if (!flood_fill(data, x, y - 1))
		return (0);
	if (!flood_fill(data, x, y + 1))
		return (0);
	return (1);
}

int	flood_fill_check(t_parser *data)
{
	t_vint2	pos_ini;

	data->copy = copy_array(data->game->map.map);
	if (!data->copy)
	{
		printf("%s%s", ERR, MALL_ERR);
		return (0);
	}
	pos_ini = data->game->player.pos_int;
	data->copy[pos_ini.y][pos_ini.x] = '1';
	while (pos_ini.x >= 0)
	{
		if (!flood_fill(data, pos_ini.x, pos_ini.y))
			return (printf("%s%s", ERR, MAP_OPEN), 0);
		pos_ini = find_in_array(data->copy, '0');
	}
	return (1);
}
