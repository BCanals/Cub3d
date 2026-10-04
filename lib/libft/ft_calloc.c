/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:13:14 by bcanals-          #+#    #+#             */
/*   Updated: 2026/10/04 17:23:44 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*rtrn;

	rtrn = malloc(nmemb * size);
	if (rtrn == NULL)
		return (NULL);
	ft_bzero(rtrn, nmemb * size);
	return (rtrn);
}
