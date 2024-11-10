/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:28:45 by max               #+#    #+#             */
/*   Updated: 2024/11/10 22:20:48 by junsan           ###   ########.fr       */
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

bool	malloc_failed(t_description_file *df)
{
	return (!(df->elements.north_path && df->elements.south_path
			&& df->elements.east_path && df->elements.west_path));
}

bool	validate_color_size(t_description_file *df)
{
	return (is_valid_number(df->elements.floor.red)
		&& is_valid_number(df->elements.floor.green)
		&& is_valid_number(df->elements.floor.blue)
		&& is_valid_number(df->elements.ceiling.red)
		&& is_valid_number(df->elements.ceiling.green)
		&& is_valid_number(df->elements.ceiling.blue));
}
