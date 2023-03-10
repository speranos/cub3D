/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 03:40:01 by aait-mas          #+#    #+#             */
/*   Updated: 2023/03/11 00:05:41 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_rect(t_map *game, int x, int y, unsigned int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCALE2)
	{
		j = 0;
		while (j < SCALE2)
		{
			my_mlx_pixel_put(game, y + j, x + i, color);
			j++;
		}
		i++;
	}
}

void	draw_circle(t_map *game)
{
	double	radius;
	double	angle;
	int		i;

	i = 0;
	angle = 0;
	radius = 0;
	while (radius < 6)
	{
		angle = 0;
		while (angle < 360)
		{
			i = 0;
			while (i < radius)
			{
				my_mlx_pixel_put(game, game->play->position_x + i * cos(angle), \
				game->play->position_y + i * sin(angle), 0x00ff0000);
				i++;
			}
			angle += 0.1f;
		}
		radius++;
	}
}

void	player_init(t_map *game)
{
	if (game->player == 'N')
		game->play->angle = 360 * M_PI / 180;
	else if (game->player == 'S')
		game->play->angle = 180 * M_PI / 180;
	else if (game->player == 'W')
		game->play->angle = 270 * M_PI / 180;
	else if (game->player == 'E')
		game->play->angle = 90 * M_PI / 180;
	game->play->ad = 0;
	game->play->move_speed = 4;
	game->play->turn_direction = 0;
	game->play->walk_direction = 0;
	game->play->rotation_speed = (M_PI / 180) * 4;
	game->play->position_x = game->play->position_x_map * SCALE + 16;
	game->play->position_y = game->play->position_y_map * SCALE + 16;
	game->play->pos_x_m_map = game->play->position_x_map * SCALE2 + 4;
	game->play->pos_y_m_map = game->play->position_y_map * SCALE2 + 4;
}
