/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:53:01 by max               #+#    #+#             */
/*   Updated: 2024/11/07 05:46:33 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

# include "type.h"
# include "config.h"

//---------print a delete--------------------------------------------------
void	debug_map_and_df(t_description_file *df);

//--------------------- utils-- -------------------------------------------
double	degrees_to_radians(double degrees);

//-------------------- init MLX/data ---------------------------------------
void	init_data(t_game *game);
bool	init_game(t_game *game, t_description_file *df);

//--------------------- parsing -------------------------------------------
bool	parse(t_description_file *desc_file, char **argv);
bool	store_elements(t_description_file *desc_file, char **elements);
bool	parse_map(t_description_file *desc_file);
bool	check_walls_surrounding_map(t_description_file *desc_file);
bool	check_map_name(char *argument);
bool	check_elements(char **elements);
bool	check_floor_and_ceiling_args(char *str);
bool	format_elements(t_description_file *df);
void	flood_fill(t_description_file *desc_file, \
		int y, int x, bool *is_map_not_enclosed);

//-------------------- parse utils ----------------------------------------
int		skype_space(char *str);
int		skype_digit(char *str);
int		skype_digit_and_space(char *str);
int		ft_atoi_cube(const char *str);
int		ft_strlen_map(char *str);
char	*skype_space_ptr(char *str);
bool	malloc_failed(t_description_file *desc_file);
bool	validate_color_size(t_description_file *desc_file);
bool	get_map(t_description_file *desc_file, char **argv);
bool	is_valid_player_char(char c);

//------------------------ input -------------------------------------------
int		key_press(int keycode, t_game *game);

//------------------------ move --------------------------------------------
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

//----------------------- rotate -------------------------------------------
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);

//-------------------- raycasting ------------------------------------------
void	perform_raycasting(t_game *game);

//-------------------- rendering -------------------------------------------
void	put_pixel(t_game *game, int x, int y, int color);
void	render_frame(t_game *game);

//------------------------ clean -------------------------------------------
void	clean_elements_array(char **elements);
void	clean_partial_array(char **elements, int i);
void	clean_elements(t_description_file *desc_file);
void	clean_map(t_description_file *desc_file);
void	clean_all(t_description_file *desc_file);
void	reach_end_of_file (t_description_file *desc_file, char ** elements);

//-----------------------destroy --------------------------------------------
void	destroy_mlx_specific(t_game *game);
void	clean_and_destroy_all(t_game *game, t_description_file *df);

#endif
