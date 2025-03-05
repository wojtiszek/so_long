/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:16:09 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/16 21:03:43 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;
	unsigned char	c;

	i = 0;
	ptr = (unsigned char *)s;
	c = '\0';
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
}
/*#include <stdio.h>
#include <string.h>
int main() {
    char buffer[10];

    // Używamy wbudowanej funkcji memset do ustawienia buffer na wartość 1
    memset(buffer, 1, sizeof(buffer));

    // Wydrukujmy wartości przed użyciem ft_bzero
    printf("Przed ft_bzero: ");
    size_t i = 0;
    while (i < sizeof(buffer)) {
        printf("%d ", buffer[i]);
        i++;
    }
    printf("\n");

    // Użyjmy naszej funkcji ft_bzero
    ft_bzero(buffer, sizeof(buffer));

    // Wydrukujmy wartości po użyciu ft_bzero
    printf("Po ft_bzero: ");
    i = 0;
    while (i < sizeof(buffer)) {
        printf("%d ", buffer[i]);
        i++;
    }
    printf("\n");

    return 0;
}*/