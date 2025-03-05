/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:49:05 by wbardzin          #+#    #+#             */
/*   Updated: 2024/04/11 22:26:54 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	deci_digits(unsigned int n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		digits += 1;
	}
	return (digits);
}

void	put_unsigned(unsigned int nbr)
{
	static char	digits[] = "0123456789";

	if (nbr > 9)
		put_unsigned(nbr / 10);
	write(STDOUT_FILENO, &digits[nbr % 10], 1);
}

int	print_uns(unsigned int nbr)
{
	put_unsigned(nbr);
	return (deci_digits(nbr));
}
