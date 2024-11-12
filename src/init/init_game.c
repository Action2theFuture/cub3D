/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:54:08 by max               #+#    #+#             */
/*   Updated: 2024/11/11 22:25:52 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static bool	init_window(t_game *game, t_description_file *df)
{
	mlx_get_screen_size(\
				game->mlx.ptr, &game->screen_size_x, &game->screen_size_y);
	game->mlx.windows = mlx_new_window(\
			game->mlx.ptr, game->screen_size_x, game->screen_size_y, CUB3D);
	if (game->mlx.windows == NULL)
		return (clean_and_destroy_all(game, df), false);
	return (true);
}

static bool	init_mlx(t_game *game, t_description_file *df)
{
	game->mlx.ptr = mlx_init();
	if (game->mlx.ptr == NULL)
		return (print_err(MLX_INIT_FAIL), clean_all(df), false);
	if (!init_window(game, df))
		return (print_err(MLX_INIT_WINDOW_FAIL), false);
	if (!init_texture(game, df))
		return (print_err(MLX_INIT_WINDOW_FAIL), false);
	return (true);
}

bool	init_game(t_game *game, t_description_file *df)
{
	if (!init_mlx(game, df))
		return (false);
	game->df = df;
	init_player(game);
	if (BONUS)
		init_doors(game);
	init_minimap(game);
	if (DEBUG_MODE)
		debug_map_and_df(df);
	render_frame(game);
	return (true);
}
