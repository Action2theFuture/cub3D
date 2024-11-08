/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:13:49 by max               #+#    #+#             */
/*   Updated: 2024/11/08 17:37:27 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	print_controlor(void)
{
	char	*line;
	int		fd;

	printf(PRINT_CYAN "\n");
	fd = open(CONTROLOR_PATH, O_RDONLY);
	while ("cub3d")
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf(RESET "\n");
	printf(PRINT_CYAN "\tW" RESET ": move forward\t");
	printf(PRINT_CYAN "\tS" RESET ": move backward\n");
	printf(PRINT_CYAN "\tA" RESET ": move left\t");
	printf(PRINT_CYAN "\tD" RESET ": move right\n");
	printf(PRINT_CYAN "\t<" RESET ": rotate left\t");
	printf(PRINT_CYAN "\t>" RESET ": rotate right\n");
	printf("\n");
}

static int	game_loop(t_game *game)
{
	render_frame(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_description_file (desc_file) = {0};
	t_game (game) = {0};
	if (argc != 2)
		return (printf("Error\nInvalid number of arguments\n"), 1);
	if (!parse(&desc_file, argv))
		return (1);
	if (!init_game(&game, &desc_file))
		return (1);
	print_controlor();
	mlx_hook(game.mlx.windows, 2, 1L << 0, key_press, &game);
	mlx_loop_hook(game.mlx.ptr, game_loop, &game);
	mlx_loop(game.mlx.ptr);
	clean_and_destroy_all(&game, &desc_file);
	return (0);
}
