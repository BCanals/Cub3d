/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 23:46:12 by bizcru            #+#    #+#             */
/*   Updated: 2026/09/29 00:42:35 by bizcru           ###   ########.fr       */
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


void	read_scene_line(t_parser *data)
{
	data->line_type = get_line_type(data->line);
	printf("line type is: %i\n", data->line_type);
}
