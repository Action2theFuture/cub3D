# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junsan <junsan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 09:12:59 by junsan            #+#    #+#              #
#    Updated: 2024/11/09 12:31:42 by junsan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOR_RESET = \033[0m
COLOR_RED = \033[1;31m
COLOR_GREEN = \033[1;32m
COLOR_YELLOW = \033[1;33m
COLOR_BLUE = \033[1;34m
COLOR_CYAN = \033[1;36m

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
RENDERING_DIR = $(SRC_DIR)/rendering
INPUT_DIR = $(SRC_DIR)/input
DEBUG_DIR   = $(SRC_DIR)/debug

SRC		 = main.c utils.c
PARSING  = check_walls.c parse_map.c parse_utils.c parse_utils2.c parse.c \
		get_map.c store_elements.c check_elements_and_map_name.c \
		format_elements.c 
INIT     = init_game.c init_player.c init_minimap.c direction_setup.c
CLEANING = clean.c destroy.c clean_utils.c
RENDERING = raycasting.c rendering.c calculate.c dda.c minimap.c minimap_draw_utils.c
INPUT = input.c move.c rotate.c
DEBUG    = debug.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRC))
SRCS += $(addprefix $(INIT_DIR)/, $(INIT))
SRCS += $(addprefix $(PARSING_DIR)/, $(PARSING))
SRCS += $(addprefix $(CLEANING_DIR)/, $(CLEANING))
SRCS += $(addprefix $(RENDERING_DIR)/, $(RENDERING))
SRCS += $(addprefix $(INPUT_DIR)/, $(INPUT))
SRCS += $(addprefix $(DEBUG_DIR)/, $(DEBUG))

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
	@cc $(CFLAGS) -o $@ $(OBJS) $(LIBFT) $(MLX_LNK) > /dev/null 2>&1
	@echo "$(COLOR_GREEN)Program Name : $(NAME)$(COLOR_RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@cc $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT): 
	@make -sC $(LIBFT_DIR)
	@echo "$(COLOR_BLUE)Compliling Obj files...$(COLOR_RESET)"

$(MLX):
	@make -sC $(MLX_DIR)
	@if [ "$(OS)" = "Darwin" ]; then \
		install_name_tool -id @executable_path/lib/mlx/$(LIB_MLX) $(MLX_DIR)$(LIB_MLX); \
	fi


$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

all : $(NAME)

debug: CFLAGS += -g3 -fsanitize=address -DDEBUG=1
debug: fclean $(NAME)


clean :
	@make -sC $(LIBFT_DIR) clean
	@make -sC $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(COLOR_RED)Cleaning completed successfully 🧹$(COLOR_RESET)"

fclean : clean
	@make -sC $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "$(COLOR_RED)Full Cleaning completed successfully 🧹$(COLOR_RESET)"

re : fclean all

.PHONY : all clean fclean debug re
