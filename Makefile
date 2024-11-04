# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: max <max@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 09:12:59 by junsan            #+#    #+#              #
#    Updated: 2024/11/04 15:10:19 by junsan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= cub3D
OS		= $(shell uname)

OBJ_DIR		= ./obj/
LIB_DIR		= ./lib
LIBFT_DIR 	= $(LIB_DIR)/libft/

LIBFT   = $(addprefix $(LIBFT_DIR), libft.a)

CFLAGS = -Wall -Wextra -Werror -g3
IFLAGS = -I ./includes/ -I $(LIBFT_DIR)includes/ -I $(MLX_DIR)

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

ifeq ($(OS), Linux)
	LIB_MLX = libmlx.a
	MLX_DIR = $(LIB_DIR)/mlx_linux/
	MLX = $(addprefix $(MLX_DIR), $(LIB_MLX))
	MLX_LNK	= -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz
else ifeq ($(OS), Darwin)
	LIB_MLX = libmlx.dylib
	MLX_DIR = $(LIB_DIR)/mlx/
	MLX = $(addprefix $(MLX_DIR), $(LIB_MLX))
	install_name_tool -id @executable_path/lib/mlx/$(LIB_MLX) $(MLX_DIR)$(LIB_MLX); \
	MLX_LNK	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

vpath %.c ./src/

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	cc $(CFLAGS) -o $@ $(OBJS) $(LIBFT) $(MLX_LNK)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
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
