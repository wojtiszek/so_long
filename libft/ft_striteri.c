/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:40:53 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/16 19:15:23 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (*s)
	{
		f(i, s);
		s++;
		i++;
	}
}
/*
// Przykładowa funkcja, która zostanie użyta jako argument dla ft_striteri
void print_index_and_char(unsigned int index, char *c)
{
    printf("Character at index %d: %c\n", index, *c);
}

int main()
{
    char str[] = "Hello, World!";

    // Wywołanie funkcji ft_striteri z przykładową funkcją print_index_and_char
    ft_striteri(str, &print_index_and_char);

    return 0;
}*/