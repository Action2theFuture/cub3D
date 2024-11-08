/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:54:08 by max               #+#    #+#             */
/*   Updated: 2024/11/08 14:34:00 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static bool	load_single_texture(void *mlx_ptr, t_texture *texture, char *path)
{
	int width;
	int height;

	texture->img = mlx_xpm_file_to_image(mlx_ptr, path, &width, &height);
	if (!texture->img)
	{
		fprintf(stderr, "Error: Failed to load texture: %s\n", path);
		return false;
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel, &texture->line_length, &texture->endian);
	texture->width = width;
	texture->height = height;
	return true;
}

static bool load_textures(t_game *game, t_description_file *df)
{
	if (!load_single_texture(game->mlx.ptr, &game->mlx.north_texture, df->elements.north_path) ||
		!load_single_texture(game->mlx.ptr, &game->mlx.south_texture, df->elements.south_path) ||
		!load_single_texture(game->mlx.ptr, &game->mlx.east_texture, df->elements.east_path) ||
		!load_single_texture(game->mlx.ptr, &game->mlx.west_texture, df->elements.west_path))
	{
		clean_and_destroy_all(game, df);
		return (false);
	}
    // 디버그 로그 추가
    printf("Loaded NORTH texture: %s (Width: %d, Height: %d)\n", df->elements.north_path, game->mlx.north_texture.width, game->mlx.north_texture.height);
    printf("Loaded SOUTH texture: %s (Width: %d, Height: %d)\n", df->elements.south_path, game->mlx.south_texture.width, game->mlx.south_texture.height);
    printf("Loaded EAST texture: %s (Width: %d, Height: %d)\n", df->elements.east_path, game->mlx.east_texture.width, game->mlx.east_texture.height);
    printf("Loaded WEST texture: %s (Width: %d, Height: %d)\n", df->elements.west_path, game->mlx.west_texture.width, game->mlx.west_texture.height);
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
	if (!load_textures(game, df))
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