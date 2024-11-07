/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 04:18:51 by max               #+#    #+#             */
/*   Updated: 2024/11/07 09:28:00 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

static void	draw_wall_column(t_game *game, int x, int draw_pos[2], int color)
{
	int	y;

	y = draw_pos[0];
	while (y < draw_pos[1])
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
		draw_wall_column(game, x, draw_pos, color);
		x++;
	}
}
