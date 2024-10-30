/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:15:29 by max               #+#    #+#             */
/*   Updated: 2024/10/21 12:23:01 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int ft_strlen_atoi(const char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != 9 && s[i] != 32 && s[i] != ',' && s[i] != '\n' && s[i])
		i++;
	return (i);
}

int ft_atoi_cube(const char *str)
{
	int i;
	int res;
	i = 0;
	res = 0;
	
	if (ft_strlen_atoi(str) > 3)
		return -1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}
int skype_space(char *str)
{
    int i;
    i = 0;
    while (str[i] == 9 || str[i] == 32)
        i++;
    return i;
}
int skype_digit(char *str)
{
    int i;
    i = 0;
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    return i;
}
int skype_digit_and_space(char *str)
{
    int i;
    i = 0;
    i += skype_digit(&str[i]);
    i += skype_space(&str[i]);

    return i;
}