# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iserzhan <iserzhan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/12 15:33:01 by iulias            #+#    #+#              #
#    Updated: 2020/07/25 16:15:31 by iserzhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

SRCS = ft_printf.c init_format.c parse_types.c print_all.c convert_pointer.c \
size.c
CC = clang
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RANLIB = ranlib

OBJS = $(SRCS:.c=.o)


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./libft
	@$(AR) $(NAME) $(OBJS) libft/*.o
	@$(RANLIB) $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	/bin/rm -f *.o
	make clean -C ./libft

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C ./libft
re: fclean all
