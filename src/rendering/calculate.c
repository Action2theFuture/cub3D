/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:39:00 by junsan            #+#    #+#             */
/*   Updated: 2024/11/08 16:41:01 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*printf("Ray %d: camera_x=%.2f, ray_dir_x=%.2f, \
ray_dir_y=%.2f\n", x, camera_x, *ray_dir_x, *ray_dir_y);
*/
void	calculate_ray_direction(t_game *game, \
						int x, double *ray_dir_x, double *ray_dir_y)
{
	double	camera_x;

	camera_x = 2.0 * x / (double)game->screen_size_x - 1.0;
	*ray_dir_x = game->player.dir_x + game->player.cam_vector_x * camera_x;
	*ray_dir_y = game->player.dir_y + game->player.cam_vector_y * camera_x;
}

double	calculate_perp_wall_dist(t_game *game, t_ray *ray)
{
	if (ray->side == NORTH || ray->side == SOUTH)
		return ((ray->map_y - game->player.pos_y + \
		(1 - ray->step_y) / 2) / ray->ray_dir_y);
	else
		return ((ray->map_x - game->player.pos_x + \
		(1 - ray->step_x) / 2) / ray->ray_dir_x);
}

int	calculate_wall_dimensions(t_game *game, \
						double perp_wall_dist, int *draw_start, int *draw_end)
{
	int	line_height;

	line_height = (int)(game->screen_size_y / perp_wall_dist);
	*draw_start = -line_height / 2 + game->screen_size_y / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = line_height / 2 + game->screen_size_y / 2;
	if (*draw_end >= game->screen_size_y)
		*draw_end = game->screen_size_y - 1;
	return (line_height);
}

void	calculate_draw_pos(\
				int line_height, int screen_size_y, int draw_pos[2])
{
	draw_pos[0] = -line_height / 2 + screen_size_y / 2;
	if (draw_pos[0] < 0)
		draw_pos[0] = 0;
	draw_pos[1] = line_height / 2 + screen_size_y / 2;
	if (draw_pos[1] >= screen_size_y)
		draw_pos[1] = screen_size_y - 1;
}

void	calculate_wall_and_tex_x(\
	t_game *game, double perp_wall_dist, double *wall_x, int *tex_x)
{
	if (game->ray.side == NORTH || game->ray.side == SOUTH)
		*wall_x = game->player.pos_x + perp_wall_dist * game->ray.ray_dir_x;
	else
		*wall_x = game->player.pos_y + perp_wall_dist * game->ray.ray_dir_y;
	*wall_x -= floor(*wall_x);
	if (game->ray.side == NORTH || game->ray.side == SOUTH)
		*tex_x = (int)(*wall_x * (double)game->mlx.north_texture.width);
	else
		*tex_x = (int)(*wall_x * (double)game->mlx.east_texture.width);
}
