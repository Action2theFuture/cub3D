/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 05:42:34 by max               #+#    #+#             */
/*   Updated: 2024/11/07 08:36:10 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	reach_end_of_file(t_description_file *desc_file, char **elements)
{
	char	*str;

	str = get_next_line(desc_file->fd);
	while (str)
	{
		free(str);
		str = get_next_line(desc_file->fd);
	}
	clean_elements_array(elements);
	close(desc_file->fd);
	clean_all(desc_file);
}
