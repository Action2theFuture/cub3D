/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:27:21 by max               #+#    #+#             */
/*   Updated: 2024/11/09 16:09:31 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	format_elements(t_description_file *df)
{
	if (!(df->elements.north_path && df->elements.south_path
			&& df->elements.east_path && df->elements.west_path))
		return (false);
	df->elements.north_path[ft_strlen(df->elements.north_path) - 1] = '\0';
	df->elements.south_path[ft_strlen(df->elements.south_path) - 1] = '\0';
	df->elements.west_path[ft_strlen(df->elements.west_path) - 1] = '\0';
	df->elements.east_path[ft_strlen(df->elements.east_path) - 1] = '\0';
	return (true);
}
