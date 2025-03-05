/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:40:26 by wbardzin          #+#    #+#             */
/*   Updated: 2024/04/19 20:18:22 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	print_string(char const	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str == NULL)
	{
		write(1, "(nil)", 5);
		return (6);
	}
	else
	{
		write(1, str, i);
		return (i);
	}
}
/*#include <stdio.h> // Do debugowania
#include <stdlib.h> // Do zarządzania pamięcią

// Deklaracja funkcji print_strint	print_ptr(void *addr)ing
int print_string(char const *str);

int main() {
    // Przykładowy ciąg znaków
    char *my_string = "Hello, World!";

    // Wywołanie funkcji print_string
    int printed_chars = print_string(my_string);

    // Wypisanie liczby wydrukowanych znaków
    printf("\nLiczba wydrukowanych znaków: %d\n", printed_chars);

    return 0;
}*/