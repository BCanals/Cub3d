/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 13:37:38 by lartes-s          #+#    #+#             */
/*   Updated: 2026/10/09 20:55:16 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (printf("Error args\n"), 1);
	game = parser(ac, av);
	if (!game)
		exit(EXIT_FAILURE);
	run_mlx(game);
	clean_t_game(game);
	return (0);
}
