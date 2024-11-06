/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 00:06:18 by max               #+#    #+#             */
/*   Updated: 2024/11/06 17:26:28 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static bool	new_line_in_map(t_description_file *desc_file)
{
	int	i;
	int	j;

	i = 0;
	while (i < desc_file->map_height)
	{
		j = skype_space(desc_file->map[i]);
		if (desc_file->map[i][j] == '\n')
			return (true);
		i++;
	}
	return (false);
}

static void	get_map_size(t_description_file *desc_file)
{
	char	*line;
	int		i;
	bool	end_of_elements;

	end_of_elements = false;
	line = get_next_line(desc_file->fd);
	while (line)
	{
		i = skype_space(line);
		if (line[i] == '\n' && end_of_elements == false)
			desc_file->elements_lines++;
		else
			end_of_elements = true;
		if (end_of_elements == true && \
			ft_strlen_map(line) > desc_file->map_width)
			desc_file->map_width = ft_strlen_map(line);
		if (end_of_elements == true)
			desc_file->map_height++;
		free(line);
		line = get_next_line(desc_file->fd);
	}
	close(desc_file->fd);
}

static void	reach_map_start(t_description_file *desc_file)
{
	int		i;
	char	*line;

	i = 0;
	while (i < desc_file->elements_lines)
	{
		line = get_next_line(desc_file->fd);
		free(line);
		i++;
	}
}

static bool	extract_map_lines(t_description_file *desc_file)
{
	int	i;

	i = 0;
	desc_file->map = malloc(desc_file->map_height * sizeof(char *));
	if (desc_file->map == NULL)
		return (printf("Error\nMalloc failed\n"), false);
	while (i < desc_file->map_height)
	{
		desc_file->map[i] = get_next_line(desc_file->fd);
		if (desc_file->map[i] == NULL)
			return (printf("Error\nMalloc failed\n"), \
			clean_partial_array(desc_file->map, i), false);
		i++;
	}
	return (true);
}

bool	get_map(t_description_file *desc_file, char **argv)
{
	get_map_size(desc_file);
	desc_file->fd = open(argv[1], O_RDONLY);
	if (desc_file->fd == OPEN_FAILED)
		return (printf("Error\nOpen file failed\n"), false);
	reach_map_start(desc_file);
	if (!extract_map_lines(desc_file))
		return (false);
	if (new_line_in_map(desc_file))
		return (printf("Error\nNew line in map\n"), false);
	parse_map(desc_file);
	close(desc_file->fd);
	return (true);
}
