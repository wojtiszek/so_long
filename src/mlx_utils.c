#include "../inc/so_long.h"

void find_player_position(t_game *game)
{
    int x, y;

    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            if (game->map[y][x] == 'P') // Jeśli znaleziono gracza
            {
                game->player_x = x;
                game->player_y = y;
                return;
            }
            x++;
        }
        y++;
    }
}
void count_collectibles(t_game *game)
{
    int x, y;

    game->collectibles = 0; // Resetujemy licznik

    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            if (game->map[y][x] == 'C')
                game->collectibles++;
            x++;
        }
        y++;
    }
    printf("DEBUG: Liczba collectibles: %d\n", game->collectibles);
}

void set_player_start_position(t_game *game)
{
    int x, y;

    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            if (game->map[y][x] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
                return;
            }
            x++;
        }
        y++;
    }
}

void init_game(t_game *game, char **map)
{
    int i;

    game->tile_size = 64;

    i = 0;
    while (map[i])
        i++;
    game->map_height = i;
    game->map_width = ft_strlen(map[0]);

    game->mlx = mlx_init();
    if (!game->mlx)
    {
        printf("Error initializing MLX\n");
        exit(1);
    }

    game->win = mlx_new_window(game->mlx, 
                    game->map_width * game->tile_size,
                    game->map_height * game->tile_size, "so_long");
    if (!game->win)
    {
        printf("Error creating window\n");
        exit(1);
    }

    game->map = map;  // Przypisujemy mapę do struktury
    set_player_start_position(game);  // Dopiero teraz możemy ustawić pozycję gracza
    count_collectibles(game);  // Obliczamy liczbę collectibles
}



