/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:17:19 by max               #+#    #+#             */
/*   Updated: 2024/11/10 22:20:48 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	print_map(t_description_file *df)
{
	int	i;

	i = 0;
	while (i < df->map_height)
	{
		printf("%s\n", df->map[i]);
		i++;
	}
}

static void	print_desc_file(t_description_file *df)
{
	printf("elements.north_path = %s\n", df->elements.north_path);
	printf("elements.south_path = %s\n", df->elements.south_path);
	printf("elements.east_path = %s\n", df->elements.east_path);
	printf("elements.west_path = %s\n", df->elements.west_path);
	printf("elements.floor.red = %d\n", df->elements.floor.red);
	printf("elements.floor.green = %d\n", df->elements.floor.green);
	printf("elements.floor.blue = %d\n", df->elements.floor.blue);
	printf("elements.ceiling.red = %d\n", df->elements.ceiling.red);
	printf("elements.ceiling.green = %d\n", df->elements.ceiling.green);
	printf("elements.ceiling.blue = %d\n", df->elements.ceiling.blue);
	printf("-----------------------------------------------------\n");
	printf("elements line = %d\n", df->elements_lines);
	printf("map width = %d\n", df->map_width);
	printf("map height= %d\n", df->map_height);
}

void	debug_map_and_df(t_description_file *df)
{
	print_map(df);
	print_desc_file(df);
}

void	print_err(const char *msg)
{
	printf(PRINT_RED"\nERROR : %s\n", msg);
	printf(RESET "\n");
}
