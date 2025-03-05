/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:31:09 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/16 21:24:27 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	c;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	c = dst_len;
	while (c + 1 < size && src[i] != '\0')
	{
		dst[c] = src[i];
		c++;
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*#include <stdio.h>
#include <string.h>
int main() {
    char destination[20] = "Hello, ";
    char source[] = "World!";

    size_t result = ft_strlcat(destination, source, sizeof(destination));

    printf("Skopiowano %zu bajtów\n", result);
    printf("dest: %s\n", destination);

    return 0;
	}*/