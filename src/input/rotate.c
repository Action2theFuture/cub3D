/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:08:09 by junsan            #+#    #+#             */
/*   Updated: 2024/11/06 15:59:30 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_cam_x;

	old_dir_x = game->player.dir_x;
	old_cam_x = game->player.cam_vector_x;
	game->player.dir_x = game->player.dir_x * cos(ROT_SPEED) - \
		game->player.dir_y * sin(ROT_SPEED);
	game->player.dir_y = old_dir_x * sin(ROT_SPEED) + \
		game->player.dir_y * cos(ROT_SPEED);
	game->player.cam_vector_x = game->player.cam_vector_x * cos(ROT_SPEED) - \
		game->player.cam_vector_y * sin(ROT_SPEED);
	game->player.cam_vector_y = old_cam_x * sin(ROT_SPEED) + \
		game->player.cam_vector_y * cos(ROT_SPEED);
}

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_cam_x;

	old_dir_x = game->player.dir_x;
	old_cam_x = game->player.cam_vector_x;
	game->player.dir_x = game->player.dir_x * cos(-ROT_SPEED) - \
		game->player.dir_y * sin(-ROT_SPEED);
	game->player.dir_y = old_dir_x * sin(-ROT_SPEED) + \
		game->player.dir_y * cos(-ROT_SPEED);
	game->player.cam_vector_x = game->player.cam_vector_x * cos(-ROT_SPEED) - \
		game->player.cam_vector_y * sin(-ROT_SPEED);
	game->player.cam_vector_y = old_cam_x * sin(-ROT_SPEED) + \
		game->player.cam_vector_y * cos(-ROT_SPEED);
}
