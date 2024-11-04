# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: max <max@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 09:12:59 by junsan            #+#    #+#              #
#    Updated: 2024/11/04 19:40:44 by junsan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= cub3D
OS		= $(shell uname)

LIB_DIR		= ./lib
LIBFT_DIR 	= $(LIB_DIR)/libft/

LIBFT   = $(addprefix $(LIBFT_DIR), libft.a)

CFLAGS = -Wall -Wextra -Werror -g3
IFLAGS = -I ./includes/ -I $(LIBFT_DIR)includes/ -I $(MLX_DIR)

SRC_DIR		= src
OBJ_DIR		= obj
INIT_DIR 	= $(SRC_DIR)/init
PARSING_DIR = $(SRC_DIR)/parsing
CLEANING_DIR = $(SRC_DIR)/clean-destroy

SRC		 = main.c
PARSING  = check_walls.c parse_map.c parse_utils.c parse_utils2.c parse.c \
		get_map.c \
		print_test.c \
		store_elements.c \
		check_elements_and_map_name.c \
		format_elements.c
		   
INIT     = init_mlx.c init_data.c init_utils.c
CLEANING = clean.c destroy.c


SRCS := $(addprefix $(SRC_DIR)/, $(SRC))
SRCS += $(addprefix $(INIT_DIR)/, $(INIT))
SRCS += $(addprefix $(PARSING_DIR)/, $(PARSING))
SRCS += $(addprefix $(CLEANING_DIR)/, $(CLEANING))

OBJS := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

vpath %.c ./src/

ifeq ($(OS), Linux)
	SRCS += $(addprefix $(CLEANING_DIR)/, destroy_linux.c)
	LIB_MLX = libmlx.a
	MLX_DIR = $(LIB_DIR)/mlx_linux/
	MLX = $(addprefix $(MLX_DIR), $(LIB_MLX))
	MLX_LNK	= -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz
else ifeq ($(OS), Darwin)
	SRCS += $(addprefix $(CLEANING_DIR)/, destroy_mac.c)
	LIB_MLX = libmlx.dylib
	MLX_DIR = $(LIB_DIR)/mlx/
	MLX = $(addprefix $(MLX_DIR), $(LIB_MLX))
	MLX_LNK	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

OBJS := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

vpath %.c ./src/

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	cc $(CFLAGS) -o $@ $(OBJS) $(LIBFT) $(MLX_LNK)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	cc $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT): 
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)
	@if [ "$(OS)" = "Darwin" ]; then \
		install_name_tool -id @executable_path/lib/mlx/$(LIB_MLX) $(MLX_DIR)$(LIB_MLX); \
	fi


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
