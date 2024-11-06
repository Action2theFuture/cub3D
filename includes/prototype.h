/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:53:01 by max               #+#    #+#             */
/*   Updated: 2024/11/06 17:37:07 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include "cube.h"

//---------print a delete----------------------------------
void print_map(t_description_file *desc_file);
void print_desc_file(t_description_file *desc_file);
//------------------------------------------------------------

//--------------------- parsing -------------------------------------------
bool parse(t_description_file *desc_file, char **argv);
bool store_elements(t_description_file *desc_file, char **elements);
bool parse_map(t_description_file *desc_file);
bool check_walls_surrounding_map(t_description_file *desc_file);
void flood_fill(t_description_file *desc_file, int y, int x, bool *is_map_not_enclosed);
bool check_map_name(char *argument);
bool check_elements(char **elements);
bool check_floor_and_ceiling_args(char *str);
bool format_elements(t_description_file *df);
//-------------------- parse utils ------------------------------------------
char *skype_space_ptr(char *str);
int skype_space(char *str);
int skype_digit(char *str);
int skype_digit_and_space(char *str);
int ft_atoi_cube(const char *str);
bool malloc_failed(t_description_file *desc_file);
bool validate_color_size(t_description_file *desc_file);
bool get_map(t_description_file *desc_file, char **argv);
int ft_strlen_map(char *str);
bool is_valid_player_char(char c);
//-------------------- init MLX/data ---------------------------------------
bool init_mlx_and_data(t_data *data, t_description_file *df);
void init_data(t_data *data);
double degrees_to_radians(double degrees);
//-------------------- raycasting --------------------------------------------
void raycast(t_data *data);
//---------------------- clean ------------------------------------------------
void clean_elements_array(char **elements);
void clean_partial_array(char **elements, int i);
void clean_elements(t_description_file *desc_file);
void clean_map(t_description_file *desc_file);
void clean_all(t_description_file *desc_file);
//-----------------------destroy -----------------------------------------------
void destroy_mlx_ptr(t_data *data);
void clean_and_destroy_all(t_data *data, t_description_file *df);

void raycast(t_data *data);

#endif