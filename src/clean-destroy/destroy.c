/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:50:19 by max               #+#    #+#             */
/*   Updated: 2024/11/06 10:02:08 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	destroy_texture(t_game *game)
{
	if (game->mlx.north_texture)
		mlx_destroy_image(game->mlx.ptr, game->mlx.north_texture);
	if (game->mlx.south_texture)
		mlx_destroy_image(game->mlx.ptr, game->mlx.south_texture);
	if (game->mlx.west_texture)
		mlx_destroy_image(game->mlx.ptr, game->mlx.west_texture);
	if (game->mlx.east_texture)
		mlx_destroy_image(game->mlx.ptr, game->mlx.east_texture);
}

void	clean_and_destroy_all(t_game *game, t_description_file *df)
{
	destroy_texture(game);
	destroy_mlx_specific(game);
	clean_all(df);
}
