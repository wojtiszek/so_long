/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 00:23:57 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/16 21:03:27 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*include <stdio.h>
int main() {
    char str[] = "Hello, World!";
    
    printf("Przed: %s\n", str);

    // Ustawiamy pierwsze 5 znaków na 'A' za pomocą ft_memset
    ft_memset(str, 'A', 5);

    printf("Po: %s\n", str);

    return 0;
}*/