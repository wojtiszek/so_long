#include "../inc/so_long.h"

void move_player(t_game *game, int dx, int dy)
{
    int new_x = game->player_x + dx;
    int new_y = game->player_y + dy;

    // Sprawdzenie, czy nowa pozycja nie wychodzi poza zakres mapy
    if (new_x < 0 || new_x >= game->map_width || new_y < 0 || new_y >= game->map_height)
        return;  // Jeśli pozycja jest poza mapą, nie robimy nic

    // Sprawdzenie, czy nowa pozycja nie jest ścianą
    if (game->map[new_y][new_x] == '1')
        return;  // Jeśli nowa pozycja to ściana, nie robimy nic

    // Jeśli gracz wejdzie w collectible, zmniejszamy liczbę collectibles i usuwamy je z mapy
    if (game->map[new_y][new_x] == 'C')
    {
        game->collectibles--;
        game->map[new_y][new_x] = '0';  // Usuwamy collectible z mapy
    }

    // Sprawdzenie, czy gracz dotarł do wyjścia
    if (game->map[new_y][new_x] == 'E')
    {
        // Jeśli gracz zebrał wszystkie collectibles, może opuścić poziom
        if (game->collectibles == 0)
        {
            printf("🎉 Congratulations! You won the game! 🎉\n");
            exit(0);  // Zakończenie gry
        }
        else
        {
            // Jeśli nie zebrał wszystkich collectibles, nie pozwalamy mu wejść w drzwi
            printf("🚪 The exit is locked! Collect all collectibles first!\n");
            return;
        }
    }

    // Przemieszczamy gracza na nową pozycję
    game->map[game->player_y][game->player_x] = '0';  // Zwalniamy starą pozycję
    game->map[new_y][new_x] = 'P';  // Ustawiamy gracza w nowym miejscu
    game->player_x = new_x;
    game->player_y = new_y;

    // Renderowanie nowej klatki
    render_map(game);
}

