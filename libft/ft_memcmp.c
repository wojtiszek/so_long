/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:42:41 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/16 20:23:43 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	unsigned int	i;

	if (n == 0)
		return (0);
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while (ss1[i] == ss2[i] && i < n)
	{
		i++;
	}
	if (i < n)
	{
		return (ss1[i] - ss2[i]);
	}
	return (0);
}
/*
void	ft_print_result(int n)
{
	if (n > 0)
		write(1, "1", 1);
	else if (n < 0)
		write(1, "-1", 2);
	else
		write(1, "0", 1);
}

int		main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		ft_print_result(ft_memcmp("salut", "salut", 5));
		ft_print_result(memcmp("salut", "salut", 5));
	}
	else if (arg == 2)
	{	ft_print_result(ft_memcmp("t\200", "t\0", 2));
		ft_print_result(memcmp("t\200", "t\0", 2));
	}
	else if (arg == 3)
	{	ft_print_result(ft_memcmp("testss", "test", 5));
		ft_print_result(memcmp("testss", "test", 5));
	}
	else if (arg == 4)
	{	ft_print_result(ft_memcmp("test", "tEst", 4));
		ft_print_result(memcmp("test", "tEst", 4));
	}
	else if (arg == 5)
	{	ft_print_result(ft_memcmp("", "test", 4));
		ft_print_result(memcmp("", "test", 4));
	}
	else if (arg == 6)
	{	ft_print_result(ft_memcmp("test", "", 4));
		ft_print_result(memcmp("test", "", 4));
	}
	else if (arg == 7)
	{	ft_print_result(ft_memcmp("abcdefghij", "abcdefgxyz", 7));
		ft_print_result(memcmp("abcdefghij", "abcdefgxyz", 7));
	}
	else if (arg == 8)
	{	ft_print_result(ft_memcmp("abcdefgh", "abcdwxyz", 6));
		ft_print_result(memcmp("abcdefgh", "abcdwxyz", 6));
	}
	else if (arg == 9)
	{	ft_print_result(ft_memcmp("zyxbcdefgh", "abcdefgxyz", 0));
		ft_print_result(memcmp("zyxbcdefgh", "abcdefgxyz", 0));
	}
	return (0);
}*/