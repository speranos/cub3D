/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <aoueldma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 03:39:47 by aait-mas          #+#    #+#             */
/*   Updated: 2023/03/10 22:01:58 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_wall(t_map *game, int x, int y)
{
	if (y >= 0 && x >= 0 && game->map[y][x] == '1')
		return (1);
	return (0);
}

void	texture_addr_init(t_map *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->create_pixel[i].image_data = (unsigned int *)mlx_get_data_addr(\
		game->create_pixel[i].image, &game->create_pixel[i].bits_per_pixel, \
		&game->create_pixel[i].size_line, &game->create_pixel[i].endian);
		i++;
	}
}

void	check_xpm_file(t_map *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!game->create_pixel[i].image)
		{
			printf("Error...Bad file !!!");
			exit (1);
		}
		i++;
	}
}

void	texture_init(t_map *game)
{
	int	i;

	i = 0;
	game->create_pixel[0].image = mlx_xpm_file_to_image(game->mlx, game->w_t, \
	&game->create_pixel[0].width, &game->create_pixel[0].height);
	game->create_pixel[1].image = mlx_xpm_file_to_image(game->mlx, game->n_t, \
	&game->create_pixel[1].width, &game->create_pixel[1].height);
	game->create_pixel[2].image = mlx_xpm_file_to_image(game->mlx, game->s_t, \
	&game->create_pixel[2].width, &game->create_pixel[2].height);
	game->create_pixel[3].image = mlx_xpm_file_to_image(game->mlx, game->e_t, \
	&game->create_pixel[3].width, &game->create_pixel[3].height);
	check_xpm_file(game);
	texture_addr_init(game);
}
