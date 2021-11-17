# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scuter <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 09:54:43 by scuter            #+#    #+#              #
#    Updated: 2021/11/17 18:32:51 by scuter           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 				fractol

CC = 				gcc

CFLAGS = 			-Wall -Wextra -Werror
GFLAGS =			-lmlx -framework OpenGL -framework AppKit
# GFLAGS =			 -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11
# GFLAGS = 			-I libft -L libft \
# 					-I /usr/local/include -L /usr/local/lib \
# 					-l mlx -framework OpenGL -framework Appkit

HEA_PATH = 			./src
HEA_NAME = 			fractol.h
HEA = 				$(addprefix $(HEA_PATH)/,$(HEA_NAME))

SRC_PATH = 			./src
SRC_NAME = 			main.c mandelbrot.c events.c julia.c burningship.c
SRC = 				$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = 			./src
OBJ_NAME = 			$(SRC_NAME:.c=.o)
OBJ = 				$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))


all: $(NAME)

$(NAME): 			$(OBJ) $(HEA)
					make -C libft/
					$(CC) $(CFLAGS) $(OBJ) $(GFLAGS) libft/libft.a -o $(NAME)

%.o: 				%.c $(HEA)
					$(CC) $(CFLAGS) -c $< -o $@

clean:
					rm -rf $(OBJ)
					make -C libft clean

fclean: 			clean
					make -C libft fclean
					rm -rf $(NAME)

re: 				fclean all

.PHONY: 			all clean fclean re
