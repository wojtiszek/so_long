/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:36:45 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/02 00:36:51 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
	{
		return (0);
	}
	return (1);
}
/*#include <stdio.h>
int main(void)
{
	int c = '!';
	printf("%i\n", ft_isdigit(c));
	return 0; 
}*/
