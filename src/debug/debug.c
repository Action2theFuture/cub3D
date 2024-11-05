/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:17:19 by max               #+#    #+#             */
/*   Updated: 2024/11/05 12:32:42 by junsan           ###   ########.fr       */
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
    printf("elements.north_path = %s\n", desc_file->elements.north_path);
    printf("elements.south_path = %s\n", desc_file->elements.south_path);
    printf("elements.east_path = %s\n", desc_file->elements.east_path);
    printf("elements.west_path = %s\n", desc_file->elements.west_path);
    printf("elements.floor.red = %d\n", desc_file->elements.floor.red);
    printf("elements.floor.green = %d\n", desc_file->elements.floor.green);
    printf("elements.floor.blue = %d\n", desc_file->elements.floor.blue);
    printf("elements.ceiling.red = %d\n", desc_file->elements.ceiling.red);
    printf("elements.ceiling.green = %d\n", desc_file->elements.ceiling.green);
    printf("elements.ceiling.blue = %d\n", desc_file->elements.ceiling.blue);
    printf("-----------------------------------------------------\n");
    printf("elements line = %d\n", desc_file->elements_lines);
    printf("map width = %d\n", desc_file->map_width);
    printf("map height= %d\n", desc_file->map_height);
}