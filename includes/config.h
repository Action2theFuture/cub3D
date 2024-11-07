/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:09:24 by max               #+#    #+#             */
/*   Updated: 2024/11/07 04:07:53 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define CUB3D "Cub3D"

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
# define OPEN_FAILED -1

# define WALL '1'
# define ROAD '0'

# define BASE_VIEW_ANGLE 0.0
# define FOV_DEGREE 66.0
# define WALL_HEIGHT 1.0
# define PLAYER_VIEW_HEIGHT 0.5

# define MOVE_SPEED 0.05
# define ROT_SPEED 0.03

# ifdef __APPLE__
#  define KEY_W     13
#  define KEY_A     0
#  define KEY_S     1
#  define KEY_D     2
#  define KEY_LEFT  123
#  define KEY_RIGHT 124
#  define KEY_ESC   53
# elif defined(__linux__)
#  define KEY_W     122
#  define KEY_A     113
#  define KEY_S     115
#  define KEY_D     100
#  define KEY_LEFT  65361
#  define KEY_RIGHT 65363
#  define KEY_ESC   65307
# else
#  error "Unsupported platform. Please define key codes for your platform."
# endif
#endif
// #  define KEY_W     119
// #  define KEY_A     97
// #  define KEY_S     115
// #  define KEY_D     100
// #  define KEY_LEFT  65361
// #  define KEY_RIGHT 65363
// #  define KEY_ESC   65307