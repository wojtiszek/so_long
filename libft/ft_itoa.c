/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:56:09 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/21 20:09:53 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_digits(int n)
{
	int	count;

	count = 0;
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	count++;
	return (count);
}

static char	*ft_help(char *result, int n, int sign, int num_digits)
{
	int	i;

	i = num_digits - 1;
	while (i >= sign)
	{
		result[i--] = '0' + (n % 10);
		n /= 10;
	}
	result[num_digits] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	int		num_digits;
	char	*result;
	int		sign;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		sign = 1;
	}
	num_digits = get_num_digits(n) + sign;
	result = malloc((num_digits + 1) * sizeof(char));
	if (sign == 1)
		result[0] = '-';
	if (!result)
		return (NULL);
	result = ft_help(result, n, sign, num_digits);
	return (result);
}
/*#include <stdio.h>
int main(void) {
    // Test cases
    int num1 = 	2147483647;
    int num2 = -2147483646;
    int num3 = 0;

    char *str1 = ft_itoa(num1);
    char *str2 = ft_itoa(num2);
    char *str3 = ft_itoa(num3);

    // Print the results
    printf("Integer: %d, String: %s\n", num1, str1);
    printf("Integer: %d, String: %s\n", num2, str2);
    printf("Integer: %d, String: %s\n", num3, str3);

    // Remember to free the allocated memory
    free(str1);
    free(str3);

    return 0;

}*/