/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:09:24 by max               #+#    #+#             */
/*   Updated: 2024/11/11 23:00:35 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define CUB3D "Cub3D"
# define CONTROLOR_PATH "./assets/controlor"

# define RESET	"\e[0m"
# define PRINT_BLACK	"\e[30m"
# define PRINT_RED	"\e[31m"
# define PRINT_GREEN	"\e[32m"
# define PRINT_YELLOW	"\e[33m"
# define PRINT_BLUE	"\e[34m"
# define PRINT_PURPLE	"\e[35m"
# define PRINT_CYAN	"\e[36m"
# define PRINT_WHITE	"\e[37m"

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

# define NO 1
# define SO 2
# define WE 3
# define EA 4
# define F  5
# define C  6
# define D  7
# define OPEN_FAILED -1

// CLOSED_DOOR, OPENED_DOOR are charactor in map
// DOOR_CLOSED, DOOR_OPENING, DOOR_OPEN for animation
# define WALL '1'
# define ROAD '0'
# define CLOSED_DOOR 'P'
# define OPENED_DOOR 'p'
# define MAX_DOOR 100

# define DOOR_CLOSED 0
# define DOOR_CLOSING 1
# define DOOR_OPEN 2
# define DOOR_OPENING 3

# define NORTH 0
# define SOUTH 1
# define EAST  2
# define WEST  3

# define BASE_VIEW_ANGLE 0.0
# define FOV_DEGREE 66.0
# define WALL_HEIGHT 1.0
# define PLAYER_VIEW_HEIGHT 0.5

# define MOVE_SPEED 0.1
# define ROT_SPEED 0.08
# define ROT_SPEED_CONTROL 0.01

# define MINIMAP_SCALE 10
# define ANIMATION_DURATION 0.5
# define DOOR_PATH "./textures/wolfenstein/eagle.xpm"

# define ERR_MAXIMUM_DOOR "Maximum number of doors reached"
# define INVALID_ELE "Invalid ID elements or invalid numbers of \
elements"
# define MALLOC_FAIL "Malloc failled"
# define INVALID_COLOR_SIZE "Invalid color size"
# define INVALID_CHARCTOR "Invalid character in the map"
# define TOO_MANY_PLAYER "The map have more than 1 player"
# define INVALID_MAP_NAME "Invalid map name"
# define NO_PLAYER "No player in the map"
# define INVALID_FILE_FORMAT "Invalid description file format"
# define FILE_OPEN_FAIL "Open file failed"
# define INVALID_INPUT_FLOOR "Invaild floor input"
# define INVALID_INPUT_CEILING "Invaild ceiling input"
# define NEW_LINE "New line in map"
# define NO_MAP "No map in the file"
# define NOT_ENCLOSED "The map is not enclosed by walls"
# define INVALID_PLAYER_LOC "Player is outside or on the edge"
# define INVALID_INPUT_CEILING_FLOOR "Invalid ceiling/floor input"
# define MLX_INIT_FAIL "MLX init failed"
# define MLX_INIT_WINDOW_FAIL "MLX init windows failed"
# define MLX_INIT_IMAGE_FAIL "MLX init image failed"
# define ERR_TEXTURE_SIZE "Texture size mismatch"
# define ERR_LOAD_TEXTURE "Failed to load texture"
# define INVALID_PLAYER_DIR "Invalid player direction"
# define INVALID_DOOR_LOC "The wall is not enclose with wall"

# ifdef __APPLE__
#  define KEY_W     13
#  define KEY_A     0
#  define KEY_S     1
#  define KEY_D     2
#  define KEY_R     15
#  define KEY_LEFT  123
#  define KEY_RIGHT 124
#  define KEY_ESC   53
# elif defined(__linux__)
#  define KEY_W     119
#  define KEY_A     97
#  define KEY_S     115
#  define KEY_D     100
#  define KEY_R     114
#  define KEY_LEFT  65361
#  define KEY_RIGHT 65363
#  define KEY_ESC   65307
# else
#  error "Unsupported platform. Please define key codes for your platform."
# endif
#endif