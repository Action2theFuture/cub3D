/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:54:08 by max               #+#    #+#             */
/*   Updated: 2024/11/10 22:42:51 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static bool	load_single_texture(void *mlx_ptr, t_texture *texture, char *path)
{
	int	width;
	int	height;

	texture->img = mlx_xpm_file_to_image(mlx_ptr, path, &width, &height);
	if (!texture->img)
	{
		fprintf(stderr, "Error: Failed to load texture: %s\n", path);
		return (false);
	}
	texture->addr = mlx_get_data_addr(\
					texture->img, &texture->bits_per_pixel, \
					&texture->line_length, &texture->endian);
	texture->width = width;
	texture->height = height;
	return (true);
}

static bool	load_textures(t_game *game, t_description_file *df)
{
	if (!load_single_texture(\
		game->mlx.ptr, &game->mlx.north_texture, df->elements.north_path) || \
		!load_single_texture(\
		game->mlx.ptr, &game->mlx.south_texture, df->elements.south_path) || \
		!load_single_texture(\
		game->mlx.ptr, &game->mlx.east_texture, df->elements.east_path) || \
		!load_single_texture(\
		game->mlx.ptr, &game->mlx.west_texture, df->elements.west_path))
	{
		clean_and_destroy_all(game, df);
		return (false);
	}
	if (BONUS)
	{
		df->elements.door_path = DOOR_PATH;
		load_single_texture(\
			game->mlx.ptr, &game->mlx.door_texture, df->elements.door_path);
	}
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
		return (print_err(MLX_INIT_FAIL), clean_all(df), false);
	if (!init_window(game, df))
		return (print_err(MLX_INIT_WINDOW_FAIL), false);
	if (!load_textures(game, df))
		return (print_err(MLX_INIT_WINDOW_FAIL), false);
	return (true);
}

bool	init_game(t_game *game, t_description_file *df)
{
	if (!init_mlx(game, df))
		return (false);
	game->df = df;
	init_player(game);
	init_minimap(game);
	if (DEBUG_MODE)
		debug_map_and_df(df);
	render_frame(game);
	return (true);
}
