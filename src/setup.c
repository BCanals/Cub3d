/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lartes-s <lartes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 13:38:19 by lartes-s          #+#    #+#             */
/*   Updated: 2026/10/04 17:44:16 by lartes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	init_player(t_player *player)
{
	player->pos.x = 2.5f;
	player->pos.y = 2.5f;
	player->dir = 0.0f;
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

void	init_walls(t_game *game)
{
	int i = -1;
	while (++i < 4)
		game->walls[i] = NULL;
}

void	init_structs(t_game *game)
{
	game->map.no = ft_strdup("./textures/north.png");
	game->map.so = ft_strdup("./textures/south.png");
	game->map.ea = ft_strdup("./textures/east.png");
	game->map.we = ft_strdup("./textures/west.png");

	game->map.map = create_dummy_map();
	game->map.n_cols = 10;
	game->map.n_rows = 8;

	game->map.floor.r = 255;
	game->map.floor.g = 149;
	game->map.floor.b = 231;

	game->map.sky.r = 162;
	game->map.sky.g = 197;
	game->map.sky.b = 255;

	init_player(&game->player);
	init_walls(game);

	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->data = NULL;
	game->bpp = 0;
	game->size_line = 0;
	game->endian = 0;
}
