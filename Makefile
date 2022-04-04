# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcattini <dcattini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 13:26:20 by dcattini          #+#    #+#              #
#    Updated: 2022/03/29 17:42:49 by dcattini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = gcc
CFLAG = -Wall -Werror -Wextra -I.

CFILES = ft_printf.c ft_putstr.c ft_putnbr.c ft_putchar.c ft_putnb_base16.c ft_putnbrun.c ft_putpoiter.c\


OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	@echo "libftprintf.a is ok"

%.o: %.c
	$(CC) $(CFLAG) -c -o $@ $^

clean:
	rm -rf $(OBJECTS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all %.o clean fclean re
