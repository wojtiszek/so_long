#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../minilibx-linux/mlx.h"  // MLX do grafiki

typedef struct s_valid
{
    int exit_found;
    int collectibles_found;
    int total_collectibles;
    int player_x;
    int player_y;
}   t_valid;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    char    **map;
    int     map_width;
    int     map_height;
    int     tile_size;
    void    *img_wall;
    void    *img_floor;
    void    *img_player;
    void    *img_exit;
    void    *img_collectible;
    int     player_x;  // Pozycja gracza w mapie (kolumna)
    int     player_y;  // Pozycja gracza w mapie (wiersz)
    int     collectibles;  // Liczba collectibles na mapie
}   t_game;

/* Deklaracje funkcji: */
int     main(int argc, char **argv);
char    *read_map_file(const char *filename);
char    **convert_to_2d_map(char *map_str);
void    free_map(char **map);
void    init_valid(t_valid *valid, char **map);
void    flood_fill(char **map, int x, int y, t_valid *valid);
int     is_map_playable(char **map);

/* Funkcje MLX: */
void    init_game(t_game *game, char **map);
void    load_textures(t_game *game);
void    render_map(t_game *game);
int     key_hook(int keycode, t_game *game);
void	move_player(t_game *game, int dx, int dy);
void count_collectibles(t_game *game);
#endif
