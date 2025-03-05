/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:33:40 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/02 00:33:52 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_isalpha(int c)
{
	if (c < 'A' || ('Z' < c && c < 'a') || c > 'z')
	{
		return (0);
	}
	return (1);
}
/*#include <stdio.h>
int main(void)
{
	int c = '9';
	printf("%i\n", ft_isalpha(c));
	return 0; 
}*/
