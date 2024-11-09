/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:30:14 by junsan            #+#    #+#             */
/*   Updated: 2024/11/09 12:30:26 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_minimap(t_game *game)
{
	game->minimap_pos_x = 200;
	game->minimap_pos_y = game->screen_size_y - \
		(game->df->map_height * MINIMAP_SCALE) - 200;
}
