/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:43:42 by junsan            #+#    #+#             */
/*   Updated: 2024/11/12 17:50:39 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	is_valid_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

bool	is_surround_wall(t_description_file *df, int x, int y)
{
	bool	vertical_check;
	bool	horizontal_check;

	if (y <= 0 || y >= df->map_height - 1 || x <= 0 || x >= df->map_width - 1)
		return (false);
	vertical_check = (df->map[y - 1][x] == WALL && \
					df->map[y + 1][x] == WALL);
	horizontal_check = (df->map[y][x - 1] == WALL && \
					df->map[y][x + 1] == WALL);
	return (vertical_check || horizontal_check);
}
