/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:28:45 by max               #+#    #+#             */
/*   Updated: 2024/11/07 05:30:36 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static bool	is_valid_number(int num)
{
	return (num >= 0 && num <= 255);
}

int	ft_strlen_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*skype_space_ptr(char *str)
{
	while ((*str == 9 || *str == 32) && *str)
		str++;
	return (str);
}

bool	malloc_failed(t_description_file *desc_file)
{
	return (!(desc_file->elements.north_path && desc_file->elements.south_path
			&& desc_file->elements.east_path && desc_file->elements.west_path));
}

bool	validate_color_size(t_description_file *desc_file)
{
	return (is_valid_number(desc_file->elements.floor.red)
		&& is_valid_number(desc_file->elements.floor.green)
		&& is_valid_number(desc_file->elements.floor.blue)
		&& is_valid_number(desc_file->elements.ceiling.red)
		&& is_valid_number(desc_file->elements.ceiling.green)
		&& is_valid_number(desc_file->elements.ceiling.blue));
}
