/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:50:43 by max               #+#    #+#             */
/*   Updated: 2024/11/04 16:05:18 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void    clean_elements_array(char **elements)
{
    int i;
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

void clean_partial_array(char **elements, int nb)
{
    int i;
    i = 0;
    while (i <= nb)
    {
        free(elements[i]);
        i++;
    }
    free(elements);
}

void clean_elements(t_description_file *desc_file)
{
    if (desc_file->elements.north_path)
    {
        free(desc_file->elements.north_path);
        desc_file->elements.north_path = NULL;
    }
    if (desc_file->elements.south_path)
    {
        free(desc_file->elements.south_path);
        desc_file->elements.south_path = NULL;
    }
    if (desc_file->elements.east_path)
    {
        free(desc_file->elements.east_path);
        desc_file->elements.east_path = NULL;
    }
    if (desc_file->elements.west_path)
    {
        free(desc_file->elements.west_path);
        desc_file->elements.west_path = NULL;
    }
}
void clean_map(t_description_file *desc_file)
{
    int i;
    i = 0;

    while (i < desc_file->map_height)
    {
        free(desc_file->map[i]);
        desc_file->map[i] = NULL;
        i++;
    }
    free(desc_file->map);
    desc_file->map = NULL;
}

void clean_all(t_description_file *desc_file)
{
    if (desc_file->map)
        clean_map(desc_file);
    clean_elements(desc_file);
}
