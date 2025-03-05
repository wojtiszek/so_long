# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbardzin <wbardzin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 22:30:06 by wbardzin          #+#    #+#              #
#    Updated: 2024/04/11 22:33:00 by wbardzin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = libftprintf.a

SRCS = ft_printf.c print_hexa.c print_int.c print_ptr.c print_string.c print_uns.c ft_putchar_fd.c
OBJS = $(SRCS:.c=.o)


$(NAME): $(OBJS)
	ar rcs $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
