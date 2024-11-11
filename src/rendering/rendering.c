/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:18:01 by junsan            #+#    #+#             */
/*   Updated: 2024/11/11 14:05:28 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	init_image(t_game	*game)
{
	if (game->img.img)
		mlx_destroy_image(game->mlx.ptr, game->img.img);
	game->img.img = mlx_new_image(game->mlx.ptr, \
							game->screen_size_x, game->screen_size_y);
	if (!game->img.img)
		return (perror("Failed to create image"), -1);
	game->img.addr = mlx_get_data_addr(game->img.img, \
		&game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	if (!game->img.addr)
		return (perror("Failed to get image address"), -1);
	return (0);
}

static void	draw_ceiling_and_floor(t_game *game)
{
	int	ceiling_limit;
	int	x;
	int	y;

	ceiling_limit = game->screen_size_y / 2;
	y = -1;
	while (++y < game->screen_size_y)
	{
		x = -1;
		while (++x < game->screen_size_x)
		{
			if (y < ceiling_limit)
				put_pixel(game, x, y, \
				(game->df->elements.ceiling.red << 16) | \
				(game->df->elements.ceiling.green << 8) | \
				game->df->elements.ceiling.blue);
			else
				put_pixel(game, x, y, \
				(game->df->elements.floor.red << 16) | \
				(game->df->elements.floor.green << 8) | \
				game->df->elements.floor.blue);
		}
	}
}

static void	update_window(t_game *game)
{
	if (init_image(game) == -1)
		exit(1);
	draw_ceiling_and_floor(game);
	perform_raycasting(game);
	mlx_put_image_to_window(game->mlx.ptr, \
						game->mlx.windows, game->img.img, 0, 0);
}

void	render_frame(t_game *game)
{
	update_window(game);
}
