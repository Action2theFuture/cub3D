/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:13:49 by max               #+#    #+#             */
/*   Updated: 2024/10/31 20:05:11 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int main(int argc, char **argv)
{
    t_description_file (desc_file) = {0};
    t_data (data) = {0};

    if (argc != 2)
        return (printf("Error\nInvalid number of arguments\n"), 1);
    if (!parse(&desc_file, argv))
        return 1;
    if (!init_mlx_and_data(&data,&desc_file))
        return 1;
    clean_and_destroy_all(&data,&desc_file);
    return 0;
}
