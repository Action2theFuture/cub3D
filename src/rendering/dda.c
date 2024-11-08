/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:26:01 by junsan            #+#    #+#             */
/*   Updated: 2024/11/08 16:36:12 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	set_ray_direction(t_game *game, \
					double ray_dir_x, double ray_dir_y, t_ray *ray)
{
	if (ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.pos_x - ray->map_x) * \
			ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.pos_x) * \
			ray->delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.pos_y - ray->map_y) * \
			ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.pos_y) * \
			ray->delta_dist_y;
	}
}

void	init_dda(t_game *game, \
					double ray_dir_x, double ray_dir_y, t_ray *ray)
{
	ray->map_x = (int)game->player.pos_x;
	ray->map_y = (int)game->player.pos_y;
	if (ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray_dir_x);
	if (ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray_dir_y);
	set_ray_direction(game, ray_dir_x, ray_dir_y, ray);
	ray->hit = false;
	ray->side = NORTH;
}

static bool	check_boundary_collision(t_game *game, t_ray *ray)
{
	if (ray->map_x < 0 || ray->map_x >= game->df->map_width || \
		ray->map_y < 0 || ray->map_y >= game->df->map_height)
		return (true);
	if (game->df->map == NULL || game->df->map[ray->map_y] == NULL)
		return (true);
	if (game->df->map[ray->map_y][ray->map_x] == '1')
		return (true);
	return (false);
}

static void	update_ray(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		if (ray->step_x > 0)
			ray->side = WEST;
		else
			ray->side = EAST;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		if (ray->step_y > 0)
			ray->side = NORTH;
		else
			ray->side = SOUTH;
	}
}

void	perform_dda(t_game *game, t_ray *ray)
{
	while (ray->hit == false)
	{
		update_ray(ray);
		if (check_boundary_collision(game, ray))
		{
			ray->hit = true;
			break ;
		}
		if (game->df->map[ray->map_y][ray->map_x] == '1')
			ray->hit = true;
	}
}
