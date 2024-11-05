/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:17:19 by max               #+#    #+#             */
/*   Updated: 2024/10/26 14:36:00 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void print_map(t_description_file *desc_file)
{
    int i;
    i = 0;
   
    while (i < desc_file->map_height)
    {
        printf("%s\n", desc_file->map[i]);
        i++;
    }
}
void print_desc_file(t_description_file *desc_file)
{
    printf("%s", desc_file->elements.north_path);
    printf("%s", desc_file->elements.south_path);
    printf("%s", desc_file->elements.east_path);
    printf("%s", desc_file->elements.west_path);
    printf("%d\n", desc_file->elements.floor.red);
    printf("%d\n", desc_file->elements.floor.green);
    printf("%d\n", desc_file->elements.floor.blue);
    printf("%d\n", desc_file->elements.ceiling.red);
    printf("%d\n", desc_file->elements.ceiling.green);
    printf("%d\n", desc_file->elements.ceiling.blue);
    printf("-----------------------------------------------------\n");
    printf("elements line = %d\n", desc_file->elements_lines);
    printf("map width = %d\n", desc_file->map_width);
    printf("map height= %d\n", desc_file->map_height);
}
