/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:30:10 by max               #+#    #+#             */
/*   Updated: 2024/11/08 16:40:35 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*printf("Player direction set to: (%.2f, %.2f), Plane: (%.2f, %.2f)\n", \
game->player.dir_x, game->player.dir_y, game->player.cam_vector_x, \
game->player.cam_vector_y);
*/
static void	init_player_view_angle(t_game *game, char direction)
{
	double	fov_rad;
	double	plane_len;

	fov_rad = degrees_to_radians(FOV_DEGREE);
	plane_len = tan(fov_rad / 2.0);
	if (direction == 'N')
		set_direction_north(game, plane_len);
	else if (direction == 'S')
		set_direction_south(game, plane_len);
	else if (direction == 'E')
		set_direction_east(game, plane_len);
	else if (direction == 'W')
		set_direction_west(game, plane_len);
	else
	{
		fprintf(stderr, "Error: Invalid player direction '%c'\n", direction);
		clean_and_destroy_all(game, game->df);
		exit(EXIT_FAILURE);
	}
}

bool	set_player_position(t_game *game, int x, int y, char direction)
{
	if (game->player.pos_x != -1 && game->player.pos_y != -1)
	{
		fprintf(stderr, "Error: Multiple player start positions found.\n");
		clean_and_destroy_all(game, game->df);
		exit(EXIT_FAILURE);
	}
	init_player_view_angle(game, direction);
	game->player.pos_x = x + 0.5;
	game->player.pos_y = y + 0.5;
	game->df->map[y][x] = '0';
	printf("Player initialized at position: (%.2f, %.2f)", \
		game->player.pos_x, game->player.pos_y);
	printf("with direction vector (%.2f, %.2f)\n", \
		game->player.dir_x, game->player.dir_y);
	return (true);
}

static void	no_player_error(t_game *game)
{
	fprintf(stderr, "Error: No player start position found in the map.\n");
	clean_and_destroy_all(game, game->df);
	exit(EXIT_FAILURE);
}

static void	init_player_position(t_game *game)
{
	int		x;
	int		y;
	bool	player_found;
	char	direction;

	player_found = false;
	game->player.pos_x = -1;
	game->player.pos_y = -1;
	y = 0;
	while (y < game->df->map_height)
	{
		x = 0;
		while (game->df->map[y][x] != '\0')
		{
			if (is_valid_player_char(game->df->map[y][x]))
			{
				direction = game->df->map[y][x];
				player_found = set_player_position(game, x, y, direction);
			}
			x++;
		}
		y++;
	}
	if (!player_found)
		no_player_error(game);
}

void	init_player(t_game *game)
{
	init_player_position(game);
	game->player.view_distance = \
		(float)game->screen_size_x / (2 * tan(FOV_DEGREE / 2));
}
