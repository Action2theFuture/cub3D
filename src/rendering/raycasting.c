/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 04:18:51 by max               #+#    #+#             */
/*   Updated: 2024/11/11 19:40:51 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	clamp_and_flip_tex_x(int tex_x, t_game *game)
{
	int	tex_width;

	if (game->ray.side == NORTH)
		tex_width = game->mlx.north_texture.width;
	else if (game->ray.side == SOUTH)
		tex_width = game->mlx.south_texture.width;
	else if (game->ray.side == EAST)
		tex_width = game->mlx.east_texture.width;
	else
		tex_width = game->mlx.west_texture.width;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex_width)
		tex_x = tex_width - 1;
	if (game->ray.side == EAST || game->ray.side == SOUTH)
		tex_x = tex_width - tex_x - 1;
	return (tex_x);
}

static void	draw_wall_column(\
			t_game *game, int x, int draw_pos[2], double perp_wall_dist)
{
	double	wall_x;
	int		line_height;
	int		tex_x;

	line_height = (int)(game->screen_size_y / perp_wall_dist);
	calculate_draw_pos(line_height, game->screen_size_y, draw_pos);
	if (game->ray.side == NORTH || game->ray.side == SOUTH)
		game->ray.step = 1.0 * game->mlx.north_texture.height / line_height;
	else
		game->ray.step = 1.0 * game->mlx.east_texture.height / line_height;
	game->ray.tex_pos = (draw_pos[0] - game->screen_size_y / 2 + \
		line_height / 2) * game->ray.step;
	calculate_wall_and_tex_x(game, perp_wall_dist, &wall_x, &tex_x);
	tex_x = clamp_and_flip_tex_x(tex_x, game);
	draw_pixels(game, x, draw_pos, tex_x);
}

static void	process_single_ray(t_game *game, int x)
{
	double	ray_dir[2];
	double	perp_wall_dist;
	int		draw_pos[2];

	calculate_ray_direction(game, x, &ray_dir[0], &ray_dir[1]);
	game->ray.ray_dir_x = ray_dir[0];
	game->ray.ray_dir_y = ray_dir[1];
	init_dda(game, ray_dir[0], ray_dir[1], &game->ray);
	perform_dda(game, &game->ray);
	if (game->ray.hit)
	{
		perp_wall_dist = calculate_perp_wall_dist(game, &game->ray);
		calculate_wall_dimensions(\
			game, perp_wall_dist, &draw_pos[0], &draw_pos[1]);
		draw_wall_column(game, x, draw_pos, perp_wall_dist);
	}
}

void	perform_raycasting(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->screen_size_x)
	{
		process_single_ray(game, x);
		x++;
	}
	draw_minimap(game);
	mlx_put_image_to_window(\
		game->mlx.ptr, game->mlx.windows, game->img.img, 0, 0);
}
