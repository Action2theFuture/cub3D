/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:09:24 by max               #+#    #+#             */
/*   Updated: 2024/10/30 20:37:48 by max              ###   ########.fr       */
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
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <math.h>
#include "X11/keysym.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/libft/includes/libft.h"
#include "../lib/libft/includes/get_next_line.h"
#include "prototype.h"


#endif