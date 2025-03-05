/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:11:35 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/16 21:20:07 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		x;
	int		a;
	char	*full;

	full = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!full)
		return (NULL);
	a = 0;
	i = 0;
	x = 0;
	while (s1[i] != '\0')
		full[a++] = s1[i++];
	while (s2[x] != '\0')
		full[a++] = s2[x++];
	full[a] = '\0';
	return (full);
}
/*#include <stdio.h>
int main ()
{
	printf("%s", ft_strjoin("sieeeemanko", "witamwmojejkuchni"));
	return (0);
}*/