/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:20:56 by junsan            #+#    #+#             */
/*   Updated: 2024/11/04 16:42:55 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	destroy_mlx_specific(t_data *data)
{
	if (data->mlx.windows)
		mlx_destroy_window(data->mlx.ptr, data->mlx.windows);
	data->mlx.windows = NULL;
}
