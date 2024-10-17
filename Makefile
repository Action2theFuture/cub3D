# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junsan <junsan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 09:12:59 by junsan            #+#    #+#              #
#    Updated: 2024/10/17 21:48:31 by junsan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= cub3D
OS		= $(shell uname)

BREW_PREFIX = $(shell brew --prefix)

OBJ_DIR		= ./obj/
LIB_DIR		= ./lib
LIBFT_DIR 	= $(LIB_DIR)/libft/
MLX_DIR		= $(LIB_DIR)/MLX42
MLX_BUILD_DIR = $(MLX_DIR)/build/

LIBFT   = $(addprefix $(LIBFT_DIR), libft.a)
MLX		= $(addprefix $(MLX_BUILD_DIR), libmlx42.a)

CFLAGS 	= -Wall -Wextra -Werror -g3
IFLAGS	= -I ./includes/ -I $(LIBFT_DIR) -I $(MLX_DIR)

GLFW_LIB = -lglfw

SRC		= main.c

SRC_DIR		= ./src/

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

ifeq ($(OS), Linux)
	MLX_LNK	= -L$(MLX_DIR) -lmlx  -lXext -lX11 -lm -lz
	LINK_FLAG = -ldl $(GLFW_LIB) -pthread -lm
else ifeq ($(OS), Darwin)
	MLX_LNK	= -framework Cocoa -framework OpenGL -framework IOKit
	LINK_FLAG = $(GLFW_LIB)
endif

vpath %.c ./src/

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	cc $(CFLAGS) $(MLX_LNK) $(MLX) -o $@ $(OBJS) $(LIBFT) $(LINK_FLAG)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	cc $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT): 
	@make -C $(LIBFT_DIR)

$(MLX):
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4 \
		--no-print-directory


$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

all : $(NAME)

clean :
	@make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)
	@rm -rf $(MLX_BUILD_DIR)

fclean : clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
