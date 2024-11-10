/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:18:59 by junsan            #+#    #+#             */
/*   Updated: 2024/11/09 17:54:50 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	toggle_door_state(t_game *game, int map_x, int map_y)
{
	if (game->df->map[map_y][map_x] == CLOSED_DOOR)
		game->df->map[map_y][map_x] = OPENED_DOOR;
	else if (game->df->map[map_y][map_x] == OPENED_DOOR)
		game->df->map[map_y][map_x] = CLOSED_DOOR;
}

void	toggle_door(t_game *game)
{
	double	door[2];
	char	cur_tile;
	int		map[2];
	int		i;

	i = 1;
	while (i <= 2)
	{
		door[0] = game->player.pos_x + game->player.dir_x * i;
		door[1] = game->player.pos_y + game->player.dir_y * i;
		map[0] = (int)(door[0]);
		map[1] = (int)(door[1]);
		if (map[0] >= 0 && map[0] < game->df->map_width && \
			map[1] >= 0 && map[1] < game->df->map_height)
		{
			cur_tile = game->df->map[map[1]][map[0]];
			if (cur_tile == CLOSED_DOOR || cur_tile == OPENED_DOOR)
			{
				toggle_door_state(game, map[0], map[1]);
				return ;
			}
		}
		i++;
	}
}
