/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:50:43 by max               #+#    #+#             */
/*   Updated: 2024/11/10 22:42:04 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	clean_elements_array(char **elements)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		free(elements[i]);
		elements[i] = NULL;
		i++;
	}
	free(elements);
	elements = NULL;
}

void	clean_partial_array(char **elements, int nb)
{
	int	i;

	i = 0;
	while (i <= nb)
	{
		free(elements[i]);
		i++;
	}
	free(elements);
}

void	clean_elements(t_description_file *df)
{
	if (df->elements.north_path)
	{
		free(df->elements.north_path);
		df->elements.north_path = NULL;
	}
	if (df->elements.south_path)
	{
		free(df->elements.south_path);
		df->elements.south_path = NULL;
	}
	if (df->elements.east_path)
	{
		free(df->elements.east_path);
		df->elements.east_path = NULL;
	}
	if (df->elements.west_path)
	{
		free(df->elements.west_path);
		df->elements.west_path = NULL;
	}
}

void	clean_map(t_description_file *df)
{
	int	i;

	i = 0;
	while (i < df->map_height)
	{
		free(df->map[i]);
		df->map[i] = NULL;
		i++;
	}
	free(df->map);
	df->map = NULL;
}

void	clean_all(t_description_file *df)
{
	if (df->map)
		clean_map(df);
	clean_elements(df);
}
