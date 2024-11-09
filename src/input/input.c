/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:11:31 by junsan            #+#    #+#             */
/*   Updated: 2024/11/09 15:18:25 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	close_window(t_game *game)
{
	clean_and_destroy_all(game, game->df);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_forward(game);
	else if (keycode == KEY_S)
		move_backward(game);
	else if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_D)
		move_right(game);
	else if (keycode == KEY_E)
		toggle_door(game);
	else if (keycode == KEY_LEFT)
		rotate_left(game);
	else if (keycode == KEY_RIGHT)
		rotate_right(game);
	else if (keycode == KEY_ESC)
	{
		clean_and_destroy_all(game, game->df);
		exit(EXIT_SUCCESS);
	}
	render_frame(game);
	return (0);
}

void	event_listener(t_game *game)
{
	mlx_hook(game->mlx.windows, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx.windows, 6, 1L << 6, mouse_move, game);
	mlx_hook(game->mlx.windows, 17, 0, close_window, game);
}
