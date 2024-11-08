/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsan <junsan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 04:18:51 by max               #+#    #+#             */
/*   Updated: 2024/11/08 14:44:20 by junsan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int get_pixel_color(t_texture texture, int x, int y)
{
    char *pixel;

    // 각 픽셀의 주소 계산
    pixel = texture.addr + (y * texture.line_length + x * (texture.bits_per_pixel / 8));
    return *(unsigned int*)pixel;
}
/*
static void draw_wall_column(t_game *game, int x, int draw_pos[2], int side, double perp_wall_dist)
{
  int y;
	int tex_x;
	int tex_y;
	double step;
	double tex_pos;
	double wall_x;
	int color;

	// 벽의 높이 계산
	int line_height = (int)(game->screen_size_y / perp_wall_dist);

	// 벽의 시작과 끝 Y 좌표 계산
	draw_pos[0] = -line_height / 2 + game->screen_size_y / 2;
	if (draw_pos[0] < 0)
		draw_pos[0] = 0;
	draw_pos[1] = line_height / 2 + game->screen_size_y / 2;
	if (draw_pos[1] >= game->screen_size_y)
		draw_pos[1] = game->screen_size_y - 1;

	// 텍스처의 스텝 설정
	step = 1.0 * (side == NORTH || side == SOUTH ? game->mlx.north_texture.height : game->mlx.east_texture.height) / line_height;

	// 텍스처 Y 좌표의 초기 위치 계산
	tex_pos = (draw_pos[0] - game->screen_size_y / 2 + line_height / 2) * step;

	// 벽에 닿은 정확한 위치 계산
	if (side == NORTH || side == SOUTH)
		wall_x = game->player.pos_x + perp_wall_dist * game->ray.ray_dir_x;
	else
		wall_x = game->player.pos_y + perp_wall_dist * game->ray.ray_dir_y;
	wall_x -= floor(wall_x); // 소수 부분만 추출

	// 텍스처 X 좌표 계산
	if (side == NORTH || side == SOUTH)
		tex_x = (int)(wall_x * (double)game->mlx.north_texture.width);
	else
		tex_x = (int)(wall_x * (double)game->mlx.east_texture.width);

	// 텍스처 X 좌표 반전 (서쪽(WEST) 또는 북쪽(NORTH) 벽인 경우)
	if ((side == SOUTH && game->ray.ray_dir_x > 0) ||
		(side == NORTH && game->ray.ray_dir_x < 0) ||
		(side == EAST && game->ray.ray_dir_y < 0) ||
		(side == WEST && game->ray.ray_dir_y > 0))
		tex_x = (side == NORTH || side == SOUTH ? game->mlx.north_texture.width : game->mlx.east_texture.width) - tex_x - 1;

	// 텍스처 X 좌표가 텍스처 너비를 초과하지 않도록 제한
	if (tex_x < 0)
		tex_x = 0;
	if (side == NORTH || side == SOUTH)
	{
		if (tex_x >= game->mlx.north_texture.width)
			tex_x = game->mlx.north_texture.width - 1;
	}
	else
	{
		if (tex_x >= game->mlx.east_texture.width)
			tex_x = game->mlx.east_texture.width - 1;
	}

	// 디버그 로그 출력
	printf("Drawing wall column at x=%d: side=%s, wall_x=%.2f, tex_x=%d\n", x,
		   (side == NORTH) ? "NORTH" :
		   (side == SOUTH) ? "SOUTH" :
		   (side == EAST)  ? "EAST"  :
		   (side == WEST)  ? "WEST"  : "UNKNOWN",
		   wall_x, tex_x);

	y = draw_pos[0];
	while (y < draw_pos[1])
	{
		// 텍스처 Y 좌표 계산
		tex_y = (int)tex_pos % (side == NORTH || side == SOUTH ? game->mlx.north_texture.height : game->mlx.east_texture.height);

		tex_pos += step;

		// 해당 텍스처에서 색상 가져오기
		if (side == NORTH)
			color = get_pixel_color(game->mlx.north_texture, tex_x, tex_y);
		else if (side == SOUTH)
			color = get_pixel_color(game->mlx.south_texture, tex_x, tex_y);
		else if (side == EAST)
			color = get_pixel_color(game->mlx.east_texture, tex_x, tex_y);
		else if (side == WEST)
			color = get_pixel_color(game->mlx.west_texture, tex_x, tex_y);
		else
			color = 0x00FF00; // 기본 색상 (초록색)

		// 픽셀 그리기
		put_pixel(game, x, y, color);
		y++;
	} 
}


void	perform_raycasting(t_game *game)
{
	double	ray_dir[2];
	double	perp_wall_dist;
	int		x;
	int		draw_pos[2];
	int		side;

	x = 0;
	while (x < game->screen_size_x)
	{
		calculate_ray_direction(game, x, &ray_dir[0], &ray_dir[1]);
		game->ray.ray_dir_x = ray_dir[0];
		game->ray.ray_dir_y = ray_dir[1];
		init_dda(game, ray_dir[0], ray_dir[1], &game->ray);
		perform_dda(game, &game->ray);
        if (game->ray.hit)
        {
		    perp_wall_dist = calculate_perp_wall_dist(game, &game->ray);
		    calculate_wall_dimensions(game, \
						    perp_wall_dist, &draw_pos[0], &draw_pos[1]);
		    side = game->ray.side;
		    draw_wall_column(game, x, draw_pos, side, perp_wall_dist);
        }
        x++;
	}
}
*/
static int calculate_line_height(double screen_size_y, double perp_wall_dist)
{
    return (int)(screen_size_y / perp_wall_dist);
}

