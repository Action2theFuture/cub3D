/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:07:55 by max               #+#    #+#             */
/*   Updated: 2024/10/25 13:26:04 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static bool check_id_element(char *element)
{
    return (ft_strncmp(element, "NO", 2) == 0 ||
            ft_strncmp(element, "SO", 2) == 0 ||
            ft_strncmp(element, "WE", 2) == 0 ||
            ft_strncmp(element, "EA", 2) == 0 ||
            ft_strncmp(element, "F", 1) == 0 ||
            ft_strncmp(element, "C", 1) == 0);
}

static bool check_valide_char(char c)
{
    return (c == 9 || c == 32 || c == ',' || c == '\n' || (c >= '0' && c <= '9'));
}

bool check_map_name(char *argument)
{
    int i;

    i = 0;
    while (argument[i])
        i++;
    if (ft_strncmp(".cub", &argument[i - 4], 4))
    {
        printf("Error\nInvalid map name\n");
        return false;
    }
    return true;
}

bool check_elements(char **elements)
{
    int i;
    i = 0;
    int j;
    j = 0;
    while (i < 6)
    {
        if (elements[i] == NULL)
            return (printf("Error\nMalloc failled\n"), false);
        j = skype_space(elements[i]);
        if (!check_id_element(&elements[i][j]))
            return (printf("Error\nWrong ID element\n"), false);
        if ((i == 4 || i == 5) && !check_floor_and_ceiling_args(&elements[i][j + 1]))
            return (printf("Error\nWrong ceiling/floor format\n"), false);
        i++;
    }
    return true;
}

bool check_floor_and_ceiling_args(char *str)
{
    int i;
    i = 0;

    while (str[i])
    {
        if (!check_valide_char(str[i]))
            return false;
        i++;
    }
    return true;
}