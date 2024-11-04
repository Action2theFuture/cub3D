/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_linux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:18:19 by junsan            #+#    #+#             */
/*   Updated: 2024/11/04 16:43:03 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	destroy_mlx_specific(t_data *data)
{
	if (data->mlx.ptr)
		mlx_destroy_display(data->mlx.ptr);
	free(data->mlx.ptr);
	data->mlx.ptr = NULL;
	if (data->mlx.windows)
		mlx_destroy_window(data->mlx.ptr, data->mlx.windows);
	data->mlx.windows = NULL;
}
