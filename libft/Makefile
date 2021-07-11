# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iulia <iulia@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/12 15:33:01 by iulias            #+#    #+#              #
#    Updated: 2020/07/14 21:40:38 by iulia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SRCS = ft_isascii.c ft_memchr.c ft_putendl_fd.c ft_strlen.c ft_atoi.c \
ft_isdigit.c ft_memcmp.c ft_putnbr_fd.c ft_strdup.c ft_strmapi.c ft_substr.c \
ft_bzero.c ft_isprint.c ft_memcpy.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c \
ft_tolower.c ft_calloc.c ft_itoa.c ft_memmove.c ft_split.c ft_strnstr.c \
ft_toupper.c ft_isalnum.c ft_memset.c ft_strlcat.c ft_strrchr.c \
ft_isalpha.c ft_memccpy.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c \
ft_strtrim.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_putnbr_sign.c \
ft_itoa_base.c ft_itoa_unsigned.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RANLIB = ranlib

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstdelone.c ft_lstadd_back.c ft_lstclear.c ft_lstiter.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@$(AR) $(NAME) $(OBJS)
	@$(RANLIB) $(NAME)

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

bonus: $(BONUS_OBJS)
	@$(AR) $(NAME) $(BONUS_OBJS)
	@$(RANLIB) $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
