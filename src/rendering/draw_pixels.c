/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:39:03 by junsan            #+#    #+#             */
/*   Updated: 2024/11/11 20:56:56 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static t_door	*find_door_at_ray_position(t_game *game)
{
	int (i) = -1;
	while (++i < game->door_cnt)
	{
		if (game->doors[i].x == game->ray.map_x && \
			game->doors[i].y == game->ray.map_y)
			return (&game->doors[i]);
	}
	return (NULL);
}

static int	get_wall_color(t_game *game, int tex_x, int tex_y)
{
	if (game->ray.side == NORTH)
		return (get_pixel_color(game->mlx.north_texture, tex_x, tex_y));
	else if (game->ray.side == SOUTH)
		return (get_pixel_color(game->mlx.south_texture, tex_x, tex_y));
	else if (game->ray.side == EAST)
		return (get_pixel_color(game->mlx.east_texture, tex_x, tex_y));
	else
		return (get_pixel_color(game->mlx.west_texture, tex_x, tex_y));
}

static bool	use_door_texture(t_door *cur_door, double progress, \
							int y, int total_height)
{
	int (skip_pixels) = (int)(total_height * (1.0 - progress));
	if (cur_door->state == DOOR_OPENING)
		return (y >= (total_height - skip_pixels));
	else if (cur_door->state == DOOR_CLOSING || cur_door->state == DOOR_OPEN)
		return (y < (total_height - skip_pixels));
	else if (cur_door->state == DOOR_CLOSED)
		return (true);
	return (false);
}

static double	calculate_progress(t_door *cur_door)
{
	double	progress;

	progress = cur_door->animation_timer / ANIMATION_DURATION;
	if (progress > 1.0)
		progress = 1.0;
	return (progress);
}

void	draw_pixels(t_game *game, int x, int draw_pos[2], int tex_x)
{
	int		tex_y;
	int		color;

	t_door (*cur_door) = find_door_at_ray_position(game);
	double (progress) = 0.0;
	int (y) = draw_pos[0];
	if (cur_door && BONUS)
		progress = calculate_progress(cur_door);
	while (y < draw_pos[1])
	{
		if (game->ray.side == NORTH || game->ray.side == SOUTH)
			tex_y = (int)game->ray.tex_pos % game->mlx.north_texture.height;
		else
			tex_y = (int)game->ray.tex_pos % game->mlx.east_texture.height;
		game->ray.tex_pos += game->ray.step;
		color = get_wall_color(game, tex_x, tex_y);
		if (cur_door && BONUS)
		{
			if (use_door_texture(\
					cur_door, progress, y, draw_pos[1] - draw_pos[0]))
				color = get_pixel_color(game->mlx.door_texture, tex_x, tex_y);
		}
		put_pixel(game, x, y, color);
		y++;
	}
}
