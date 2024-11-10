/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 05:42:34 by max               #+#    #+#             */
/*   Updated: 2024/11/10 22:20:48 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	reach_end_of_file(t_description_file *df, char **elements)
{
	char	*str;

	str = get_next_line(df->fd);
	while (str)
	{
		free(str);
		str = get_next_line(df->fd);
	}
	clean_elements_array(elements);
	close(df->fd);
	clean_all(df);
}
