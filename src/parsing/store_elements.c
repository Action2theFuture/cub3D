/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:25:41 by max               #+#    #+#             */
/*   Updated: 2024/11/10 22:20:48 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	store_path(t_description_file *df, char *element, int type)
{
	int	i;

	i = 0;
	if (element == NULL)
		return ;
	while (element[i] == 9 || element[i] == 32)
		i++;
	if (type == NO && df->elements.north_path == NULL)
		df->elements.north_path = ft_strdup(&element[i]);
	if (type == SO && df->elements.south_path == NULL)
		df->elements.south_path = ft_strdup(&element[i]);
	if (type == WE && df->elements.west_path == NULL)
		df->elements.west_path = ft_strdup(&element[i]);
	if (type == EA && df->elements.east_path == NULL)
		df->elements.east_path = ft_strdup(&element[i]);
	if (type == D && df->elements.door_path == NULL)
		df->elements.door_path = ft_strdup(&element[i]);
}

static bool	store_floor_color(t_description_file *df, char *element)
{
	int	i;

	i = 0;
	i += skype_space(&element[i]);
	if (element[i] < '0' || element[i] > '9')
		return (false);
	df->elements.floor.red = ft_atoi_cube(&element[i]);
	i += skype_digit_and_space(&element[i]);
	if (element[i++] != ',')
		return (false);
	i += skype_space(&element[i]);
	if (element[i] < '0' || element[i] > '9')
		return (false);
	df->elements.floor.green = ft_atoi_cube(&element[i]);
	i += skype_digit_and_space(&element[i]);
	if (element[i++] != ',')
		return (false);
	i += skype_space(&element[i]);
	if (element[i] < '0' || element[i] > '9')
		return (false);
	df->elements.floor.blue = ft_atoi_cube(&element[i]);
	i += skype_digit_and_space(&element[i]);
	if (element[i] != '\n' && element[i] != '\0')
		return (false);
	return (true);
}

static bool	store_ceiling_color(t_description_file *df, char *element)
{
	int	i;

	i = 0;
	i += skype_space(&element[i]);
	if (element[i] < '0' || element[i] > '9')
		return (false);
	df->elements.ceiling.red = ft_atoi_cube(&element[i]);
	i += skype_digit_and_space(&element[i]);
	if (element[i++] != ',')
		return (false);
	i += skype_space(&element[i]);
	if (element[i] < '0' || element[i] > '9')
		return (false);
	df->elements.ceiling.green = ft_atoi_cube(&element[i]);
	i += skype_digit_and_space(&element[i]);
	if (element[i++] != ',')
		return (false);
	i += skype_space(&element[i]);
	if (element[i] < '0' || element[i] > '9')
		return (false);
	df->elements.ceiling.blue = ft_atoi_cube(&element[i]);
	i += skype_digit_and_space(&element[i]);
	if (element[i] != '\n' && element[i] != '\0')
		return (false);
	return (true);
}

static bool	store_color(t_description_file *df, char *element, int type)
{
	if (type == F)
	{
		if (!store_floor_color(df, element))
			return (print_err(INVALID_INPUT_FLOOR), false);
	}
	if (type == C)
	{
		if (!store_ceiling_color(df, element))
			return (print_err(INVALID_INPUT_CEILING), false);
	}
	return (true);
}

bool	store_elements(t_description_file *df, char **elements)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < 6)
	{
		tmp = skype_space_ptr(&elements[i][0]);
		if (!(ft_strncmp(tmp, "NO", 2)))
			store_path(df, tmp + 2, NO);
		else if (!(ft_strncmp(tmp, "SO", 2)))
			store_path(df, tmp + 2, SO);
		else if (!(ft_strncmp(tmp, "WE", 2)))
			store_path(df, tmp + 2, WE);
		else if (!(ft_strncmp(tmp, "EA", 2)))
			store_path(df, tmp + 2, EA);
		else if (!(ft_strncmp(tmp, "F", 1)) && !store_color(df, tmp + 1,
				F))
			return (false);
		else if (!(ft_strncmp(tmp, "C", 1)) && !store_color(df, tmp + 1,
				C))
			return (false);
		i++;
	}
	return (true);
}
