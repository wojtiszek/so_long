/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:26:38 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/16 21:27:47 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	while ((i < (size - 1)) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
/*#include "libft.h"
#include <string.h>
#include <stdio.h> // Dodane w celu użycia printf do testowania

int main(void)
{
    // Przykładowe dane wejściowe
    const char *source = "Hello, world!";
    size_t size = 0;

    // Test funkcji ft_strlcpy
    char dest_ft[20];
    size_t result_ft = ft_strlcpy(dest_ft, source, size);
    printf("ft_strlcpy result: %zu, destination: \"%s\"\n", result_ft, dest_ft);


    return 0;
}*/