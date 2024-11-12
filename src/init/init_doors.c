/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:14:25 by junsan            #+#    #+#             */
/*   Updated: 2024/11/11 19:06:53 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	add_door(t_game *game, int x, int y, char state)
{
	if (game->door_cnt >= MAX_DOOR)
	{
		print_err(ERR_MAXIMUM_DOOR);
		return ;
	}
	game->doors[game->door_cnt].x = x;
	game->doors[game->door_cnt].y = y;
	if (state == CLOSED_DOOR)
		game->doors[game->door_cnt].state = DOOR_CLOSED;
	else
		game->doors[game->door_cnt].state = DOOR_OPEN;
	game->doors[game->door_cnt].animation_timer = 0.0;
	game->door_cnt++;
}

void	init_doors(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->door_cnt = 0;
	while (++i < game->df->map_height)
	{
		j = -1;
		while (++j < game->df->map_width)
		{
			if (game->df->map[i][j] == CLOSED_DOOR || \
				game->df->map[i][j] == OPENED_DOOR)
				add_door(game, j, i, game->df->map[i][j]);
		}
	}
}
