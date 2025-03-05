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
#include "../inc/so_long.h"

// Sprawdzenie, czy mapa jest prostokątna
int is_map_rectangular(char **map)
{
    int width;
    int i;
    int current_width;

    width = -1;
    i = 0;
    while (map[i])
    {
        current_width = 0;
        while (map[i][current_width])
            current_width++;
        if (width == -1)
            width = current_width;
        else if (width != current_width)
            return (0);
        i++;
    }
    return (1);
}
int	is_map_surrounded_by_walls(char **map)
{
	int	i;
	int	len;
	int	height;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	len = i;
	height = 0;
	while (map[height])
		height++;
	if (height <= 0)
		return (0);
	i = 0;
	while (i < len)
	{
		if (map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}



// Sprawdzenie poprawności elementów mapy
int check_elements(char **map)
{
    int player_count;
    int exit_count;
    int collectible_count;
    int y;
    int x;

    player_count = 0;
    exit_count = 0;
    collectible_count = 0;
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'P')
                player_count++;
            else if (map[y][x] == 'E')
                exit_count++;
            else if (map[y][x] == 'C')
                collectible_count++;
            x++;
        }
        y++;
    }
    if (player_count != 1 || exit_count != 1 || collectible_count < 1)
        return (0);
    return (1);
}

int is_map_playable(char **map)
{
    // Sprawdzenie, czy mapa jest prostokątna
    if (!is_map_rectangular(map))
    {
        printf("Error: Map is not rectangular\n");
        return (0);
    }
    
    // Sprawdzenie, czy mapa jest otoczona ścianami
    if (!is_map_surrounded_by_walls(map))
    {
        printf("Error: Map is not surrounded by walls\n");
        return (0);
    }
    
    // Sprawdzenie poprawności elementów mapy (gracz, wyjście, collectibles)
    if (!check_elements(map))
    {
        printf("Error: Missing or incorrect elements on the map\n");
        return (0);
    }

    // Upewnienie się, że mapa zawiera co najmniej jednego gracza (P), wyjście (E) i jeden collectible (C)
    int player_count = 0, exit_count = 0, collectible_count = 0;
    int y = 0;
    while (map[y])
    {
        int x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'P') player_count++;
            else if (map[y][x] == 'E') exit_count++;
            else if (map[y][x] == 'C') collectible_count++;
            x++;
        }
        y++;
    }

    if (player_count != 1)
    {
        printf("Error: Map must contain exactly one player (P)\n");
        return (0);
    }
    if (exit_count != 1)
    {
        printf("Error: Map must contain exactly one exit (E)\n");
        return (0);
    }
    if (collectible_count < 1)
    {
        printf("Error: Map must contain at least one collectible (C)\n");
        return (0);
    }

    // Jeśli wszystkie kontrole przeszły, mapa jest poprawna
    return (1);
}


// Funkcja tworząca duplikat mapy 2D (opcjonalnie, jeżeli potrzebujesz kopii dla flood_fill)
char **duplicate_map(char **map)
{
    char **copy;
    int i;

    i = 0;
    while (map[i])  // Zliczamy ilość wierszy w mapie
        i++;
    
    copy = malloc(sizeof(char *) * (i + 1));  // Alokujemy pamięć dla mapy
    if (!copy)  // Sprawdzamy, czy alokacja się powiodła
    {
        printf("Error: Memory allocation failed for map duplication\n");
        return (NULL);
    }

    i = 0;
    while (map[i])
    {
        copy[i] = ft_strdup(map[i]);  // Tworzymy kopię każdego wiersza mapy
        if (!copy[i])  // Sprawdzamy, czy alokacja się powiodła dla wiersza
        {
            printf("Error: Memory allocation failed for map row %d\n", i);
            free_map(copy);  // Zwalniamy już zaalokowaną pamięć
            return (NULL);
        }
        i++;
    }
    copy[i] = NULL;  // Dodajemy NULL na końcu tablicy
    return (copy);
}


// Inicjalizacja struktury valid (używane przed flood_fill)
void init_valid(t_valid *valid, char **map)
{
    int x;
    int y;

    valid->exit_found = 0;
    valid->collectibles_found = 0;
    valid->total_collectibles = 0;
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'P')
            {
                valid->player_x = x;
                valid->player_y = y;
            }
            else if (map[y][x] == 'C')
                valid->total_collectibles++;
            x++;
        }
        y++;
    }
}
#include "../inc/so_long.h"

// Funkcja do odczytu mapy z pliku z użyciem get_next_line
char *read_map_file(const char *filename)
{
    int     fd;
    char    *map;
    char    *line;
    char    *tmp;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (NULL);
    map = ft_strdup("");
    if (!map)
    {
        close(fd);
        return (NULL);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        tmp = ft_strjoin(map, line);
        free(map);
        free(line);
        if (!tmp)
        {
            close(fd);
            return (NULL);
        }
        map = tmp;
    }
    close(fd);
    return (map);
}

// Funkcja do konwersji mapy (string) na tablicę 2D
char **convert_to_2d_map(char *map_str)
{
    char **map;
    int i;
    int j;
    int len;
    int k;

    // Najpierw liczymy, ile linii mamy w mapie
    i = 0;
    j = 0;
    while (map_str[i])
    {
        if (map_str[i] == '\n')
            j++;
        i++;
    }
    map = malloc(sizeof(char *) * (j + 1));
    if (!map)
        return (NULL);
    i = 0;
    j = 0;
    while (map_str[i])
    {
        len = 0;
        while (map_str[i + len] && map_str[i + len] != '\n')
            len++;
        map[j] = malloc(sizeof(char) * (len + 1));
        if (!map[j])
            return (NULL);
        k = 0;
        while (k < len)
        {
            map[j][k] = map_str[i + k];
            k++;
        }
        map[j][k] = '\0';
        i += len;
        if (map_str[i] == '\n')
            i++;
        j++;
    }
    map[j] = NULL;
    return (map);
}

void free_map(char **map)
{
    int i;

    i = 0;
    while (map[i])  // Iterujemy przez wszystkie wiersze mapy
    {
        free(map[i]);  // Zwalniamy pamięć zajmowaną przez pojedynczy wiersz
        i++;
    }
    free(map);  // Zwalniamy pamięć zajmowaną przez tablicę wskaźników
}

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




