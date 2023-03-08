/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 03:40:06 by aait-mas          #+#    #+#             */
/*   Updated: 2023/03/08 09:53:16 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_draw_player_mini_map(t_map *game)
{
	double	i;
	double	x;
	double	y;
	double	angle;
	double	max_ang;

	angle = game->play->angle - (30 * M_PI / 180);
	max_ang = game->play->angle + (30 * M_PI / 180);
	while (angle < max_ang)
	{
		i = 0;
		x = game->play->pos_x_m_map + i * cos(angle);
		y = game->play->pos_y_m_map + i * sin(angle);
		while (x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
		{
			x = game->play->pos_x_m_map + i * cos(angle);
			y = game->play->pos_y_m_map + i * sin(angle);
			if (check_wall(game, (int)x / SCALE2, (int)y / SCALE2))
				break ;
			my_mlx_pixel_put(game, (int)x, (int)y, 0x00FDEE00);
			i += 0.05;
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
			angle += 0.1f;
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
		x = player->pos_x_m_map + cos(player->angle + M_PI / 2) * 0.25 * move;
		y = player->pos_y_m_map + sin(player->angle + M_PI / 2) * 0.25 * move;
	}
	else
	{
		x = player->pos_x_m_map + cos(player->angle) * 0.25 * move;
		y = player->pos_y_m_map + sin(player->angle) * 0.25 * move;
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
	ft_img_init(game->imge);
	get_pos(game);
	player_init(game);
	texture_init(game);
	game->cast->num_rays = WINDOW_WIDTH;
}
