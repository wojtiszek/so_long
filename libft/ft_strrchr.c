/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:06:53 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/19 23:16:23 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*last_occurrence;
	unsigned char	ch;

	last_occurrence = NULL;
	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			last_occurrence = s;
		s++;
	}
	if (c == '\0')
		last_occurrence = s;
	return ((char *)last_occurrence);
}

/*#include <stdio.h>
#include <string.h>
int main() 
{
    const char *str = "bonjourb";
    int ch = 'b';

    char *result = ft_strrchr(str, ch);


    if (result != NULL) {
        printf("Znak '%c' p: %ld\n", ch, result - str);
    } else {
        printf("Znak '%c' nie został znaleziony w ciągu.\n", ch);
    }
	printf(" strrchr\n %s \n", strrchr(str, ch));
	printf(" ft_strrchr\n %s \n", strrchr(str, ch));


    return 0;
}*/