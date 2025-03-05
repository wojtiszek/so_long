/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:38:43 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/05 23:38:46 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	unsigned int	result;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == '\n' || nptr[i] == ' ' || nptr[i] == '\t'
		|| nptr[i] == '\r' || nptr[i] == '\f' || nptr[i] == '\v')
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i + 1] == '-' || nptr[i + 1] == '+')
			return (0);
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
/*#include <stdlib.h>
#include <stdio.h>
int main() {
    char    *str = "  ++++----1234ab567"; // 
    int number = ft_atoi(str); // 

    printf("Liczba to: %d\n", number); // W
    printf("Liczba to: %d\n", atoi(str)); // W

    return 0;
}*/	