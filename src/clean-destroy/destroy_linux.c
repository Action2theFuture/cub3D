/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_linux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:18:19 by junsan            #+#    #+#             */
/*   Updated: 2024/11/06 13:59:01 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	destroy_mlx_specific(t_game *game)
{
	if (game->mlx.windows)
		mlx_destroy_window(game->mlx.ptr, game->mlx.windows);
	game->mlx.windows = NULL;
	if (game->mlx.ptr)
		mlx_destroy_display(game->mlx.ptr);
	free(game->mlx.ptr);
	game->mlx.ptr = NULL;
}
