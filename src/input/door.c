/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:18:59 by junsan            #+#    #+#             */
/*   Updated: 2024/11/11 22:35:51 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	toggle_door_state(t_game *game, int map_x, int map_y)
{
	int (i) = -1;
	while (++i < game->door_cnt)
	{
		if (game->doors[i].x == map_x && game->doors[i].y == map_y)
		{
			if (DEBUG_MODE)
				printf("Toggling door at (%d, %d). Current state: %d\n", \
				map_x, map_y, game->doors[i].state);
			if (game->doors[i].state == DOOR_CLOSED)
			{
				game->doors[i].state = DOOR_OPENING;
				game->doors[i].animation_timer = 0.0;
			}
			else if (game->doors[i].state == DOOR_OPEN)
			{
				game->doors[i].state = DOOR_CLOSING;
				game->doors[i].animation_timer = 0.0;
			}
			return ;
		}
	}
}

void	update_doors(t_game *game, double delta_time)
{
	int (i) = -1;
	while (++i < game->door_cnt)
	{
		if (game->doors[i].state == DOOR_OPENING || \
			game->doors[i].state == DOOR_CLOSING)
		{
			game->doors[i].animation_timer += delta_time;
			if (game->doors[i].animation_timer >= ANIMATION_DURATION)
			{
				if (game->doors[i].state == DOOR_OPENING)
				{
					game->doors[i].state = DOOR_OPEN;
					game->df->map[game->doors[i].y][game->doors[i].x] = \
						OPENED_DOOR;
				}
				else if (game->doors[i].state == DOOR_CLOSING)
				{
					game->doors[i].state = DOOR_CLOSED;
					game->df->map[game->doors[i].y][game->doors[i].x] = \
						CLOSED_DOOR;
				}
			}
		}
	}
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
