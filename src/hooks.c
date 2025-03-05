#include "../inc/so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
    if (keycode == 65307) // ESC - Wyjście z gry
    {
        mlx_destroy_window(game->mlx, game->win);
        exit(0);
    }
    else if (keycode == 97)  // A - Lewo
        move_player(game, -1, 0);
    else if (keycode == 100) // D - Prawo
        move_player(game, 1, 0);
    else if (keycode == 119) // W - Góra
        move_player(game, 0, -1);
    else if (keycode == 115) // S - Dół
        move_player(game, 0, 1);

    return (0);
}
