/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:20:25 by max               #+#    #+#             */
/*   Updated: 2024/11/06 17:41:58 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static char **get_elements(int fd, t_description_file *desc_file)
{
    int(count) = 0;
    int(i) = 0;
    char **elements = malloc(6 * sizeof(char *));
    int(j) = 0;
    if (!elements)
        return NULL;
    while (count < 6)
    {
        elements[i] = get_next_line(fd);
        desc_file->elements_lines++;
        if (!elements[i])
        {
            if (count < 6)
                return (clean_partial_array(elements, i), NULL);
        }
        j = skype_space(elements[i]);
        if (elements[i][j] == '\n')
        {
            free(elements[i]);
            continue;
        }
        i++;
        count++;
    }
    return elements;
}
static bool check_and_store_elements(t_description_file *desc_file, char **elements)
{
    if (!check_elements(elements))
        return false;
    if (!store_elements(desc_file, elements))
        return false;
    if (!format_elements(desc_file))
        return (printf("Error\nInvalid ID elements\n"),false);
    if (malloc_failed(desc_file))
        return (printf("Error\nMalloc failled\n"), false);
    if (!validate_color_size(desc_file))
        return (printf("Error\nInvalid color size\n"), false);
    return true;
}
bool is_valid_player_char(char c)
{
    return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}
static bool validate_map(t_description_file *desc_file)
{
    int(i) = 0;
    int j;
    bool have_player;
    have_player = false;
    while (i < desc_file->map_height)
    {
        j = 0;
        while (j < desc_file->map_width - 1)
        {
            if (!is_valid_player_char(desc_file->map[i][j]) && desc_file->map[i][j] != '0' && desc_file->map[i][j] != '1')
                return (printf("Error\nInvalid character in the map\n"), false);
            if (is_valid_player_char(desc_file->map[i][j]))
            {
                if (have_player == true)
                    return (printf("Error\nThe map contains more than one player\n"), false);
                have_player = true;
            }
            j++;
        }
        i++;
    }
    if (have_player == false)
        return (printf("Error\nNo player in the map\n"), false);
    return true;
}

bool parse(t_description_file *desc_file, char **argv)
{
    char *str;

    if (!check_map_name(argv[1]))
        return false;
    desc_file->fd = open(argv[1], O_RDONLY);
    if (desc_file->fd == OPEN_FAILED)
        return (printf("Error\nOpen file failed\n"), false);
    char **elements = get_elements(desc_file->fd, desc_file);
    if (!elements)
        return (printf("Error\nInvalid description file format\n"), close(desc_file->fd), false);
    if (!check_and_store_elements(desc_file, elements))
    {
        while ((str = get_next_line(desc_file->fd)))
            free(str);
        return (clean_elements_array(elements), close(desc_file->fd), clean_all(desc_file), false);
    }
    if (!get_map(desc_file, argv))
        return (clean_elements_array(elements), close(desc_file->fd), false);
    if (!validate_map(desc_file))
        return (clean_all(desc_file), clean_elements_array(elements), close(desc_file->fd), false);
    clean_elements_array(elements);
    return true;
}
