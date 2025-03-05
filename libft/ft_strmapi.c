/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:08:23 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/16 19:07:41 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*result;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[len] = '\0';
	return (result);
}
/*
#include "libft.h"
#include <stdio.h>

char transform(unsigned int index, char c)
{
    if (index % 2 == 0) // Przekształcamy tylko znaki na parzystych pozycjach
    {
        if (c >= 'a' && c <= 'z')
            return c - 32; // Zamiana na wielką literę
    }
    return c; // Zwracamy znak bez zmiany dla pozostałych przypadków
}

int main()
{
    const char *input = "Hello World";
    char *result = ft_strmapi(input, &transform);

    if (result != NULL)
    {
        printf("Original string: %s\n", input);
        printf("Transformed string: %s\n", result);

        free(result);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
*/