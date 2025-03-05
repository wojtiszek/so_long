/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:38:02 by wbardzin          #+#    #+#             */
/*   Updated: 2024/04/11 22:26:08 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hexa_digits(unsigned int n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		digits += 1;
		n /= 16;
	}
	return (digits);
}

static void	put_hexa(unsigned int nbr, bool upper)
{
	static char	upper_digits[] = "0123456789ABCDEF";
	static char	lower_digits[] = "0123456789abcdef";

	if (nbr >= 16)
		put_hexa((nbr / 16), upper);
	if (upper == true)
		write(1, &upper_digits[nbr % 16], 1);
	else
		write(1, &lower_digits[nbr % 16], 1);
}

int	print_hexa(unsigned int nbr, bool upper)
{
	put_hexa(nbr, upper);
	return (hexa_digits(nbr));
}
