/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:30:10 by max               #+#    #+#             */
/*   Updated: 2024/11/06 17:13:16 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	init_player_view_angle(t_game *game, char direction)
{
	double	fov_rad;
	double	plane_len;


	fov_rad = degrees_to_radians(FOV_DEGREE);
	plane_len = tan(fov_rad / 2.0);
	if (direction == 'N')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = -1.0;
		game->player.cam_vector_x = plane_len;
		game->player.cam_vector_y = 0.0;
	}
	else if (direction == 'S')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = 1.0;
		game->player.cam_vector_x = -plane_len;
		game->player.cam_vector_y = 0.0;
	}
	else if (direction == 'E')
	{
		game->player.dir_x = 1.0;
		game->player.dir_y = 0.0;
		game->player.cam_vector_x = 0.0;
		game->player.cam_vector_y = plane_len;
	}
	else if (direction == 'W')
	{
		game->player.dir_x = -1.0;
		game->player.dir_y = 0.0;
		game->player.cam_vector_x = 0.0;
		game->player.cam_vector_y = -plane_len;
	}
	else
	{
		fprintf(stderr, "Error: Invalid player direction '%c'\n", direction);
		clean_and_destroy_all(game, game->df);
		exit(EXIT_FAILURE);
	}
	printf("Player direction set to: (%.2f, %.2f), Plane: (%.2f, %.2f)\n", \
	game->player.dir_x, game->player.dir_y, game->player.cam_vector_x, \
	game->player.cam_vector_y);
}

static void	init_player_position(t_game *game)
{
	int		x;
	int		y;
	bool	player_found;
	char	direction;

	player_found = false;
	y = 0;
	while (y < game->df->map_height)
	{
		x = 0;
		while (game->df->map[y][x] != '\0')
		{
			if (is_valid_player_char(game->df->map[y][x]))
			{
				if (player_found)
				{
					fprintf(stderr, "Error: Multiple player start positions found.\n");
					clean_and_destroy_all(game, game->df);
					exit(EXIT_FAILURE);
				}
				direction = game->df->map[y][x];
				init_player_view_angle(game, direction);
				game->player.pos_x = x + 0.5;
				game->player.pos_y = y + 0.5;
				player_found = true;
				game->df->map[y][x] = '0';
				printf("Player initialized at position: (%.2f, %.2f) with direction vector (%.2f, %.2f)\n",
				game->player.pos_x, game->player.pos_y, game->player.dir_x, game->player.dir_y);
			}
			x++;
		}
		y++;
	}
	if (!player_found)
	{
		fprintf(stderr, "Error: No player start position found in the map.\n");
		clean_and_destroy_all(game, game->df);
		exit(EXIT_FAILURE);
	}
	return ;
}

void	init_data(t_game *game)
{
	init_player_position(game);
	game->player.view_distance = \
		(float)game->screen_size_x / (2 * tan(FOV_DEGREE / 2));
}
