# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junsan <junsan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 09:12:59 by junsan            #+#    #+#              #
#    Updated: 2024/06/24 10:36:11 by junsan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= cub3D
OS		= $(shell uname)

LIBFT   = $(addprefix $(LIBFT_DIR), libft.a)
MLX		= $(addprefix $(MX_DIR), mlx.a)

CFLAGS 	= -Wall -Wextra -Werror -g3
IFLAGS	= -I ./includes/ -I $(LIBFT_DIR) -I $(MLX_DIR)

SRC		= \

SRC_DIR		= ./mandatory/
OBJ_DIR		= ./obj/
LIBFT_DIR 	= ./libft/

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

ifeq ($(OS), Linux)
	MLX_DIR	= ./mlx_linux/
	MLX_LIB = $(addprefix $(MLX_DIR), libmlx.a)
	MLX_LNK	= -L$(MLX_DIR) -lmlx  -lXext -lX11 -lm -lz
else ifeq ($(OS), Darwin)
	MLX_DIR := ./mlx/
	MLX_LIB = $(addprefix $(MLX_DIR), libmlx.dylib)
	MLX_LNK	= -Lmlx -lmlx -framework OpenGL -framework AppKit
endif

vpath %.c ./mandatory/
vpath %.c ./bonus/

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	cc $(CFLAGS) $(MLX_LNK) -o $@ $(OBJS) $(LIBFT) $(MLX_LIB)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
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
	rm -rf $(OBJ_DIR)
	rm -rf $(B_OBJ_DIR)

fclean : clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
