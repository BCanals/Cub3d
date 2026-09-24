/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 18:45:00 by lartes-s          #+#    #+#             */
/*   Updated: 2026/09/24 18:42:19 by lartes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	init_player(t_player *player)
{
	player->pos_x = 4.5f;
	player->pos_y = 3.5f;
	player->dir = 0.0f; // 0 radians (mirant cap a l'est / dreta)
}

static char	**create_dummy_map(void)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * 9);
	if (!map)
		return (NULL);
	map[0] = ft_strdup("1111111111");
	map[1] = ft_strdup("1000000001");
	map[2] = ft_strdup("1011001101");
	map[3] = ft_strdup("1000000001");
	map[4] = ft_strdup("1001111001");
	map[5] = ft_strdup("1000000001");
	map[6] = ft_strdup("1000000001");
	map[7] = ft_strdup("1111111111");
	map[8] = NULL;

	// Comprovació en cas que algun ft_strdup falli
	i = 0;
	while (i < 8)
	{
		if (!map[i])
			return (NULL);
		i++;
	}
	return (map);
}

void	init_structs(t_game *game)
{
	// Inicialització de punters de textures (per ara a NULL fins al parsing)
	game->map.tex_n = NULL;
	game->map.tex_s = NULL;
	game->map.tex_e = NULL;
	game->map.tex_o = NULL;

	// Dimensions del mapa de prova (8 files x 10 columnes)
	game->map.n_rows = 8;
	game->map.n_cols = 10;
	game->map.map = create_dummy_map();

	// Colors de terra (marró fosc/gris) i sostre (blau cel)
	game->map.floor.r = 75;
	game->map.floor.g = 75;
	game->map.floor.b = 75;

	game->map.sky.r = 135;
	game->map.sky.g = 206;
	game->map.sky.b = 235;

	// Jugador
	init_player(&game->player);

	// MiniLibX i buffer d'imatge
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->data = NULL;
	game->bpp = 0;
	game->size_line = 0;
	game->endian = 0;
}