# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkergast <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 16:06:19 by rkergast          #+#    #+#              #
#    Updated: 2020/01/30 14:39:42 by rkergast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define SRC_NAME
main.c\
get_next_line.c\
ft_get_next_line.c\
ft_settab.c\
ft_initmlx.c\
ft_getkey.c\
ft_setkey.c\
ft_error.c\
ft_drawimg.c\
ft_player.c
endef

CC = gcc
FLAGS = -Wall -Wextra -Werror
OBJ_NAME = $(SRC:.c=.o)
SRC = $(SRC_NAME)
OBJ = $(OBJ_NAME)
MLXPATH = miniLibX
LIBFTPATH = libft
MLX = $(MLXPATH)/libmlx.a -framework OPENGL -framework AppKit
NAME = wolf3d
LIB = wolf3d.a
LIBFTLIB = libft/libft.a
.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFTPATH)
	make -C $(MLXPATH)
	ar rc $(LIB) $(OBJ)
	ranlib $(LIB)
	$(CC) $(FLAGS) $(SRC) $(LIBFTLIB) -o $(NAME) $(MLX)

%.o: %.c
	$(CC) -c $(FLAGS) -o $@ $<

clean :
	rm -f $(OBJ)
	make clean -C $(LIBFTPATH)
	make clean -C $(MLXPATH)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)
	make fclean -C $(LIBFTPATH)

re: fclean all
