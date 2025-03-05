/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:55:39 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/15 22:49:41 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

/*// Przykładowe użycie funkcji ft_putchar_fd
int main() 
{
    char character = 'A'; // Przykładowy znak do wypisania
    int file_descriptor = STDOUT_FILENO; // )

    ft_putchar_fd(character, file_descriptor); // 
    return 0;
}*/
