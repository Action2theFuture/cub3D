/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:57:05 by junsan            #+#    #+#             */
/*   Updated: 2024/11/07 09:16:22 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	set_direction_north(t_game *game, double plane_len)
{
	game->player.dir_x = 0.0;
	game->player.dir_y = -1.0;
	game->player.cam_vector_x = plane_len;
	game->player.cam_vector_y = 0.0;
}

void	set_direction_south(t_game *game, double plane_len)
{
	game->player.dir_x = 0.0;
	game->player.dir_y = 1.0;
	game->player.cam_vector_x = -plane_len;
	game->player.cam_vector_y = 0.0;
}

void	set_direction_east(t_game *game, double plane_len)
{
	game->player.dir_x = 1.0;
	game->player.dir_y = 0.0;
	game->player.cam_vector_x = 0.0;
	game->player.cam_vector_y = plane_len;
}

void	set_direction_west(t_game *game, double plane_len)
{
	game->player.dir_x = -1.0;
	game->player.dir_y = 0.0;
	game->player.cam_vector_x = 0.0;
	game->player.cam_vector_y = -plane_len;
}
