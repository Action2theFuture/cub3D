# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junsan <junsan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 09:12:59 by junsan            #+#    #+#              #
#    Updated: 2024/11/04 12:42:39 by junsan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= cub3D
OS		= $(shell uname)

OBJ_DIR		= ./obj/
LIB_DIR		= ./lib
LIBFT_DIR 	= $(LIB_DIR)/libft/
MLX_DIR		=

LIBFT   = $(addprefix $(LIBFT_DIR), libft.a)

CFLAGS 	= -Wall -Wextra -Werror -g3
IFLAGS	= -I ./includes/ -I $(LIBFT_DIR) -I $(MLX_DIR)

LINK_FLAG = 

SRC		= main.c

SRC_DIR		= ./src/

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

ifeq ($(OS), Linux)
	LIB_MLX = libmlx.a
	MLX_DIR = $(LIB_DIR)/mlx_linux/
	MLX = $(addprefix $(MLX_DIR), $(LIB_MLX))
	MLX_LNK	= -L$(MLX_DIR) -lmlx  -lXext -lX11 -lm -lz
else ifeq ($(OS), Darwin)
	LIB_MLX = libmlx.dylib
	MLX_DIR = $(LIB_DIR)/mlx/
	MLX = $(addprefix $(MLX_DIR), $(LIB_MLX))
	install_name_tool -id @executable_path/lib/mlx/$(LIB_MLX) $(MLX_DIR)$(LIB_MLX); \
	MLX_LNK	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

vpath %.c ./src/

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	cc $(CFLAGS) $(MLX_LNK) -o $@ $(OBJS) $(LIBFT)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	cc $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT): 
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

all : $(NAME)

clean :
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean : clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
