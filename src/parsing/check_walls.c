/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:24:06 by max               #+#    #+#             */
/*   Updated: 2024/11/10 22:20:48 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static bool	check_up_of_map(t_description_file *df)
{
	int		i;
	bool	is_map_not_enclosed;

	i = 0;
	is_map_not_enclosed = false;
	while (df->map[0][i])
	{
		if (df->map[0][i] == '0'
			|| is_valid_player_char(df->map[0][i]))
			return (print_err(NOT_ENCLOSED), false);
		if (df->map[0][i] == 32)
			flood_fill(df, 0, i, &is_map_not_enclosed);
		if (is_map_not_enclosed == true)
			return (print_err(NOT_ENCLOSED), false);
		if (df->border_player == true)
			return (print_err(INVALID_PLAYER_LOC), false);
		i++;
	}
	return (true);
}

static bool	check_down_of_map(t_description_file *df)
{
	int		i;
	bool	is_map_not_enclosed;

	i = 0;
	is_map_not_enclosed = false;
	while (df->map[df->map_height - 1][i])
	{
		if (df->map[df->map_height - 1][i] == '0'
			|| is_valid_player_char(df->map[df->map_height
				- 1][i]))
			return (print_err(NOT_ENCLOSED), false);
		if (df->map[df->map_height - 1][i] == 32)
			flood_fill(df, df->map_height - 1, i,
				&is_map_not_enclosed);
		if (is_map_not_enclosed == true)
			return (print_err(NOT_ENCLOSED), false);
		if (df->border_player == true)
			return (print_err(INVALID_PLAYER_LOC), false);
		i++;
	}
	return (true);
}

static bool	check_left_of_map(t_description_file *df)
{
	int		i;
	bool	is_map_not_enclosed;

	i = 0;
	is_map_not_enclosed = false;
	while (i < df->map_height)
	{
		if (df->map[i][0] == '0'
			|| is_valid_player_char(df->map[i][0]))
			return (print_err(NOT_ENCLOSED), false);
		if (df->map[i][0] == 32)
			flood_fill(df, i, 0, &is_map_not_enclosed);
		if (is_map_not_enclosed == true)
			return (print_err(NOT_ENCLOSED), false);
		if (df->border_player == true)
			return (print_err(INVALID_PLAYER_LOC), false);
		i++;
	}
	return (true);
}

static bool	check_right_of_map(t_description_file *df)
{
	int		i;
	bool	is_map_not_enclosed;

	i = 0;
	is_map_not_enclosed = false;
	while (i < df->map_height)
	{
		if (df->map[i][df->map_width - 1] == '0'
			|| is_valid_player_char(df->map[i][df->map_width
				- 1]))
			return (print_err(NOT_ENCLOSED), false);
		if (df->map[i][df->map_width - 1] == 32)
			flood_fill(df, i, df->map_width - 1,
				&is_map_not_enclosed);
		if (is_map_not_enclosed == true)
			return (print_err(NOT_ENCLOSED), false);
		if (df->border_player == true)
			return (print_err(NOT_ENCLOSED), false);
		i++;
	}
	return (true);
}

bool	check_walls_surrounding_map(t_description_file *df)
{
	if (!check_up_of_map(df))
		return (false);
	if (!check_down_of_map(df))
		return (false);
	if (!check_left_of_map(df))
		return (false);
	if (!check_right_of_map(df))
		return (false);
	return (true);
}
