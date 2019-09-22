# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brpinto <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 14:03:54 by brpinto           #+#    #+#              #
#    Updated: 2019/03/19 02:06:29 by brpinto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = clang
FLAGS = -Wall -Wextra -Werror

SRC_PATH = ./srcs/
OBJ_PATH = ./srcs/obj/
LIB_PATH = ./libft/
INC_PATH = ./includes/

MLX_HEADER = ./minilibx_macos/include
MLX_LIB = ./minilibx_macos/

SRC_FILES = main.c			\
			init_env.c 		\
			key_hook.c		\
			check_file.c	\
			init_map.c		\
			fdf.c			\
			create_img.c	\
			init_img.c		\
			projection.c	\
			select_point.c	\
			color.c			\
			close.c			\
			bresenham.c

LIB_FILES = libft.a
LIB = $(addprefix $(LIB_PATH), $(LIB_FILES))

OBJ_FILES = $(SRC_FILES:.c=.o)
	OBJ_EXEC = $(addprefix $(OBJ_PATH), $(OBJ_FILES))

all: $(NAME)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC_PATH) -I $(LIB_PATH)includes -I $(MLX_HEADER)
	@echo "\033[40mCompilation of \033[1m$(notdir $<)\033[0m \033[32mdone.\033[0m"

$(LIB):
	@make -C $(LIB_PATH)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJ_EXEC)
	@$(CC) $(FLAGS) $(OBJ_EXEC) $(LIB) -o $(NAME) -I $(INC_PATH)  -L $(MLX_LIB) -lmlx -framework OpenGL -framework AppKit

	@echo "\033[1;32m$(notdir $(NAME))\033[1;0m\033[32m created.\033[0m"

clean:
	@/bin/rm -rf $(OBJ_PATH)
	@make clean -C $(LIB_PATH)
	@echo "\033[31mObjects files of \033[1;31m$(notdir $(NAME))\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@make fclean -C $(LIB_PATH)
	@/bin/rm -rf $(NAME)
	@echo "\033[1;31m$(notdir $(NAME))\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
