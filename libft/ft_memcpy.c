/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:38:48 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/04 18:38:52 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*#include <stdio.h>
#include <string.h>
int main() {
    char source[] = "Hello, World!";
    char destination[] = "Eloooooooooooooooooooooooooooo";

    // Wydrukuj wartość destination przed użyciem ft_memcpy
    printf("Przed ft_memcpy: %s\n", destination);

    // Użyj naszej funkcji ft_memcpy
    ft_memcpy(destination, source, sizeof(source));

    // Wydrukuj wartość destination po użyciu ft_memcpy
    printf("Po ft_memcpy: %s\n", destination);

    return 0;
}*/