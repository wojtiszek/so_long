#include "../inc/so_long.h"

void load_textures(t_game *game)
{
    int img_width;
    int img_height;

    game->img_wall = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm",
            &img_width, &img_height);
    game->img_floor = mlx_xpm_file_to_image(game->mlx, "images/floor.xpm",
            &img_width, &img_height);
    game->img_player = mlx_xpm_file_to_image(game->mlx, "images/player.xpm",
            &img_width, &img_height);
    game->img_exit = mlx_xpm_file_to_image(game->mlx, "images/exit.xpm",
            &img_width, &img_height);
    game->img_collectible = mlx_xpm_file_to_image(game->mlx, "images/collectible.xpm",
            &img_width, &img_height);
    if (!game->img_wall || !game->img_floor || !game->img_player ||
        !game->img_exit || !game->img_collectible)
    {
        printf("Error loading textures\n");
        exit(1);
    }
}
#include "so_long.h"

void render_map(t_game *game)
{
    int x, y;

    // Czyścimy ekran przed rysowaniem nowej klatki
    mlx_clear_window(game->mlx, game->win);

    // Rysujemy mapę
    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * game->tile_size, y * game->tile_size);
            else if (game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, x * game->tile_size, y * game->tile_size);
            else if (game->map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * game->tile_size, y * game->tile_size);
            else
                mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * game->tile_size, y * game->tile_size);
            x++;
        }
        y++;
    }

    // Rysujemy postać gracza na końcu, aby była na wierzchu
    mlx_put_image_to_window(game->mlx, game->win, game->img_player, game->player_x * game->tile_size, game->player_y * game->tile_size);
}


int key_hook(int keycode, t_game *game)
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

