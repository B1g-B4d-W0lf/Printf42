# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 20:16:59 by wfreulon          #+#    #+#              #
#    Updated: 2023/01/25 22:52:09 by wfreulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC =	ft_printf.c addfunctions.c
HEADERFILES = ft_printf.h
OBJFILES = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJFILES)
	ar -rc $@ $^

all: $(NAME)

%.o: ft_%.c $(HEADERFILES)
	$(CC) -c $(CFLAGS) -o $@ $<
	
clean:
	rm -f $(OBJFILES)

fclean:
	rm -f $(NAME) $(OBJFILES)

re: fclean all

.PHONY: clean fclean all re bonus