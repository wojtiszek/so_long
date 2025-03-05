/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:52:13 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/15 23:02:26 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

/*int main() {
    char *message = "Hello, world!";
    int file_descriptor = 1; // 1 for standard output (stdout)
    
    ft_putstr_fd(message, file_descriptor);
    
    return 0;
}*/