/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:20:56 by junsan            #+#    #+#             */
/*   Updated: 2024/11/06 15:28:42 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	destroy_mlx_specific(t_game *game)
{
	if (game->mlx.windows)
		mlx_destroy_window(game->mlx.ptr, game->mlx.windows);
	game->mlx.windows = NULL;
	return ;
}
