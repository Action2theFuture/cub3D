/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 03:13:39 by max               #+#    #+#             */
/*   Updated: 2024/11/10 22:20:48 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static char	*format_line(t_description_file *df, char *map_line,
		char *new_line)
{
	int	i;

	i = 0;
	while (map_line[i] != '\n' && map_line[i])
	{
		new_line[i] = map_line[i];
		i++;
	}
	while (i < df->map_width)
	{
		new_line[i] = ' ';
		i++;
	}
	new_line[i] = '\0';
	free(map_line);
	return (new_line);
}

static void	fill_internal_spaces(t_description_file *df)
{
	int	i;
	int	j;

	i = 0;
	while (i < df->map_height)
	{
		j = 0;
		while (df->map[i][j])
		{
			if (df->map[i][j] == ' ')
				df->map[i][j] = ROAD;
			j++;
		}
		i++;
	}
}

void	flood_fill(t_description_file *df, int y, int x,
		bool *is_map_not_enclosed)
{
	if (x < 0 || y < 0 || x > df->map_width - 1
		|| y > df->map_height - 1 || df->map[y][x] == WALL)
		return ;
	if (is_valid_player_char(df->map[y][x]))
	{
		df->border_player = true;
		return ;
	}
	if (df->map[y][x] == ROAD)
	{
		*is_map_not_enclosed = true;
		return ;
	}
	if (df->map[y][x] == ' ')
		df->map[y][x] = WALL;
	flood_fill(df, y - 1, x, is_map_not_enclosed);
	flood_fill(df, y + 1, x, is_map_not_enclosed);
	flood_fill(df, y, x - 1, is_map_not_enclosed);
	flood_fill(df, y, x + 1, is_map_not_enclosed);
}

bool	parse_map(t_description_file *df)
{
	int		i;
	char	*line;

	i = 0;
	while (i < df->map_height)
	{
		if (ft_strlen_map(df->map[i]) < df->map_width)
		{
			line = malloc((df->map_width + 1) * sizeof(char));
			if (!line)
				return (print_err(MALLOC_FAIL), false);
			df->map[i] = format_line(df, df->map[i], line);
		}
		else
			df->map[i][ft_strlen_map(df->map[i])] = '\0';
		i++;
	}
	if (!check_walls_surrounding_map(df))
		return (false);
	fill_internal_spaces(df);
	return (true);
}
