/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:09:24 by max               #+#    #+#             */
/*   Updated: 2024/10/30 20:06:13 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
#define CONFIG_H


#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define NO 1
#define SO 2
#define WE 3
#define EA 4
#define F  5
#define C  6
#define OPEN_FAILED -1

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "X11/keysym.h"
#include <fcntl.h>
#include "../lib/minilibx-linux/mlx.h"
#include <math.h>
#include "../lib/libft/includes/get_next_line.h"
#include "prototype.h"


#endif