/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:18:01 by junsan            #+#    #+#             */
/*   Updated: 2024/11/08 16:21:18 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_pixel_color(t_texture texture, int x, int y)
{
	char	*pixel;

	pixel = texture.addr + \
		(y * texture.line_length + x * (texture.bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= game->screen_size_x || y < 0 || y >= game->screen_size_y)
		return ;
	dst = game->img.addr + \
		(y * game->img.line_length + x * (game->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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

static void	update_window(t_game *game)
{
	if (init_image(game) == -1)
		exit(1);
	ft_memset(game->img.addr, 0, game->screen_size_x * game->screen_size_y * \
		(game->img.bits_per_pixel / 8));
	perform_raycasting(game);
	mlx_put_image_to_window(game->mlx.ptr, \
						game->mlx.windows, game->img.img, 0, 0);
}

void	render_frame(t_game *game)
{
	update_window(game);
}
