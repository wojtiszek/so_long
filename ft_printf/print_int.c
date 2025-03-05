/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:47:27 by wbardzin          #+#    #+#             */
/*   Updated: 2024/04/18 18:24:32 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "printf.h"
#include <unistd.h>

static int	get_num_digits(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count = 1;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	count++;
	return (count);
}

static void	recursive(int n)
{
	static char	digits[] = "0123456789";

	if (n > 9)
		recursive(n / 10);
	write(1, &digits[n % 10], 1);
}

int	print_int(int n)
{
	int	len;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	len = get_num_digits(n);
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	recursive(n);
	return (len);
}
/*
//#include "printf.h" // Załóżmy, że masz plik nagłówkowy printf.h

int main() {
	int number = -1432423423;

	// Wywołanie funkcji print_int
	int printed_chars = print_int(number);

	// Wyświetlenie liczby znaków wypisanych przez print_int
	write(1, "\nNumber of characters printed: ", 31); 
	print_int(printed_chars);

	return 0;
}*/
