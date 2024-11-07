/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:24:06 by max               #+#    #+#             */
/*   Updated: 2024/11/07 01:39:24 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static bool	check_up_of_map(t_description_file *desc_file)
{
	int		i;
	bool	is_map_not_enclosed;

	i = 0;
	is_map_not_enclosed = false;
	while (desc_file->map[0][i])
	{	
		if (desc_file->map[0][i] == '0' || is_valid_player_char(desc_file->map[0][i]))
			return (printf("Error\nThe map is not enclosed by walls\n"), false);
		if (desc_file->map[0][i] == 32)
			flood_fill(desc_file, 0, i, &is_map_not_enclosed);
		if (is_map_not_enclosed == true)
			return (printf("Error\nThe map is not enclosed by walls\n"), false);
		if (desc_file->border_player == true)
			return (printf("Error\nPlayer is outside or on the edge of the map\n"), false);
		i++;
	}
	return (true);
}

static bool	check_down_of_map(t_description_file *desc_file)
{
	int		i;
	bool	is_map_not_enclosed;

	i = 0;
	is_map_not_enclosed = false;
	while (desc_file->map[desc_file->map_height - 1][i])
	{
		if (desc_file->map[desc_file->map_height - 1][i] == '0' || is_valid_player_char(desc_file->map[desc_file->map_height - 1][i]))
			return (printf("Error\nThe map is not enclosed by walls\n"), false);
		if (desc_file->map[desc_file->map_height - 1][i] == 32)
			flood_fill(desc_file, desc_file->map_height - 1, i, \
			&is_map_not_enclosed);
		if (is_map_not_enclosed == true)
			return (printf("Error\nThe map is not enclosed by walls\n"), false);
		if (desc_file->border_player == true)
			return (printf("Error\nPlayer is outside or on the edge of the map\n"), false);
		i++;
	}
	return (true);
}

static bool	check_left_of_map(t_description_file *desc_file)
{
	int		i;
	bool	is_map_not_enclosed;

	i = 0;
	is_map_not_enclosed = false;
	while (i < desc_file->map_height)
	{
		if (desc_file->map[i][0] == '0' || is_valid_player_char(desc_file->map[i][0]))
			return (printf("Error\nThe map is not enclosed by walls\n"), false);
		if (desc_file->map[i][0] == 32)
			flood_fill(desc_file, i, 0, &is_map_not_enclosed);
		if (is_map_not_enclosed == true)
			return (printf("Error\nThe map is not enclosed by walls\n"), false);
		if (desc_file->border_player == true)
			return (printf("Error\nPlayer is outside or on the edge of the map\n"), false);
		i++;
	}
	return (true);
}

static bool	check_right_of_map(t_description_file *desc_file)
{
	int		i;
	bool	is_map_not_enclosed;

	i = 0;
	is_map_not_enclosed = false;
	while (i < desc_file->map_height)
	{
		if (desc_file->map[i][desc_file->map_width - 1] == '0' || is_valid_player_char(desc_file->map[i][desc_file->map_width - 1]))
			return (printf("Error\nThe map is not enclosed by walls\n"), false);
		if (desc_file->map[i][desc_file->map_width - 1] == 32)
			flood_fill(desc_file, i, desc_file->map_width - 1, \
			&is_map_not_enclosed);
		if (is_map_not_enclosed == true)
			return (printf("Error\nThe map is not enclosed by walls\n"), false);
		if (desc_file->border_player == true)
			return (printf("Error\nPlayer is outside or on the edge of the map\n"), false);
		i++;
	}
	return (true);
}

bool	check_walls_surrounding_map(t_description_file *desc_file)
{
	if (!check_up_of_map(desc_file))
		return (false);
	if (!check_down_of_map(desc_file))
		return (false);
	if (!check_left_of_map(desc_file))
		return (false);
	if (!check_right_of_map(desc_file))
		return (false);
	return (true);
}
