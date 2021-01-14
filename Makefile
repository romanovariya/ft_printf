# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 00:44:40 by mbabette          #+#    #+#              #
#    Updated: 2020/08/04 11:23:16 by mbabette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
INCLUDE = -I ./
SRC = ft_checkers.c ft_print_ptr.c ft_printchar.c ft_printf.c ft_printhex.c \
		ft_printnum.c ft_printpercent.c ft_printstr.c ft_printunsigned.c \
		libsfunc.c libsfuncs.c utils.c ft_print_upx.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re