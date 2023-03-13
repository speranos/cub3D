/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 03:40:06 by aait-mas          #+#    #+#             */
/*   Updated: 2023/03/12 13:48:34 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_pixels(t_map *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == '1')
				print_rect(game, i * SCALE2, j * SCALE2, 0x00ffffff);
			else if (game->map[i][j] == '0' || game->map[i][j] == 'W'
				|| game->map[i][j] == 'N'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'S')
				print_rect(game, i * SCALE2, j * SCALE2, game->c_rgb);
			j++;
		}
		i++;
	}
}

void	ft_draw_player_mini_map(t_map *game)
{
	double	move;
	double	x;
	double	y;
	double	angle;
	double	max_ang;

	angle = game->play->angle - (30 * M_PI / 180);
	max_ang = game->play->angle + (30 * M_PI / 180);
	while (angle < max_ang)
	{
		move = 0;
		while (x < WINDOW_WIDTH && y < WINDOW_HEIGHT && move < 24)
		{
			x = game->play->pos_x_m_map + move * cos(angle);
			y = game->play->pos_y_m_map + move * sin(angle);
			if (check_wall(game, (int)x / SCALE2, (int)y / SCALE2))
				break ;
			my_mlx_pixel_put(game, (int)x, (int)y, 0x00FF0000);
			move += 4;
		}
		angle += 0.00097;
	}
	draw_circle_mini_map(game);
}

void	draw_circle_mini_map(t_map *game)
{
	double	radius;
	double	angle;
	int		i;

	i = 0;
	angle = 0;
	radius = 0;
	while (radius < 4)
	{
		angle = 0;
		while (angle < 360)
		{
			i = 0;
			while (i < radius)
			{
				my_mlx_pixel_put(game, game->play->pos_x_m_map + i * cos(angle),
					game->play->pos_y_m_map + i * sin(angle), 0x00FF0000);
				i++;
			}
			angle += 1;
		}
		radius++;
	}
}

void	update_player_mini_map(t_player *player, t_map *game)
{
	double	move;
	double	x;
	double	y;

	move = player->walk_direction * player->move_speed;
	if (player->ad == 1)
	{
		x = player->pos_x_m_map + cos(player->angle + M_PI / 2) * 0.1875 * move;
		y = player->pos_y_m_map + sin(player->angle + M_PI / 2) * 0.1875 * move;
	}
	else
	{
		x = player->pos_x_m_map + cos(player->angle) * 0.1875 * move;
		y = player->pos_y_m_map + sin(player->angle) * 0.1875 * move;
	}
	if (check_wall(game, x / SCALE2, player->pos_y_m_map / SCALE2) != 1)
	{
		player->pos_x_m_map = x;
	}
	if (check_wall(game, player->pos_x_m_map / SCALE2, y / SCALE2) != 1)
	{
		player->pos_y_m_map = y;
	}
	player->angle += player->turn_direction * player->rotation_speed;
}

void	struct_initialisation(t_map *game)
{
	image_init(game);
	get_pos(game);
	player_init(game);
	texture_init(game);
}
