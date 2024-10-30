/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:13:49 by max               #+#    #+#             */
/*   Updated: 2024/10/26 14:36:00 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int main(int argc, char **argv)
{
    (void)argc;
    t_description_file(desc_file) = {0};

    if (argc != 2)
    {
        printf("Error\nInvalid number of arguments\n");
        return 1;
    }

    if (!parse(&desc_file, argv))
        return 1;
    print_map(&desc_file);
    clean_and_destroy_all(&desc_file);
    return 0;
}