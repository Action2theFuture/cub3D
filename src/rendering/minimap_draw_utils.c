/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:25:36 by junsan            #+#    #+#             */
/*   Updated: 2024/11/09 13:00:29 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	is_wall(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->df->map_width || y < 0 || y >= game->df->map_height)
		return (true);
	if (game->df->map[y][x] == '1')
		return (true);
	return (false);
}

double	calculate_distance_to_wall(t_game *game)
{
	double	distance;
	double	step;
	double	pos[2];
	double	dir[2];

	pos[0] = game->player.pos_x;
	pos[1] = game->player.pos_y;
	dir[0] = game->player.dir_x;
	dir[1] = game->player.dir_y;
	distance = 0.0;
	step = 0.1;
	while (true)
	{
		pos[0] += dir[0] * step;
		pos[1] += dir[1] * step;
		distance += step;
		if (is_wall(game, (int)pos[0], (int)pos[1]))
			return (distance);
	}
}

void	init_line(\
			int player_pos[2], int line_pos[2], int params[4], int *err)
{
	params[0] = abs(line_pos[0] - player_pos[0]);
	params[1] = abs(line_pos[1] - player_pos[1]);
	*err = params[0] - params[1];
	if (player_pos[0] < line_pos[0])
		params[2] = 1;
	else
		params[2] = -1;
	if (player_pos[1] < line_pos[1])
		params[3] = 1;
	else
		params[3] = -1;
}
