/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:50:19 by max               #+#    #+#             */
/*   Updated: 2024/11/08 12:20:59 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	destroy_texture(t_game *game)
{
	if (game->mlx.north_texture.img)
		mlx_destroy_image(game->mlx.ptr, game->mlx.north_texture.img);
	if (game->mlx.south_texture.img)
		mlx_destroy_image(game->mlx.ptr, game->mlx.south_texture.img);
	if (game->mlx.west_texture.img)
		mlx_destroy_image(game->mlx.ptr, game->mlx.west_texture.img);
	if (game->mlx.east_texture.img)
		mlx_destroy_image(game->mlx.ptr, game->mlx.east_texture.img);
}

void	clean_and_destroy_all(t_game *game, t_description_file *df)
{
	destroy_texture(game);
	destroy_mlx_specific(game);
	clean_all(df);
}
