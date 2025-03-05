/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:39:10 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/16 21:49:49 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	while (*big && len)
	{
		i = 0;
		while (big[i] == little[i] && little[i] && i < len)
			i++;
		if (little[i] == '\0')
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
/*#include <stdio.h>
int main(void) {
    const char *big_string = "To be or not to be, that is the question.";
    const char *search_string = "nor";

    // Ustawienie maksymalnej długości przeszukiwania na 10
    size_t max_length = 15;

    // Wywołanie funkcji ft_strnstr
    char *result = ft_strnstr(big_string, search_string, max_length);

    // Wyświetlenie wyniku
    if (result != NULL) {
        printf("Podciąg znaleziony: %s\n", result);
    } else {
        printf("Podciąg nie został znaleziony.\n");
    }

    return 0;
}*/