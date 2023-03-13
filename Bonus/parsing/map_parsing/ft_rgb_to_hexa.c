/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_to_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <aoueldma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:21:34 by aoueldma          #+#    #+#             */
/*   Updated: 2023/03/10 12:24:19 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_rgb_to_hexa(t_map *cub, char c)
{
	if (c == 'c')
		cub->c_rgb = create_trgb(cub->ceilling_rgb[0], \
		cub->ceilling_rgb[1], cub->ceilling_rgb[2]);
	else
		cub->f_rgb = create_trgb(cub->floor_rgb[0], \
		cub->floor_rgb[1], cub->floor_rgb[2]);
}
