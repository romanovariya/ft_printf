# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbabette <mbabette@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/26 17:28:57 by mbabette          #+#    #+#              #
#    Updated: 2020/07/26 18:24:42 by mbabette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
MAKE = make
CC = gcc
GFLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h
OBJ = $(SRC:%.c=%.o)
SRC = ./ft_printf.c

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft && $(MAKE) bonus
	@cp libft/libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJ)
	@echo libftprintf compiled
	
%.o: %.c $(HEADER)
	@$(CC) $(GFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C ./libft clean

fclean: clean
	
	

