/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 16:24:06 by lartes-s          #+#    #+#             */
/*   Updated: 2026/10/04 16:25:06 by lartes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

include "../../inc/cub.h"

t_vec2	*add_to_vec(t_vec2 *orig, t_vec2 *other)
{
	orig->i += other->i;
	orig->j += other->j;
	return (orig);
}

t_vec2	*subt_from_vec(t_vec2 *orig, t_vec2 *other)
{
	orig->i -= other->i;
	orig->j -= other->j;
	return (orig);
}

float	abs_vec(t_vec2 *vec)
{
	return (sqrt(vec->i * vec->i + vec->j * vec->j));
}

t_vec2	*normalize_vec(t_vec2 *vec)
{
	float	abs;

	abs = abs_vec(vec);
	vec->i /= abs;
	vec->j /= abs;
	return (vec);
}
