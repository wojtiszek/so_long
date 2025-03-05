/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:31:09 by wbardzin          #+#    #+#             */
/*   Updated: 2024/04/19 20:56:08 by wbardzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdio.h"
# include "stdarg.h"
# include "unistd.h"
# include "stdbool.h"
# include "unistd.h"

int			ft_printf(const char *form, ...);
int			print_hexa(unsigned int nbr, bool upper);
int			print_ptr(void *addr);
int			print_string(char const	*str);
int			print_uns(unsigned int nbr);
int			print_int(int n);
int			ft_putchar_fd(char c, int fd);

#endif