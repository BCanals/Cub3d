/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 17:50:26 by lartes-s          #+#    #+#             */
/*   Updated: 2026/09/24 19:00:07 by lartes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return(printf("Error args\n"), 1);
	init_structs(&game);
	run_mlx(&game);
	free_structs(&game);
	return (0);
}