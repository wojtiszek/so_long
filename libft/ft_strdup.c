/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:08:54 by wbardzin          #+#    #+#             */
/*   Updated: 2024/03/16 21:16:29 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_cpy(char *str, char *dest)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;
	char	*str;

	str = (char *)s;
	i = ft_strlen(str);
	dest = malloc(sizeof(char) * i + 1);
	if (!(dest))
		return (NULL);
	return (str_cpy(str, dest));
}
/*#include <stdio.h>
int main()
{
	char	*t = "helloworld0000000000000000000";
	printf("%s", ft_strdup(t));
	return (0);
}*/
