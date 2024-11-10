/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:59:32 by junsan            #+#    #+#             */
/*   Updated: 2024/11/09 13:00:42 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//  Bresenham line algoritm
//  params[4] --------------
//  params[0], params[1] => delta_x, delta_y
//  params[2], params[3] => step_x, step_y
static void	draw_line(\
		t_game *game, int player_pos[2], int line_pos[2], int color)
{
	int	params[4];
	int	err;
	int	e2;

	init_line(player_pos, line_pos, params, &err);
	while (true)
	{
		put_pixel(game, player_pos[0], player_pos[1], color);
		if (player_pos[0] == line_pos[0] && player_pos[1] == line_pos[1])
			break ;
		e2 = 2 * err;
		if (e2 > -params[1])
		{
			err -= params[1];
			player_pos[0] += params[2];
		}
		if (e2 < params[0])
		{
			err += params[0];
			player_pos[1] += params[3];
		}
	}
}

static void	draw_player_circle(\
				t_game *game, int player_x, int player_y, int radius)
{
	int	i;
	int	j;

	i = player_y - radius;
	while (i <= player_y + radius)
	{
		j = player_x - radius;
		while (j <= player_x + radius)
		{
			if ((j - player_x) * (j - player_x) + \
				(i - player_y) * (i - player_y) <= radius * radius)
				put_pixel(game, j, i, GREEN);
			j++;
		}
		i++;
	}
}

static void	draw_player(t_game *game)
{
	double	distance_to_wall;
	double	dir_len;
	int		player_pos[2];
	int		line_pos[2];
	int		radius;

	player_pos[0] = game->player.pos_x * MINIMAP_SCALE + game->minimap_pos_x;
	player_pos[1] = game->player.pos_y * MINIMAP_SCALE + game->minimap_pos_y;
	radius = MINIMAP_SCALE / 2;
	draw_player_circle(game, player_pos[0], player_pos[1], radius);
	distance_to_wall = calculate_distance_to_wall(game);
	dir_len = (distance_to_wall * MINIMAP_SCALE);
	line_pos[0] = player_pos[0] + (int)(game->player.dir_x * dir_len);
	line_pos[1] = player_pos[1] + (int)(game->player.dir_y * dir_len);
	draw_line(game, player_pos, line_pos, RED);
}

static void	draw_rectangle(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = y;
	while (i < y + MINIMAP_SCALE)
	{
		j = x;
		while (j < x + MINIMAP_SCALE)
		{
			put_pixel(game, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	int	map_x;
	int	map_y;
	int	pixel_x;
	int	pixel_y;

	map_y = 0;
	while (map_y < game->df->map_height)
	{
		map_x = 0;
		while (map_x < game->df->map_width)
		{
			pixel_x = map_x * MINIMAP_SCALE + game->minimap_pos_x;
			pixel_y = map_y * MINIMAP_SCALE + game->minimap_pos_y;
			if (game->df->map[map_y][map_x] == '1')
				draw_rectangle(game, pixel_x, pixel_y, WHITE);
			else
				draw_rectangle(game, pixel_x, pixel_y, BLACK);
			map_x++;
		}
		map_y++;
	}
	draw_player(game);
}
