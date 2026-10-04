/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 16:24:06 by lartes-s          #+#    #+#             */
/*   Updated: 2026/10/04 16:37:22 by lartes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

t_vec2	*add_to_vec(t_vec2 *orig, t_vec2 *other)
{
	orig->x += other->x;
	orig->y += other->y;
	return (orig);
}

t_vec2	*subt_from_vec(t_vec2 *orig, t_vec2 *other)
{
	orig->x -= other->x;
	orig->y -= other->y;
	return (orig);
}

float	abs_vec(t_vec2 *vec)
{
	return (sqrt(vec->x * vec->x + vec->y * vec->y));
}

t_vec2	*normalize_vec(t_vec2 *vec)
{
	float	abs;

	abs = abs_vec(vec);
	vec->x /= abs;
	vec->y /= abs;
	return (vec);
}
