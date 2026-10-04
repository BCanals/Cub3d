/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 19:58:47 by lartes-s          #+#    #+#             */
/*   Updated: 2026/10/02 20:06:48 by lartes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"


float	angle_from_x(int x)
{
	float	normal_x;
	float	plane_size;
	int		plane_dist;

	plane_dist = 3;
	normal_x = ((float)x * 2) / WIDTH - 0.5;
	plane_size = plane_dist * tan(PI / 2) * 2;
	return(atan2f(normal_x, plane_size));
}
