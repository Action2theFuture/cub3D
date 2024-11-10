/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:48:50 by junsan            #+#    #+#             */
/*   Updated: 2024/11/09 14:37:32 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	rotate_player(t_game *game, double rot_speed)
{
	double	old_dir_x;
	double	old_cam_vector_x;

	old_dir_x = game->player.dir_x;
	old_cam_vector_x = game->player.cam_vector_x;
	game->player.dir_x = game->player.dir_x * cos(rot_speed) - \
		game->player.dir_y * sin(rot_speed);
	game->player.dir_y = old_dir_x * sin(rot_speed) + \
		game->player.dir_y * cos(rot_speed);
	game->player.cam_vector_x = game->player.cam_vector_x * cos(rot_speed) - \
		game->player.cam_vector_y * sin(rot_speed);
	game->player.cam_vector_y = old_cam_vector_x * sin(rot_speed) + \
		game->player.cam_vector_y * cos(rot_speed);
}

int	mouse_move(int x, int y, t_game *game)
{
	static int	last_x = -1;
	static int	last_y = -1;
	double		rot_speed;
	int			delta_x;

	if (last_x == -1 && last_y == -1)
	{
		last_x = x;
		last_y = y;
		return (0);
	}
	delta_x = x - last_x;
	last_x = x;
	last_y = y;
	rot_speed = delta_x * ROT_SPEED * ROT_SPEED_CONTROL;
	rotate_player(game, rot_speed);
	return (0);
}
