/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:07:59 by max               #+#    #+#             */
/*   Updated: 2024/10/31 01:50:46 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
#define TYPE_H

typedef struct s_colors
{
    int red;
    int green;
    int blue;

} t_colors;

typedef struct s_elements
{
    char *north_path;
    char *south_path;
    char *east_path;
    char *west_path;
    t_colors floor;
    t_colors ceiling;

} t_elements;

typedef struct s_description_file
{
    int fd;
    int elements_lines;
    int map_width;
    int map_height;
    t_elements elements;
    char **map;

} t_description_file;

typedef struct s_mlx
{
    void *ptr;
    void *windows;
    void *north_texture;
    void *south_texture;
    void *east_texture;
    void *west_texture;

} t_mlx;

// typedef struct s_player
// {

// } t_player;

typedef struct s_data
{
    t_description_file *df;
    t_mlx mlx;
    int screen_size_x;
    int screen_size_y;
    // int initial_view_direction;
} t_data;

#endif