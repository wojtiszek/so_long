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
