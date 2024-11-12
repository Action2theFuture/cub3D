/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:13:33 by junsan            #+#    #+#             */
/*   Updated: 2024/11/11 19:04:36 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

double	degrees_to_radians(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

double	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((double)(tv.tv_sec) + (double)(tv.tv_usec) / 1000000.0);
}
