/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <aoueldma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 03:39:53 by aait-mas          #+#    #+#             */
/*   Updated: 2023/03/10 21:50:38 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	update_player(t_player *player, t_map *game)
{
	double	move;
	double	x;
	double	y;

	move = player->walk_direction * player->move_speed;
	if (player->ad == 1)
	{
		x = player->position_x + cos(player->angle + M_PI / 2) * move;
		y = player->position_y + sin(player->angle + M_PI / 2) * move;
	}
	else
	{
		x = player->position_x + cos(player->angle) * move;
		y = player->position_y + sin(player->angle) * move;
	}
	if (check_wall(game, x / SCALE, player->position_y / SCALE) != 1)
	{
		player->position_x = x;
	}
	if (check_wall(game, player->position_x / SCALE, y / SCALE) != 1)
	{
		player->position_y = y;
	}
	player->angle += player->turn_direction * player->rotation_speed;
}

void	ft_draw_player(t_map *game)
{
	double	i;
	int		j;
	double	x;
	double	y;
	double	*angle_ray;

	angle_ray = (double *)malloc(sizeof(double));
	*angle_ray = game->play->angle - (30 * M_PI / 180);
	j = 0;
	while (*angle_ray < game->play->angle + (30 * M_PI / 180))
	{
		i = 0;
		x = game->play->position_x + i * cos(*angle_ray);
		y = game->play->position_y + i * sin(*angle_ray);
		while (x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
		{
			x = game->play->position_x + i * cos(*angle_ray);
			y = game->play->position_y + i * sin(*angle_ray);
			if (check_wall(game, (int)x / SCALE, (int)y / SCALE))
				break ;
			i += 0.05;
		}
		get_distance(game, angle_ray, j, i);
		j++;
	}
}

void	get_distance(t_map *game, double *angle_ray, int j, double i)
{
	float	proj_dis;

	proj_dis = 0.7f * 32 / tan(0.523599);
	game->cast->x_wall = (game->play->position_x + i * cos(*angle_ray));
	game->cast->y_wall = (game->play->position_y + i * sin(*angle_ray));
	game->cast->dist = sqrt((game->cast->x_wall - game->play->position_x) * \
						(game->cast->x_wall - game->play->position_x) + \
						(game->cast->y_wall - game->play->position_y) * \
						(game->cast->y_wall - game->play->position_y)) + 10;
		game->cast->tab_x[j] = game->cast->x_wall;
		game->cast->tab_y[j] = game->cast->y_wall;
		game->cast->dist_wall[j] = game->cast->dist * \
									cos(game->play->angle - *angle_ray);
		game->cast->dist_wall2[j] = 720 * proj_dis / game->cast->dist_wall[j];
		*angle_ray += 0.00097;
}

void	floor_ceeling(t_map *cube)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT / 2)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(cube, j, i, cube->c_rgb);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < WINDOW_HEIGHT / 2)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(cube, j, i + WINDOW_HEIGHT / 2, cube->f_rgb);
			j++;
		}
		i++;
	}
}

int	ft_draw(t_map *game)
{
	ft_image(game);
	floor_ceeling(game);
	ft_draw_player(game);
	draw_walls(game);
	put_pixels(game);
	update_player(game->play, game);
	ft_draw_player_mini_map(game);
	update_player_mini_map(game->play, game);
	mlx_put_image_to_window(game->mlx, game->win, game->imge->img, 0, 0);
	mlx_destroy_image(game->mlx, game->imge->img);
	return (0);
}
