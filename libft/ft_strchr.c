/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:48:59 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/19 23:16:18 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*ss;
	unsigned char	ch;

	ss = (unsigned char *)s;
	ch = (unsigned char)c;
	while (*ss != '\0')
	{
		if (*ss == ch)
			return ((char *)ss);
		ss++;
	}
	if ((char)ch == '\0')
		return ((char *)ss);
	return (NULL);
}
/*int main() {
    const char *str = "Hello, World!";
    int ch = 'o';

    char *result = ft_strchr(str, ch);

    if (result != NULL) {
        printf("Znaleziono znak '%c' w ciągu 
        na pozycji: %ld\n", ch, result - str);
    } else {
        printf("Znak '%c' nie został znaleziony w ciągu.\n", ch);
    }

    return 0;
}*/
