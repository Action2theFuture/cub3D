/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 23:34:36 by junsan            #+#    #+#             */
/*   Updated: 2024/11/11 21:15:47 by junsan           ###   ########.fr       */
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
