/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 03:13:39 by max               #+#    #+#             */
/*   Updated: 2024/11/07 05:30:30 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static char	*format_line(t_description_file *desc_file, char *map_line,
		char *new_line)
{
	int	i;

	i = 0;
	while (map_line[i] != '\n' && map_line[i])
	{
		new_line[i] = map_line[i];
		i++;
	}
	while (i < desc_file->map_width)
	{
		new_line[i] = ' ';
		i++;
	}
	new_line[i] = '\0';
	free(map_line);
	return (new_line);
}

static void	fill_internal_spaces(t_description_file *desc_file)
{
	int	i;
	int	j;

	i = 0;
	while (i < desc_file->map_height)
	{
		j = 0;
		while (desc_file->map[i][j])
		{
			if (desc_file->map[i][j] == ' ')
				desc_file->map[i][j] = ROAD;
			j++;
		}
		i++;
	}
}

void	flood_fill(t_description_file *desc_file, int y, int x,
		bool *is_map_not_enclosed)
{
	if (x < 0 || y < 0 || x > desc_file->map_width - 1
		|| y > desc_file->map_height - 1 || desc_file->map[y][x] == WALL)
		return ;
	if (is_valid_player_char(desc_file->map[y][x]))
	{
		desc_file->border_player = true;
		return ;
	}
	if (desc_file->map[y][x] == ROAD)
	{
		*is_map_not_enclosed = true;
		return ;
	}
	if (desc_file->map[y][x] == ' ')
		desc_file->map[y][x] = WALL;
	flood_fill(desc_file, y - 1, x, is_map_not_enclosed);
	flood_fill(desc_file, y + 1, x, is_map_not_enclosed);
	flood_fill(desc_file, y, x - 1, is_map_not_enclosed);
	flood_fill(desc_file, y, x + 1, is_map_not_enclosed);
}

bool	parse_map(t_description_file *desc_file)
{
	int		i;
	char	*line;

	i = 0;
	while (i < desc_file->map_height)
	{
		if (ft_strlen_map(desc_file->map[i]) < desc_file->map_width)
		{
			line = malloc((desc_file->map_width + 1) * sizeof(char));
			if (!line)
				return (printf("Error\nMalloc failed\n"), false);
			desc_file->map[i] = format_line(desc_file, desc_file->map[i], line);
		}
		else
			desc_file->map[i][ft_strlen_map(desc_file->map[i])] = '\0';
		i++;
	}
	if (!check_walls_surrounding_map(desc_file))
		return (false);
	fill_internal_spaces(desc_file);
	return (true);
}
