/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:58:02 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/21 20:35:33 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substring;
	size_t	i;

	s_len = 0;
	if (s == NULL)
		return (NULL);
	while (s[s_len] != '\0')
		s_len++;
	if (start >= s_len)
		return (ft_calloc(1, 1));
	if (len > s_len - start)
		len = s_len - start;
	substring = malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[len] = '\0';
	return (substring);
}

/*#include "libft.h"
#include <stdio.h>

int main() {
    const char *s = "This is a test string";
    unsigned int start = 1;
    size_t len = 20;

    char *substring = ft_substr(s, start, len);

    if (substring != NULL) {
        printf("Substring: %s\n", substring);
        free(substring); // Zwolnienie pamięci po uzyskanym podłańcuchu
    } else {
        printf("Błąd: nie udało się uzyskać podłańcucha.\n");
    }

    return 0;
}*/