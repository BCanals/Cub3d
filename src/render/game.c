
#include "../../inc/cub.h"

void    init_game(t_game *game)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, 1200, 720, "Game");
    game->img = mlx_new_image(game->mlx, 1200, 720);
}

int main(void)
{
    t_game  game;

    init_game(&game);
    mlx_loop(game.mlx);

    return (0);
}