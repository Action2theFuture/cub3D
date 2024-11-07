/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:54:08 by max               #+#    #+#             */
/*   Updated: 2024/11/07 09:13:37 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static bool	load_texture(t_game *game, t_description_file *df)
{
	int	x;
	int	y;

	x = 128;
	y = 128;
	game->mlx.north_texture = mlx_xpm_file_to_image(\
							game->mlx.ptr, df->elements.north_path, &x, &y);
	if (game->mlx.north_texture == NULL)
		return (clean_and_destroy_all(game, df), false);
	game->mlx.south_texture = mlx_xpm_file_to_image(\
							game->mlx.ptr, df->elements.south_path, &x, &y);
	if (game->mlx.south_texture == NULL)
		return (clean_and_destroy_all(game, df), false);
	game->mlx.west_texture = mlx_xpm_file_to_image(\
							game->mlx.ptr, df->elements.west_path, &x, &y);
	if (game->mlx.west_texture == NULL)
		return (clean_and_destroy_all(game, df), false);
	game->mlx.east_texture = mlx_xpm_file_to_image(\
							game->mlx.ptr, df->elements.east_path, &x, &y);
	if (game->mlx.east_texture == NULL)
		return (clean_and_destroy_all(game, df), false);
	return (true);
}

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
		return (printf("Error\n,MLX init failed\n"), clean_all(df), false);
	if (!init_window(game, df))
		return (printf("Error\nMLX init windows failed\n"), false);
	if (!load_texture(game, df))
		return (printf("Error\nMLX init image failed\n"), false);
	return (true);
}

bool	init_game(t_game *game, t_description_file *df)
{
	if (!init_mlx(game, df))
		return (false);
	game->df = df;
	init_player(game);
	debug_map_and_df(df);
	render_frame(game);
	return (true);
}
