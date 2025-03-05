/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:26:51 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/21 20:11:22 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;

	if (size && (4294967295 / size < nmemb))
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr != NULL)
		ft_memset(ptr, 0, total_size);
	return (ptr);
}
/*#include <stdio.h>
int main()
{
    // Przykładowe dane
    size_t num_elements = 5;
    size_t element_size = sizeof(int);

    // Alokuj pamięć dla tablicy 5 elementów typu int, zainicjalizowanych zerami
    int *array = (int *)ft_calloc(num_elements, element_size);

    if (array != NULL)
	{
        // Wypełnij tablicę danymi
        //size_t i = 0;
        //while (i < num_elements)
		//{
        //    array[i] = i + 1;  // Przykładowe dane (1, 2, 3, 4, 5)
        //    i++;
        //}

        // Wyświetl zawartość tablicy w terminalu
        printf("Zawartość tablicy:\n");
        size_t j = 0;
        while (j < num_elements) {
            printf("%d ", array[j]);
            j++;
        }
        printf("\n");

        // Zwolnij zaalokowaną pamięć
        free(array);
    }
    return 0;
}*/