# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: max <max@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 09:12:59 by junsan            #+#    #+#              #
#    Updated: 2024/11/01 04:12:25 by max              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= cub3D

OBJ_DIR		= ./obj/
LIB_DIR		= ./lib
LIBFT_DIR 	= $(LIB_DIR)/libft/
MLX_DIR		= $(LIB_DIR)/minilibx-linux/


LIBFT  = $(addprefix $(LIBFT_DIR), libft.a)
MLX	   = $(addprefix $(MLX_DIR), libmlx.a)

CFLAGS = -Wall -Wextra -Werror -g3
IFLAGS = -I ./includes/ -I $(LIBFT_DIR) -I $(MLX_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC		 = main.c 	\

PARSING  = parsing/check_walls.c parsing/parse_map.c parsing/parse_utils.c parsing/parse_utils2.c parsing/parse.c \
		   parsing/get_map.c \
		   parsing/print_test.c \
		   parsing/store_elements.c \
		   parsing/check_elements_and_map_name.c \
		   parsing/format_elements.c
		   
INIT     = init/init_mlx.c \
		   init/init_data.c \
		   init/init_utils.c
		   
CLEANING = clean-destroy/clean.c \
		   clean-destroy/destroy.c

SRC_DIR		= ./src/

SRCS := $(addprefix $(SRC_DIR), $(SRC))
SRCS += $(addprefix $(SRC_DIR), $(PARSING))
SRCS += $(addprefix $(SRC_DIR), $(CLEANING))
SRCS += $(addprefix $(SRC_DIR), $(INIT))
OBJS := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

vpath %.c ./src/

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	cc $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) $(MLX_FLAGS) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	cc $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT): 
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR) 
		--no-print-directory

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

all : $(NAME)

clean :
	@make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean : clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
