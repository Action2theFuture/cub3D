/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:27:21 by max               #+#    #+#             */
/*   Updated: 2024/10/31 14:32:00 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void format_elements(t_description_file *df)
{
    df->elements.north_path[ft_strlen(df->elements.north_path) - 1] = '\0';
    df->elements.south_path[ft_strlen(df->elements.south_path) - 1] = '\0';
    df->elements.west_path[ft_strlen(df->elements.west_path) - 1] = '\0';
    df->elements.east_path[ft_strlen(df->elements.east_path) - 1] = '\0';
}