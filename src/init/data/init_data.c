/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:30:10 by max               #+#    #+#             */
/*   Updated: 2024/10/31 20:42:38 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void init_player_view_angle(t_data *data, char c)
{
    if (c == 'N')
        data->player.view_angle = 0;
    if (c == 'E')
        data->player.view_angle = 90;
    if (c == 'S')
        data->player.view_angle = 180;
    if (c == 'W')
        data->player.view_angle = 270;
}

void init_player_position(t_data *data)
{
    int x;
    int y;

    y = 0;

    while (y < data->df->map_height)
    {
        x = 0;
        while (data->df->map[y][x])
        {
            if (is_valid_player_char(data->df->map[y][x]))
            {
                init_player_view_angle(data, data->df->map[y][x]);
                data->player.pos_x = x + 0.5;
                data->player.pos_y = y + 0.5;
            }
            x++;
        }
        y++;
    }
    return;
}

void init_data(t_data *data)
{
    init_player_position(data);
    printf("view = %f\n", data->player.view_angle);
}