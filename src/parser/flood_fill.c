/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becanals <becanals@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 16:13:35 by becanals          #+#    #+#             */
/*   Updated: 2026/10/04 19:51:41 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

// coordinates references: (0,0) is top left, only positive values.
/*
static int	flood_fill(t_parser *data, int x, int y)
{
	if (check
}
*/
int	flood_fill_check(t_parser *data)
{
	if (data)
		return (1);
	return (0);
}
