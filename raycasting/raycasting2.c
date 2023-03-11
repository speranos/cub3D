/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 03:39:58 by aait-mas          #+#    #+#             */
/*   Updated: 2023/03/11 12:14:50 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_image(t_map *game)
{
	game->imge->img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->imge->add_img = mlx_get_data_addr(game->imge->img, \
		&game->imge->bits_per_pixel, &game->imge->size_line, \
		&game->imge->endian);
}

void	ft_img_init(t_img *img)
{
	img->bits_per_pixel = 32;
	img->size_line = 720 * (32 / 8);
	img->endian = 10;
}

void	get_pos(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'W'
			|| game->map[i][j] == 'S' || game->map[i][j] == 'E')
			{
				game->play->position_y_map = i;
				game->play->position_x_map = j;
			}
			j++;
		}
		i++;
	}
}

void	my_mlx_pixel_put(t_map *game, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
	{
		dst = game->imge->add_img + \
			(y * game->imge->size_line + x * (game->imge->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
