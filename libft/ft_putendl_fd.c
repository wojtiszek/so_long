/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:20:53 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/16 15:01:28 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}
/*int main()
{
    char *message = "Hello, world!";
    int file_descriptor = STDOUT_FILENO; 

    ft_putendl_fd(message, file_descriptor);

    return 0;
}*/
