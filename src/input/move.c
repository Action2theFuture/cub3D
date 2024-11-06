/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:01:55 by junsan            #+#    #+#             */
/*   Updated: 2024/11/06 17:05:51 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * MOVE_SPEED;
	new_y = game->player.pos_y + game->player.dir_y * MOVE_SPEED;
	if (game->df->map[(int)new_y][(int)game->player.pos_x] == '0')
		game->player.pos_y = new_y;
	if (game->df->map[(int)game->player.pos_y][(int)new_x] == '0')
		game->player.pos_x = new_x;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_x * MOVE_SPEED;
	new_y = game->player.pos_y - game->player.dir_y * MOVE_SPEED;
	if (game->df->map[(int)new_y][(int)game->player.pos_x] == '0')
		game->player.pos_y = new_y;
	if (game->df->map[(int)game->player.pos_y][(int)new_x] == '0')
		game->player.pos_x = new_x;
}

void	move_left(t_game *game)
{
	double	perp_dir_x;
	double	perp_dir_y;
	double	new_x;
	double	new_y;

	perp_dir_x = game->player.dir_y;
	perp_dir_y = -game->player.dir_x;
	new_x = game->player.pos_x + perp_dir_x * MOVE_SPEED;
	new_y = game->player.pos_y + perp_dir_y * MOVE_SPEED;
	if (game->df->map[(int)new_y][(int)game->player.pos_x] == '0')
		game->player.pos_y = new_y;
	if (game->df->map[(int)game->player.pos_y][(int)new_x] == '0')
		game->player.pos_x = new_x;
}

void	move_right(t_game *game)
{
	double	perp_dir_x;
	double	perp_dir_y;
	double	new_x;
	double	new_y;

	perp_dir_x = -game->player.dir_y;
	perp_dir_y = game->player.dir_x;
	new_x = game->player.pos_x + perp_dir_x * MOVE_SPEED;
	new_y = game->player.pos_y + perp_dir_y * MOVE_SPEED;
	if (game->df->map[(int)new_y][(int)game->player.pos_x] == '0')
		game->player.pos_y = new_y;
	if (game->df->map[(int)game->player.pos_y][(int)new_x] == '0')
		game->player.pos_x = new_x;
}
