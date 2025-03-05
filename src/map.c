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

