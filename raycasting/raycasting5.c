/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 03:39:47 by aait-mas          #+#    #+#             */
/*   Updated: 2023/03/08 09:55:06 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_wall(t_map *game, int x, int y)
{
	if (y >= 0 && x >= 0 && game->map[y][x] == '1')
		return (1);
	return (0);
}

void	texture_init(t_map *game)
{
	game->create_pixel[0].image = mlx_xpm_file_to_image(game->mlx, game->w_t, &game->create_pixel[0].width, &game->create_pixel[0].height);
	game->create_pixel[0].image_data = (unsigned int *)mlx_get_data_addr(game->create_pixel[0].image, &game->create_pixel[0].bits_per_pixel, &game->create_pixel[0].size_line, &game->create_pixel[0].endian);
	game->create_pixel[1].image = mlx_xpm_file_to_image(game->mlx, game->n_t, &game->create_pixel[1].width, &game->create_pixel[1].height);
	game->create_pixel[1].image_data = (unsigned int *)mlx_get_data_addr(game->create_pixel[1].image, &game->create_pixel[1].bits_per_pixel, &game->create_pixel[1].size_line, &game->create_pixel[1].endian);
	game->create_pixel[2].image = mlx_xpm_file_to_image(game->mlx, game->s_t, &game->create_pixel[2].width, &game->create_pixel[2].height);
	game->create_pixel[2].image_data = (unsigned int *)mlx_get_data_addr(game->create_pixel[2].image, &game->create_pixel[2].bits_per_pixel, &game->create_pixel[2].size_line, &game->create_pixel[2].endian);
	game->create_pixel[3].image = mlx_xpm_file_to_image(game->mlx, game->e_t, &game->create_pixel[3].width, &game->create_pixel[3].height);
	game->create_pixel[3].image_data = (unsigned int *)mlx_get_data_addr(game->create_pixel[3].image, &game->create_pixel[3].bits_per_pixel, &game->create_pixel[3].size_line, &game->create_pixel[3].endian);
}