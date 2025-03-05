/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:30:24 by wbardzin          #+#    #+#             */
/*   Updated: 2023/11/25 22:26:07 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*#include <stdio.h>
int main(void)
{
	printf("%li\n", ft_strlen("helloo"));
	return 0; 
}*/