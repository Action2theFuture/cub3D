/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:53:01 by max               #+#    #+#             */
/*   Updated: 2024/11/09 14:25:46 by junsan           ###   ########.fr       */
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
void	init_player(t_game *game);
void	set_direction_north(t_game *game, double plane_len);
void	set_direction_south(t_game *game, double plane_len);
void	set_direction_east(t_game *game, double plane_len);
void	set_direction_west(t_game *game, double plane_len);
void	init_minimap(t_game *game);
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

//------------------------ move --------------------------------------------
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

//----------------------- rotate -------------------------------------------
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);

//------------------------ input -------------------------------------------
int		mouse_move(int x, int y, t_game *game);
int		key_press(int keycode, t_game *game);
void	event_listener(t_game *game);

//-------------------------- dda -------------------------------------------
void	init_dda(t_game *game, \
					double ray_dir_x, double ray_dir_y, t_ray *ray);
void	perform_dda(t_game *game, t_ray *ray);

//-------------------- calculate -------------------------------------------
double	calculate_perp_wall_dist(t_game *game, t_ray *ray);
void	calculate_ray_direction(t_game *game, \
						int x, double *ray_dir_x, double *ray_dir_y);
void	calculate_draw_pos(\
				int line_height, int screen_size_y, int draw_pos[2]);
void	calculate_wall_and_tex_x(\
	t_game *game, double perp_wall_dist, double *wall_x, int *tex_x);
int		calculate_wall_dimensions(t_game *game, \
						double perp_wall_dist, int *draw_start, int *draw_end);

//----------------------- map ----------------------------------------------
double	calculate_distance_to_wall(t_game *game);
bool	is_wall(t_game *game, int x, int y);
void	init_line(int player_pos[2], int line_pos[2], int params[4], int *err);
void	draw_minimap(t_game *game);

//-------------------- raycasting ------------------------------------------
void	draw_wall_column(\
		t_game *game, int x, int draw_pos[2], double perp_wall_dist);
void	put_pixel(t_game *game, int x, int y, int color);
void	perform_raycasting(t_game *game);

//-------------------- rendering -------------------------------------------
void	put_pixel(t_game *game, int x, int y, int color);
int		get_pixel_color(t_texture texture, int x, int y);
void	render_frame(t_game *game);

//------------------------ clean -------------------------------------------
void	clean_elements_array(char **elements);
void	clean_partial_array(char **elements, int i);
void	clean_elements(t_description_file *desc_file);
void	clean_map(t_description_file *desc_file);
void	clean_all(t_description_file *desc_file);
void	reach_end_of_file(t_description_file *desc_file, char **elements);

//-----------------------destroy --------------------------------------------
void	destroy_mlx_specific(t_game *game);
void	clean_and_destroy_all(t_game *game, t_description_file *df);

#endif
