/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 23:46:12 by bizcru            #+#    #+#             */
/*   Updated: 2026/10/03 12:31:33 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static e_line	get_line_type(char *str)
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

static int	parse_map()
{
	printf("parsing map...\n");
	return (1);
}

static int parse_fc()
{
	printf("parsing floor/ceiling...\n");
	return (1);
}

static int parse_wall()
{
	printf("parsing wall texture...\n");
	return (1);
}

static int	parse_line(t_parser *data)
{
	if (data->line_type == MAP)
	{
		if (data->parsed_elements < 6)
		{
			printf("%s%s", ERR, MAP_N_LAST);
			return (0);
		}
		if (!parse_map())
			return (0);
	}
	else if (data->line_type == FLOOR || data->line_type == SKY)
	{
		if (!parse_fc())
			return (0);
	}
	else
	{
		if (!parse_wall())
			return (0);
	}
	data->parsed_elements++;
	return (1);
}

void	read_scene_line(t_parser *data)
{
	data->line_type = get_line_type(data->line);
	printf("line type is: %i\n", data->line_type);
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
