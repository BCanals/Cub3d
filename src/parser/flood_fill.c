/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 16:13:35 by becanals          #+#    #+#             */
/*   Updated: 2026/10/08 20:58:27 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

// coordinates references: (0,0) is top left, only positive values.

/*
static int	flood_fill(t_parser *data,t_vec2 pos);
{
	
}
*/


int	flood_fill_check(t_parser *data)
{
	if (data)
		return (1);
	return (0);
/*
	ft_print_array(data);
	t_vec2	pos_ini;

	pos_ini = get_empty_cell(data)
	while (pos_ini.x >= 0)
	{
		if (!flood_fill(pos_ini))
		{
			printf("%s%s", ERR, MAP_OPEN);
			break ;
		}
		pos_ini = get_empty_cell(data);
	}
	if (pos_ini.x >=0)
		return (0);
	return (1);
*/
}
