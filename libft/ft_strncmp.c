/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:53:38 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/16 22:05:46 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n)
		i++;
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
/*#include <stdio.h>
#include <string.h>
 //Two helper functions to display the results of strncmp and ft_strncmp
void test_strncmp(char *s1, char *s2, size_t n) {
    int result = strncmp(s1, s2, n);
    printf("strncmp(\"%s\", \"%s\", %zu) = %d\n", s1, s2, n, result);
}

void test_ft_strncmp(char *s1, char *s2, unsigned int n) {
    int result = ft_strncmp(s1, s2, n);
    printf("ft_strncmp(\"%s\", \"%s\", %u) = %d\n", s1, s2, n, result);
}
int main() 
{
    // Test cases
    char str1[] = "Hello";
    char str2[] = "Hell";
    char str3[] = "Hello";
    char str4[] = "Hella";

    size_t n = 8;
    printf("Testing with strncmp:\n");
    test_strncmp(str1, str2, n);
    test_strncmp(str1, str3, n);
    test_strncmp(str1, str4, n);

    printf("\nTesting with ft_strncmp:\n");
    test_ft_strncmp(str1, str2, n);
    test_ft_strncmp(str1, str3, n);
    test_ft_strncmp(str1, str4, n);

    return 0;
}*/