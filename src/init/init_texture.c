/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:48:09 by junsan            #+#    #+#             */
/*   Updated: 2024/11/11 22:33:08 by junsan           ###   ########.fr       */
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
		print_err(ERR_LOAD_TEXTURE);
		printf(PRINT_RED"\n%s", path);
		return (false);
	}
	texture->addr = mlx_get_data_addr(\
					texture->img, &texture->bits_per_pixel, \
					&texture->line_length, &texture->endian);
	texture->width = width;
	texture->height = height;
	return (true);
}

static bool	is_door(t_description_file *df)
{
	int	i;
	int	j;

	i = -1;
	while (++i < df->map_height)
	{
		j = -1;
		while (++j < df->map_width)
		{
			if (df->map[i][j] == CLOSED_DOOR || \
				df->map[i][j] == OPENED_DOOR)
				return (true);
		}
	}
	return (false);
}

static bool	check_texture_size(t_game *game, const char *texture_name, \
						int tex_width, int tex_height)
{
	t_mlx	*mlx;

	mlx = &game->mlx;
	if (mlx->south_texture.width != tex_width || \
		mlx->south_texture.height != tex_height || \
		mlx->east_texture.width != tex_width || \
		mlx->east_texture.height != tex_height || \
		mlx->west_texture.width != tex_width || \
		mlx->west_texture.height != tex_height)
		return (print_err(ERR_TEXTURE_SIZE), \
		printf(PRINT_RED"Texture : %s\n", texture_name), false);
	return (true);
}

bool	init_texture(t_game *game, t_description_file *df)
{
	if (!load_single_texture(\
		game->mlx.ptr, &game->mlx.north_texture, df->elements.north_path))
		return (clean_and_destroy_all(game, df), false);
	if (!load_single_texture(\
		game->mlx.ptr, &game->mlx.south_texture, df->elements.south_path))
		return (clean_and_destroy_all(game, df), false);
	if (!load_single_texture(\
		game->mlx.ptr, &game->mlx.east_texture, df->elements.east_path))
		return (clean_and_destroy_all(game, df), false);
	if (!load_single_texture(\
		game->mlx.ptr, &game->mlx.west_texture, df->elements.west_path))
		return (clean_and_destroy_all(game, df), false);
	if (!check_texture_size(game, "Wall Texture", \
		game->mlx.north_texture.width, game->mlx.north_texture.height))
		return (clean_and_destroy_all(game, df), false);
	if (BONUS && is_door(df))
	{
		df->elements.door_path = DOOR_PATH;
		if (!load_single_texture(\
		game->mlx.ptr, &game->mlx.door_texture, df->elements.door_path) || \
		!check_texture_size(game, "Door Texture", \
		game->mlx.door_texture.width, game->mlx.door_texture.height))
			return (clean_and_destroy_all(game, df), false);
	}
	return (true);
}
