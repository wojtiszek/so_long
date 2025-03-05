/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:57:30 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/19 23:15:54 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*str;
	size_t				i;
	unsigned char		ch;

	ch = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>
// Declaration of the ft_memchr function
void *ft_memchr(const void *s, int c, size_t n);

int main() {
    // Sample data for testing with negative numbers
    char arr[] = {-10, -20, -30, -40, -50, -60, -70};
    int search_value1 = -30;
    int search_value2 = -80; // A value not present in the array

    size_t n = 3;

    // Using ft_memchr function on the array
    void *result1 = ft_memchr(arr, search_value1, n);
    void *result2 = ft_memchr(arr, search_value2, n);

    // Displaying results
    if (result1 != NULL) {
        printf("ft '%d'  %ld\n", search_value1, (char *)result1 - arr);
    } else {
        printf("ft_ did not '%d' in the array.\n", search_value1);
    }

    if (result2 != NULL) {
        printf("ft_ '%d' %ld\n", search_value2, (char *)result2 - arr);
    } else {
        printf("ft_memchr: Did not find '%d' in the array.\n", search_value2);
    }

    return 0;
}*/
