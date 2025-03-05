/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:33:44 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/16 20:53:26 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d > s)
	{
		i = n;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (dest);
}

/*int main() {
    char source[] = "Hello, World!";
    char destination[20];

    // Użyj wbudowanej funkcji memmove do skopiowania source do destination
    memmove(destination, source, sizeof(source));

    // Wydrukuj wartość destination przed użyciem ft_memmove
    printf("Przed ft_memmove: %s\n", destination);

    // Użyj naszej funkcji ft_memmove
    ft_memmove(destination + 7, source, 7);

    // Wydrukuj wartość destination po użyciu ft_memmove
    printf("Po ft_memmove: %s\n", destination);

    return 0;
}*/	