/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 23:46:12 by bizcru            #+#    #+#             */
/*   Updated: 2026/10/09 20:10:29 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

e_line	get_line_type(char *str)
{
	while (*str && *str == ' ')
		str++;
	if (!str)
		return (ERROR);
	if (*str == '1' || *str == '0')
		return (MAP);
	if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
		return (TEX_N);
	if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
		return (TEX_S);
	if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
		return (TEX_O);
	if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
		return (TEX_E);
	if (str[0] == 'F' && str[1] == ' ')
		return (FLOOR);
	if (str[0] == 'C' && str[1] == ' ')
		return (SKY);
	return (ERROR);
}

static int	parse_line(t_parser *data)
{
	if (data->line_type == MAP)
	{
		if (ft_strlen(data->parsed_elements) < 6)
		{
			printf("%s%s", ERR, MAP_N_LAST);
			return (0);
		}
		if (!parse_map(data))
			return (0);
	}
	else if (data->line_type == FLOOR || data->line_type == SKY)
	{
		if (!parse_fc(data))
			return (0);
	}
	else
	{
		if (!parse_wall(data))
			return (0);
	}
	data->parsed_elements[data->line_type] = 'x';
	return (1);
}

void	read_scene_line(t_parser *data)
{
	data->line_type = get_line_type(data->line);
	if (data->line_type == ERROR)
	{
		printf ("Error\nUndefined line type at: %s", data->line);
		return ;
	}
	if (!parse_line(data))
	{
		data->line_type = ERROR;
		return ;
	}
}
