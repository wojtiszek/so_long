/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:35:31 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/16 21:55:25 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_isinset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_isinset(s1[end - 1], set))
		end--;
	trimmed = malloc(sizeof(char) * (end - start + 1));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, end - start + 1);
	return (trimmed);
}
/*
#include <stdio.h>
#include <stdlib.h>


int main() {
    // Przykładowe dane wejściowe
    const char *input_string = "   \t   Hello, World!   \t   ";
    const char *trim_set = " \t"; // Zestaw znaków do wycinania 
    // Wyświetlenie oryginalnego ciągu przed przycięciem
    printf("Original string: \"%s\"\n", input_string);

    // Wyświetlenie zestawu znaków do wycinania
    printf("Trim set: \"%s\"\n", trim_set);

    // Wywołanie funkcji ft_strtrim
    char *trimmed_string = ft_strtrim(input_string, trim_set);

    // Sprawdzenie, czy alokacja pamięci się powiodła
    if (trimmed_string == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Kod błędu
    }

    // Wyświetlenie przyciętego ciągu
    printf("Trimmed string: \"%s\"\n", trimmed_string);

    // Zwolnienie zaalokowanej pamięci
    free(trimmed_string);

    return 0; // Zwrócenie sukcesu
}*/