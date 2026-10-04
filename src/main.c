/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 13:37:38 by lartes-s          #+#    #+#             */
/*   Updated: 2026/10/04 13:38:02 by lartes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	main(int ac, char **av)
{
	t_game	game;

	(void)av;
	if (ac != 2)
		return(printf("Error args\n"), 1);
	init_structs(&game);
	run_mlx(&game);
	free_structs(&game);
	return (0);
}
