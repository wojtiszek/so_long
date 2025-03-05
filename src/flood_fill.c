#include "../inc/so_long.h"

// Rekurencyjna funkcja zalewająca (DFS)
void flood_fill(char **map, int x, int y, t_valid *valid)
{
    if (map[y][x] == '1' || map[y][x] == 'F')
        return;
    if (map[y][x] == 'E')
        valid->exit_found = 1;
    if (map[y][x] == 'C')
        valid->collectibles_found++;
    map[y][x] = 'F';
    flood_fill(map, x + 1, y, valid);
    flood_fill(map, x - 1, y, valid);
    flood_fill(map, x, y + 1, valid);
    flood_fill(map, x, y - 1, valid);
}
