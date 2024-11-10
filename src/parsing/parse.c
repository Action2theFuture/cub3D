/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:20:25 by max               #+#    #+#             */
/*   Updated: 2024/11/11 00:06:32 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static char	**get_elements(int fd, t_description_file *df)
{
	char **(elements) = malloc(6 * sizeof(char *));
	int (count) = 0;
	int (i) = 0;
	int (j) = 0;
	if (!elements)
		return (NULL);
	while (count < 6)
	{
		elements[i] = get_next_line(fd);
		df->elements_lines++;
		if (!elements[i])
		{
			if (count < 6)
				return (clean_partial_array(elements, i), NULL);
		}
		j = skype_space(elements[i]);
		if (elements[i][j] == '\n')
		{
			free(elements[i]);
			continue ;
		}
		i++;
		count++;
	}
	return (elements);
}

static bool	check_and_store_elements(t_description_file *df,
		char **elements)
{
	if (!check_elements(elements))
		return (false);
	if (!store_elements(df, elements))
		return (false);
	if (!format_elements(df))
		return (print_err(INVALID_ELE), false);
	if (malloc_failed(df))
		return (print_err(MALLOC_FAIL), false);
	if (!validate_color_size(df))
		return (print_err(INVALID_COLOR_SIZE), false);
	return (true);
}

bool	is_valid_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

static bool	validate_map(t_description_file *df)
{
	int		j;

	int (i) = 0;
	while (i < df->map_height)
	{
		j = 0;
		while (j < df->map_width - 1)
		{
			if ((!is_valid_player_char(df->map[i][j]) && \
			df->map[i][j] != ROAD && df->map[i][j] != WALL) && \
			!(BONUS && df->map[i][j] == CLOSED_DOOR))
				return (print_err(INVALID_CHARCTOR), false);
			if (is_valid_player_char(df->map[i][j]))
			{
				if (df->have_player == true)
					return (print_err(TOO_MANY_PLAYER), false);
				df->have_player = true;
			}
			j++;
		}
		i++;
	}
	if (df->have_player == false)
		return (print_err(NO_PLAYER), false);
	return (true);
}

bool	parse(t_description_file *df, char **argv)
{
	char	**elements;

	if (!check_map_name(argv[1]))
		return (false);
	df->fd = open(argv[1], O_RDONLY);
	if (df->fd == OPEN_FAILED)
		return (print_err(FILE_OPEN_FAIL), false);
	elements = get_elements(df->fd, df);
	if (!elements)
		return (print_err(INVALID_FILE_FORMAT),
			close(df->fd), false);
	if (!check_and_store_elements(df, elements))
		return (reach_end_of_file(df, elements), false);
	if (!get_map(df, argv))
		return (clean_elements_array(elements), close(df->fd),
			clean_all(df), false);
	if (!validate_map(df))
		return (clean_all(df), clean_elements_array(elements),
			close(df->fd), false);
	clean_elements_array(elements);
	return (true);
}