// 그릴 Y 좌표(draw_start, draw_end) 계산
static void calculate_draw_pos(int line_height, int screen_size_y, int draw_pos[2])
{
    draw_pos[0] = -line_height / 2 + screen_size_y / 2;
    if (draw_pos[0] < 0)
        draw_pos[0] = 0;
    draw_pos[1] = line_height / 2 + screen_size_y / 2;
    if (draw_pos[1] >= screen_size_y)
        draw_pos[1] = screen_size_y - 1;
}

// 벽 충돌 지점(wall_x)과 텍스처 X 좌표(tex_x) 계산
static void calculate_wall_and_tex_x(int side, t_game *game, double perp_wall_dist, double *wall_x, int *tex_x)
{
    if (side == NORTH || side == SOUTH)
        *wall_x = game->player.pos_x + perp_wall_dist * game->ray.ray_dir_x;
    else
        *wall_x = game->player.pos_y + perp_wall_dist * game->ray.ray_dir_y;
    *wall_x -= floor(*wall_x); // 소수 부분만 추출

    if (side == NORTH || side == SOUTH)
        *tex_x = (int)(*wall_x * (double)game->mlx.north_texture.width);
    else
        *tex_x = (int)(*wall_x * (double)game->mlx.east_texture.width);
}

// 텍스처 X 좌표 클램핑 및 반전
static int clamp_and_flip_tex_x(int side, int tex_x, t_game *game)
{
    if ((side == SOUTH && game->ray.ray_dir_x > 0) ||
        (side == NORTH && game->ray.ray_dir_x < 0) ||
        (side == EAST && game->ray.ray_dir_y < 0) ||
        (side == WEST && game->ray.ray_dir_y > 0))
    {
        tex_x = ((side == NORTH || side == SOUTH) ? game->mlx.north_texture.width : game->mlx.east_texture.width) - tex_x - 1;
    }

    if (tex_x < 0)
        tex_x = 0;
    
    if (side == NORTH || side == SOUTH)
    {
        if (tex_x >= game->mlx.north_texture.width)
            tex_x = game->mlx.north_texture.width - 1;
    }
    else
    {
        if (tex_x >= game->mlx.east_texture.width)
            tex_x = game->mlx.east_texture.width - 1;
    }

    return tex_x;
}

// 각 픽셀에 대한 텍스처 색상 추출 및 그리기
static void draw_pixels(t_game *game, int x, int draw_start, int draw_end, int side, int tex_x, double tex_pos, double step)
{
    int y;
    int tex_y;
    int color;

    y = draw_start;
    while (y < draw_end)
    {
        tex_y = (int)tex_pos % ((side == NORTH || side == SOUTH) ? game->mlx.north_texture.height : game->mlx.east_texture.height);
        tex_pos += step;

        if (side == NORTH)
            color = get_pixel_color(game->mlx.north_texture, tex_x, tex_y);
        else if (side == SOUTH)
            color = get_pixel_color(game->mlx.south_texture, tex_x, tex_y);
        else if (side == EAST)
            color = get_pixel_color(game->mlx.east_texture, tex_x, tex_y);
        else if (side == WEST)
            color = get_pixel_color(game->mlx.west_texture, tex_x, tex_y);
        else
            color = 0x00FF00; // 기본 색상 (초록색)

        put_pixel(game, x, y, color);
        y++;
    }
}

// 벽 컬럼을 그리는 함수 (텍스처 매핑 포함)
static void draw_wall_column(t_game *game, int x, int draw_pos[2], int side, double perp_wall_dist)
{
    int line_height = calculate_line_height(game->screen_size_y, perp_wall_dist);
    calculate_draw_pos(line_height, game->screen_size_y, draw_pos);

    double step = 1.0 * ((side == NORTH || side == SOUTH) ? game->mlx.north_texture.height : game->mlx.east_texture.height) / line_height;
    double tex_pos = (draw_pos[0] - game->screen_size_y / 2 + line_height / 2) * step;

    double wall_x;
    int tex_x;
    calculate_wall_and_tex_x(side, game, perp_wall_dist, &wall_x, &tex_x);
    tex_x = clamp_and_flip_tex_x(side, tex_x, game);

    // 디버그 로그 출력
    printf("Drawing wall column at x=%d: side=%s, wall_x=%.2f, tex_x=%d\n", x,
           (side == NORTH) ? "NORTH" :
           (side == SOUTH) ? "SOUTH" :
           (side == EAST)  ? "EAST"  :
           (side == WEST)  ? "WEST"  : "UNKNOWN",
           wall_x, tex_x);

    draw_pixels(game, x, draw_pos[0], draw_pos[1], side, tex_x, tex_pos, step);
}

// 단일 레이 캐스팅 처리
static void process_single_ray(t_game *game, int x)
{
    double ray_dir[2];
    int draw_pos[2];
    int side;
    double perp_wall_dist;

    calculate_ray_direction(game, x, &ray_dir[0], &ray_dir[1]);
    game->ray.ray_dir_x = ray_dir[0];
    game->ray.ray_dir_y = ray_dir[1];

    init_dda(game, ray_dir[0], ray_dir[1], &game->ray);
    perform_dda(game, &game->ray);

    if (game->ray.hit)
    {
        perp_wall_dist = calculate_perp_wall_dist(game, &game->ray);
        calculate_wall_dimensions(game, perp_wall_dist, &draw_pos[0], &draw_pos[1]);
        side = game->ray.side;
        draw_wall_column(game, x, draw_pos, side, perp_wall_dist);
    }
}

// 레이캐스팅 수행 함수
void perform_raycasting(t_game *game)
{
    for (int x = 0; x < game->screen_size_x; x++)
    {
        process_single_ray(game, x);
    }

    // 렌더링 후 이미지 출력
    mlx_put_image_to_window(game->mlx.ptr, game->mlx.windows, game->img.img, 0, 0);
}