/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:50:19 by max               #+#    #+#             */
/*   Updated: 2024/10/31 01:18:46 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void destroy_mlx_ptr(t_data *data)
{
    if (data->mlx.ptr)
        mlx_destroy_display(data->mlx.ptr);
    free(data->mlx.ptr);
    data->mlx.ptr = NULL;
}
void destroy_mlx_windows(t_data *data)
{
    if (data->mlx.windows)
        mlx_destroy_window(data->mlx.ptr, data->mlx.windows);
    data->mlx.windows = NULL;
}

void destroy_texture(t_data *data)
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

void clean_and_destroy_all(t_data *data, t_description_file *df)
{
    destroy_texture(data);
    destroy_mlx_windows(data);
    destroy_mlx_ptr(data);
    clean_all(df);
}