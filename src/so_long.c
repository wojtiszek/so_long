#include "../inc/so_long.h"

int main(int argc, char **argv)
{
    char    *map_str;
    char    **map_2d;
    t_game  game;

    if (argc != 2)
    {
        printf("Usage: %s map.ber\n", argv[0]);
        return (1);
    }
    map_str = read_map_file(argv[1]);
    if (!map_str)
    {
        printf("Error: Failed to read map\n");
        return (1);
    }
    map_2d = convert_to_2d_map(map_str);
    free(map_str);
    if (!map_2d)
    {
        printf("Error: Failed to convert map\n");
        return (1);
    }
    if (!is_map_playable(map_2d))
    {
        free_map(map_2d);
        return (1);
    }
    
    game.map = map_2d;
    init_game(&game, game.map);
    load_textures(&game);
    render_map(&game);

    mlx_hook(game.win, 2, 1L<<0, key_hook, &game);
    mlx_loop(game.mlx);

    free_map(map_2d);
    return (0);
}