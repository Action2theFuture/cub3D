/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:25:41 by max               #+#    #+#             */
/*   Updated: 2024/11/07 05:29:46 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	store_path(t_description_file *desc_file, char *element, int type)
{
	int	i;

	i = 0;
	if (element == NULL)
		return ;
	while (element[i] == 9 || element[i] == 32)
		i++;
	if (type == NO && desc_file->elements.north_path == NULL)
		desc_file->elements.north_path = ft_strdup(&element[i]);
	if (type == SO && desc_file->elements.south_path == NULL)
		desc_file->elements.south_path = ft_strdup(&element[i]);
	if (type == WE && desc_file->elements.west_path == NULL)
		desc_file->elements.west_path = ft_strdup(&element[i]);
	if (type == EA && desc_file->elements.east_path == NULL)
		desc_file->elements.east_path = ft_strdup(&element[i]);
}

static bool	store_floor_color(t_description_file *desc_file, char *element)
{
	int	i;

	i = 0;
	i += skype_space(&element[i]);
	if (element[i] < '0' || element[i] > '9')
		return (false);
	desc_file->elements.floor.red = ft_atoi_cube(&element[i]);
	i += skype_digit_and_space(&element[i]);
	if (element[i++] != ',')
		return (false);
	i += skype_space(&element[i]);
	if (element[i] < '0' || element[i] > '9')
		return (false);
	desc_file->elements.floor.green = ft_atoi_cube(&element[i]);
	i += skype_digit_and_space(&element[i]);
	if (element[i++] != ',')
		return (false);
	i += skype_space(&element[i]);
	if (element[i] < '0' || element[i] > '9')
		return (false);
	desc_file->elements.floor.blue = ft_atoi_cube(&element[i]);
	i += skype_digit_and_space(&element[i]);
	if (element[i] != '\n' && element[i] != '\0')
		return (false);
	return (true);
}

static bool	store_ceiling_color(t_description_file *desc_file, char *element)
{
	int	i;

	i = 0;
	i += skype_space(&element[i]);
	if (element[i] < '0' || element[i] > '9')
		return (false);
	desc_file->elements.ceiling.red = ft_atoi_cube(&element[i]);
	i += skype_digit_and_space(&element[i]);
	if (element[i++] != ',')
		return (false);
	i += skype_space(&element[i]);
	if (element[i] < '0' || element[i] > '9')
		return (false);
	desc_file->elements.ceiling.green = ft_atoi_cube(&element[i]);
	i += skype_digit_and_space(&element[i]);
	if (element[i++] != ',')
		return (false);
	i += skype_space(&element[i]);
	if (element[i] < '0' || element[i] > '9')
		return (false);
	desc_file->elements.ceiling.blue = ft_atoi_cube(&element[i]);
	i += skype_digit_and_space(&element[i]);
	if (element[i] != '\n' && element[i] != '\0')
		return (false);
	return (true);
}

static bool	store_color(t_description_file *desc_file, char *element, int type)
{
	if (type == F)
	{
		if (!store_floor_color(desc_file, element))
			return (printf("Error\nWrong floor input\n"), false);
	}
	if (type == C)
	{
		if (!store_ceiling_color(desc_file, element))
			return (printf("Error\nWrong ceiling input\n"), false);
	}
	return (true);
}

bool	store_elements(t_description_file *desc_file, char **elements)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < 6)
	{
		tmp = skype_space_ptr(&elements[i][0]);
		if (!(ft_strncmp(tmp, "NO", 2)))
			store_path(desc_file, tmp + 2, NO);
		else if (!(ft_strncmp(tmp, "SO", 2)))
			store_path(desc_file, tmp + 2, SO);
		else if (!(ft_strncmp(tmp, "WE", 2)))
			store_path(desc_file, tmp + 2, WE);
		else if (!(ft_strncmp(tmp, "EA", 2)))
			store_path(desc_file, tmp + 2, EA);
		else if (!(ft_strncmp(tmp, "F", 1)) && !store_color(desc_file, tmp + 1,
				F))
			return (false);
		else if (!(ft_strncmp(tmp, "C", 1)) && !store_color(desc_file, tmp + 1,
				C))
			return (false);
		i++;
	}
	return (true);
}
