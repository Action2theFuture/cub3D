/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:09:24 by max               #+#    #+#             */
/*   Updated: 2024/11/04 14:05:30 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define NO 1
# define SO 2
# define WE 3
# define EA 4
# define F  5
# define C  6
# define OPEN_FAILED -1
# define M_PI 3.14159265358979323846

# define BASE_VIEW_ANGLE 0.0
# define FOV_DEGREE 66.0
# define FOV (FOV_DEGREE * M_PI / 180.0)
# define WALL_HEIGHT 1.0
# define PLAYER_VIEW_HEIGHT 0.5

# include "cube.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# ifdef __linux__
#  include "X11/keysym.h"
#  include "../lib/minilibx-linux/mlx.h"
# endif

# include "prototype.h"

#endif
