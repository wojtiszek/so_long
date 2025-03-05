/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:08:45 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/21 20:35:52 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (in_word == 0)
			{
				in_word = 1;
				count++;
			}
		}
		else
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*result;
	size_t	i;

	result = NULL;
	result = (char *)malloc((n + 1) * sizeof(char));
	if (result)
	{
		i = 0;
		while (i < n && s[i] != '\0')
		{
			result[i] = s[i];
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}

static void	ft_free(char **split)
{
	int	j;

	j = 0;
	while (split[j])
	{
		free(split[j]);
		j++;
	}
	free(split);
}

static void	ft_splitstring( char **result, const char *s, char c)
{
	int				i;
	const char		*start;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			result[i] = ft_strndup(start, s - start);
			if (result[i] == NULL)
				ft_free(result);
			i++;
		}
		else
			s++;
	}
	result[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int			num_words;
	char		**result;

	result = NULL;
	num_words = count_words(s, c);
	result = malloc((num_words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	ft_splitstring(result, s, c);
	return (result);
}
/*#include <stdio.h>
int main() {
    // Przykładowy łańcuch znaków do podziału
    char const *s = "To jest przykładowy łańcuch znaków do podziału";

    // Separator, którym będziemy dzielić łańcuch
    char c = ' ';

    // Wywołanie funkcji ft_split
    char **result = ft_split(s, c);

    // Wyświetlenie wyników
    if (result) {
        printf("Podłańcuchy:\n");
        int i = 0;
        while (result[i] != NULL) {
            printf("%s\n", result[i]);
            //free(result[i]); // Zwolnienie pamięci każdego podłańcucha
            i++;
        }
        //free(result); // Zwolnienie pamięci tablicy wskaźników
    } else {
        printf("Błąd podczas dzielenia łańcucha.\n");
    }

    return 0;
}*/