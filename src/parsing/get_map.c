/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 00:06:18 by max               #+#    #+#             */
/*   Updated: 2024/11/10 22:20:48 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static bool	new_line_in_map(t_description_file *df)
{
	int	i;
	int	j;

	i = 0;
	while (i < df->map_height)
	{
		j = skype_space(df->map[i]);
		if (df->map[i][j] == '\n')
			return (true);
		i++;
	}
	return (false);
}

static void	get_map_size(t_description_file *df)
{
	char	*line;
	int		i;
	bool	end_of_elements;

	end_of_elements = false;
	line = get_next_line(df->fd);
	while (line)
	{
		i = skype_space(line);
		if (line[i] == '\n' && end_of_elements == false)
			df->elements_lines++;
		else
			end_of_elements = true;
		if (end_of_elements == true
			&& ft_strlen_map(line) > df->map_width)
			df->map_width = ft_strlen_map(line);
		if (end_of_elements == true)
			df->map_height++;
		free(line);
		line = get_next_line(df->fd);
	}
	close(df->fd);
}

static void	reach_map_start(t_description_file *df)
{
	int		i;
	char	*line;

	i = 0;
	while (i < df->elements_lines)
	{
		line = get_next_line(df->fd);
		free(line);
		i++;
	}
}

static bool	extract_map_lines(t_description_file *df)
{
	int	i;

	i = 0;
	df->map = malloc(df->map_height * sizeof(char *));
	if (df->map == NULL)
		return (print_err(MALLOC_FAIL), false);
	while (i < df->map_height)
	{
		df->map[i] = get_next_line(df->fd);
		if (df->map[i] == NULL)
			return (print_err(MALLOC_FAIL),
				clean_partial_array(df->map, i), false);
		i++;
	}
	return (true);
}

bool	get_map(t_description_file *df, char **argv)
{
	get_map_size(df);
	if (df->map_height == 0)
		return (print_err(NO_MAP), false);
	df->fd = open(argv[1], O_RDONLY);
	if (df->fd == OPEN_FAILED)
		return (print_err(FILE_OPEN_FAIL), false);
	reach_map_start(df);
	if (!extract_map_lines(df))
		return (false);
	if (new_line_in_map(df))
		return (print_err(NEW_LINE), false);
	if (!parse_map(df))
		return (false);
	close(df->fd);
	return (true);
}
