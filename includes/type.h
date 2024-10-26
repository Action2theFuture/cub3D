/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:07:59 by max               #+#    #+#             */
/*   Updated: 2024/10/26 02:25:24 by max              ###   ########.fr       */
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

#endif