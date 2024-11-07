/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:11:31 by junsan            #+#    #+#             */
/*   Updated: 2024/11/07 04:11:53 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int key_press(int keycode, t_game *game)
{
	printf("\nKEY CODE = %d\n", keycode);
	if (keycode == KEY_W)
		move_forward(game);
	else if (keycode == KEY_S)
		move_backward(game);
	else if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_D)
		move_right(game);
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
