/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <aoueldma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:40:29 by aoueldma          #+#    #+#             */
/*   Updated: 2023/03/16 00:57:43 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	set_tex_y(t_map *game, int mid, int i)
{
	int	tex_y;

	tex_y = (int)(((float)(game->toppixel - mid + game->cast->dist_wall2[i] \
	* 0.7f) / (float)(2.0f * game->cast->dist_wall2[i] * 0.7f)) * (float)32);
	return (tex_y);
}

int	get_tex_color(t_map *game, int d, int index)
{
	int	color;

	color = game->create_pixel[d].image_data[index];
	return (color);
}

int	set_offsetx(t_map *game, int i, int d)
{
	if ((int)game->cast->tab_x[i] % 32 >= 0 && (int)game->cast->tab_x[i] % 32 <= \
	31 && (int)game->cast->tab_y[i] % 32 == 0)
	{
		game->offsetx = (int)game->cast->tab_x[i] % 32;
		d = 2;
	}
	else if ((int)game->cast->tab_y[i] % 32 >= 0 && (int)game->cast->tab_y[i] \
	% 32 <= 31 && (int)game->cast->tab_x[i] % 32 == 31)
	{
		game->offsetx = (int)game->cast->tab_y[i] % 32;
		d = 3;
	}
	else if ((int)game->cast->tab_x[i] % 32 >= 0 && (int)game->cast->tab_x[i] \
	% 32 <= 31 && (int)game->cast->tab_y[i] % 32 == 31)
	{
		game->offsetx = (int)game->cast->tab_x[i] % 32;
		d = 0;
	}
	else if ((int)game->cast->tab_y[i] % 32 >= 0 && (int)game->cast->tab_y[i] \
	% 32 <= 31 && (int)game->cast->tab_x[i] % 32 == 0)
	{
		game->offsetx = (int)game->cast->tab_y[i] % 32;
		d = 1;
	}
	return (d);
}

void	draw_walls(t_map *game)
{
	int	mid;
	int	i;
	int	tex_y;
	int	index;
	int	d;

	d = 0;
	i = 0;
	mid = WINDOW_HEIGHT / 2;
	while (i < WINDOW_WIDTH)
	{
		game->toppixel = mid - game->cast->dist_wall2[i] * 0.7f;
		game->lowpixel = mid + game->cast->dist_wall2[i] * 0.7f;
		while (game->toppixel <= game->lowpixel)
		{
			d = set_offsetx(game, i, d);
			tex_y = set_tex_y(game, mid, i);
			game->offsety = (int)(tex_y % 32);
			index = (32 * game->offsety) + game->offsetx;
			my_mlx_pixel_put(game, i, game->toppixel, \
			get_tex_color(game, d, index));
			game->toppixel++;
		}
		i++;
	}
}
