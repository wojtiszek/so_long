/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 23:31:46 by wbardzin          #+#    #+#             */
/*   Updated: 2024/04/19 20:59:10 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_specificator(char format, va_list args)
{
	char	*str;

	if (format == '%')
		return (write(1, "%", 1));
	else if (format == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (format == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			return (write(1, "(null)", 6));
		else
			return (print_string(str));
	}
	else if (format == 'p')
		return (print_ptr(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (print_int(va_arg(args, int)));
	else if (format == 'u')
		return (print_uns(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (print_hexa(va_arg(args, unsigned int), false));
	else if (format == 'X')
		return (print_hexa(va_arg(args, unsigned int), true));
	return (0);
}

int	ft_printf(const char *form, ...)
{
	int		i;
	int		len;
	va_list	args;

	if (!form)
		return (0);
	i = 0;
	len = 0;
	va_start(args, form);
	while (form[i])
	{
		if (form[i] == '%')
		{
			i++;
			len += check_specificator(form[i], args);
		}
		else
			len += write(1, &form[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
/*int main()
{
	//char *null_str = NULL;
    ft_printf("%p%p\n",0,0);
    ft_printf("%s\n", "siemka");
    ft_printf("%p\n", -10);
    ft_printf("\n%d\n", -12345);
    ft_printf("%u\n", 4294967295);
    ft_printf("%x\n", 255);
    ft_printf("%X\n", 255);
    
    return 0;
}*/
