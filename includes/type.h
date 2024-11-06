/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:07:59 by max               #+#    #+#             */
/*   Updated: 2024/11/06 17:17:37 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

typedef struct s_colors
{
	int	red;
	int	green;
	int	blue;
}	t_colors;

typedef struct s_elements
{
	char		*north_path;
	char		*south_path;
	char		*east_path;
	char		*west_path;
	t_colors	floor;
	t_colors	ceiling;
}	t_elements;

typedef struct s_description_file
{
	int			fd;
	int			elements_lines;
	int			map_width;
	int			map_height;
	char		**map;
	t_elements	elements;

}	t_description_file;

typedef struct s_mlx
{
	void	*ptr;
	void	*windows;
	void	*north_texture;
	void	*south_texture;
	void	*east_texture;
	void	*west_texture;
}	t_mlx;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	view_angle;
	double	view_distance;
	double	dir_x;
	double	dir_y;
	double	cam_vector_x;
	double	cam_vector_y;
}	t_player;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;	
}	t_image;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	bool	hit;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
}	t_ray;

typedef struct s_game
{
	t_description_file	*df;
	t_mlx				mlx;
	t_player			player;
	t_image				img;
	t_ray				ray;
	int					screen_size_x;
	int					screen_size_y;
}	t_game;
#endif
