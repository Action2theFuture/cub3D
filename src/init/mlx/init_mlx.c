/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:54:08 by max               #+#    #+#             */
/*   Updated: 2024/10/31 15:06:23 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "../../../lib/minilibx-linux/mlx.h"

static bool load_texture(t_data *data, t_description_file *df)
{
    int x;
    int y;

    x = 128;
    y = 128;

    data->mlx.north_texture = mlx_xpm_file_to_image(data->mlx.ptr, df->elements.north_path, &x, &y);
    if (data->mlx.north_texture == NULL)
        return (clean_and_destroy_all(data, df), false);
    data->mlx.south_texture = mlx_xpm_file_to_image(data->mlx.ptr, df->elements.south_path, &x, &y);
    if (data->mlx.north_texture == NULL)
        return (clean_and_destroy_all(data, df), false);
    data->mlx.west_texture = mlx_xpm_file_to_image(data->mlx.ptr, df->elements.west_path, &x, &y);
    if (data->mlx.west_texture == NULL)
        return (clean_and_destroy_all(data, df), false);
    data->mlx.east_texture = mlx_xpm_file_to_image(data->mlx.ptr, df->elements.east_path, &x, &y);
    if (data->mlx.east_texture == NULL)
        return (clean_and_destroy_all(data, df), false);
    return true;
}

static bool init_window(t_data *data, t_description_file *df)
{
    mlx_get_screen_size(data->mlx.ptr, &data->screen_size_x, &data->screen_size_y);
    data->mlx.windows = mlx_new_window(data->mlx.ptr, data->screen_size_x, data->screen_size_y, "CUBE 3D");
    if (data->mlx.windows == NULL)
        return (clean_and_destroy_all(data, df), false);
    return true;
}

static bool init_mlx(t_data *data, t_description_file *df)
{
    data->mlx.ptr = mlx_init();
    if (data->mlx.ptr == NULL)
        return (printf("Error\n,MLX init failed\n"), clean_all(df), false);
    if (!init_window(data, df))
        return (printf("Error\nMLX init windows failed\n"), false);
    if (!load_texture(data, df))
        return (printf("Error\nMLX init image failed\n"), false);
    return true;
}

bool init_mlx_and_data(t_data *data, t_description_file *df)
{
    if (!init_mlx(data, df))
        return false;

    return true;
}
