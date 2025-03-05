/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:20:02 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/03 23:20:04 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
	{
		return (1);
	}
	return (0);
}
/*#include <stdio.h>
int main(void)
{
	int c = '!';
	printf("%i\n", ft_isalnum(c));
	return 0; 
}*/
