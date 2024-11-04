/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:50:19 by max               #+#    #+#             */
/*   Updated: 2024/11/04 16:40:08 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	destroy_texture(t_data *data)
{
	if (data->mlx.north_texture)
		mlx_destroy_image(data->mlx.ptr, data->mlx.north_texture);
	if (data->mlx.south_texture)
		mlx_destroy_image(data->mlx.ptr, data->mlx.south_texture);
	if (data->mlx.west_texture)
		mlx_destroy_image(data->mlx.ptr, data->mlx.west_texture);
	if (data->mlx.east_texture)
		mlx_destroy_image(data->mlx.ptr, data->mlx.east_texture);
}

void	clean_and_destroy_all(t_data *data, t_description_file *df)
{
	destroy_texture(data);
	destroy_mlx_specific(data);
	clean_all(df);
}
