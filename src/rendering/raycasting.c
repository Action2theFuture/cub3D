/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 04:18:51 by max               #+#    #+#             */
/*   Updated: 2024/11/06 17:18:06 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// improving the ray direction calculation
// printf("Ray %d: camera_x=%.2f, ray_dir_x=%.2f, \
// ray_dir_y=%.2f\n", x, camera_x, *ray_dir_x, *ray_dir_y);
static void	calculate_ray_direction(t_game *game, \
						int x, double *ray_dir_x, double *ray_dir_y)
{
	double	camera_x;

	camera_x = 2.0 * x / (double)game->screen_size_x - 1.0;
	*ray_dir_x = game->player.dir_x + game->player.cam_vector_x * camera_x;
	*ray_dir_y = game->player.dir_y + game->player.cam_vector_y * camera_x;
}

static void	init_dda(t_game *game, \
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
	ray->hit = false;
	ray->side = 0;
}

static void	perform_dda(t_game *game, t_ray *ray)
{
	while (ray->hit == false)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_x < 0 || ray->map_x >= game->df->map_width || \
			ray->map_y < 0 || ray->map_y >= game->df->map_height)
		{
			ray->hit = true;
			break ;
		}
		if (game->df->map == NULL || game->df->map[ray->map_y] == NULL)
		{
			ray->hit = true;
			break;
		}
		if (game->df->map[ray->map_y][ray->map_x] == '1')
			ray->hit = true;
	}
}

static double	calculate_perp_wall_dist(t_game *game, t_ray *ray)
{
	double	perp_wall_dist;

	if (ray->side == 0)
		perp_wall_dist = (ray->map_x - game->player.pos_x + \
			(1 - ray->step_x) / 2.0) / ray->ray_dir_x;
	else
		perp_wall_dist = (ray->map_y - game->player.pos_y + \
			(1 - ray->step_y) / 2.0) / ray->ray_dir_y;
	return (perp_wall_dist);
}

static int	calculate_wall_dimensions(t_game *game, \
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

static int	determine_wall_color(int side)
{
	int	color;

	if (side == 0)
		color = RED;
	else
		color = GREEN;
	if (side == 1)
		color /= 2;
	return (color);
}

static void	draw_wall_column(t_game *game, int x, int draw_start, int draw_end, int color)
{
	int	y;

	y = draw_start;
	while (y < draw_end)
	{
		put_pixel(game, x, y, color);
		y++;
	}
}

/*
// void perform_raycasting(t_game *game)
// {
//     int x = 0;
//     double ray_dir[2];
//     double perp_wall_dist;
//     int draw_start, draw_end;

//     while (x < game->screen_size_x)
//     {
//         calculate_ray_direction(game, x, &ray_dir[0], &ray_dir[1]);
//         game->ray.ray_dir_x = ray_dir[0];
//         game->ray.ray_dir_y = ray_dir[1];

//         printf("Ray %d: dir_x=%.2f, dir_y=%.2f\n", x, ray_dir[0], ray_dir[1]);

//         initialize_dda(game, ray_dir[0], ray_dir[1], &game->ray);
//         perform_dda(game, &game->ray);

//         if (game->ray.hit)
//         {
//             perp_wall_dist = calculate_perp_wall_dist(game, &game->ray);
//             printf("Ray %d hit wall at distance=%.2f\n", x, perp_wall_dist);

//             calculate_wall_dimensions(game, perp_wall_dist, \
//             &draw_start, &draw_end);

//             int color = determine_wall_color(game->ray.side);
//             printf(\
//          "Drawing wall column at x=%d from y=%d to y=%d with color=0x%06X\n",
//                    x, draw_start, draw_end, color);
//             draw_wall_column(game, x, draw_start, draw_end, color);
//         }
//         else
//         {
//             printf("Ray %d did not hit any wall.\n", x);
//         }

//         x++;
//     }
// }
*/

void	perform_raycasting(t_game *game)
{
	double	ray_dir[2];
	double	perp_wall_dist;
	int		x;
	int		draw_pos[2];
	int		color;

	x = 0;
	while (x < game->screen_size_x)
	{
		calculate_ray_direction(game, x, &ray_dir[0], &ray_dir[1]);
		game->ray.ray_dir_x = ray_dir[0];
		game->ray.ray_dir_y = ray_dir[1];
		init_dda(game, ray_dir[0], ray_dir[1], &game->ray);
		perform_dda(game, &game->ray);
		perp_wall_dist = calculate_perp_wall_dist(game, &game->ray);
		calculate_wall_dimensions(game, \
							perp_wall_dist, &draw_pos[0], &draw_pos[1]);
		color = determine_wall_color(game->ray.side);
		draw_wall_column(game, x, draw_pos[0], draw_pos[1], color);
		x++;
	}
}
