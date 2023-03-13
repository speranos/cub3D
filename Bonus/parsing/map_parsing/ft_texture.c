/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <aoueldma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:21:53 by aoueldma          #+#    #+#             */
/*   Updated: 2023/03/10 12:21:53 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_texture_check(char **map, t_map *cub)
{
	cub->tmp = 0;
	while (cub->tmp != 1)
	{
		cub->c0 = *map[0];
		cub->tmp = ft_alpha(cub->c0, map);
		if (cub->tmp != 0)
			break ;
		if (cub->c0 == 'N' || cub->c0 == 'S'
			|| cub->c0 == 'W' || cub->c0 == 'E')
			ft_texture_valid(map, cub);
		else if (cub->c0 == 'F' || cub->c0 == 'C')
			ft_rgb_valide(map, cub, cub->c0);
		else if (cub->c0 <= 32)
		{
			if (ft_end_check(cub) == 1)
				break ;
			(*map)++;
		}
		else
			ft_undifiende_error(cub);
	}
}

int	ft_alpha(char c, char **map)
{
	(void)map;
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	ft_texture_valid(char **map, t_map *cub)
{
	(*map)++;
	cub->c1 = *map[0];
	ft_valide_path(map, cub, cub->c0, cub->c1);
}

int	ft_end_check(t_map *cub)
{
	if (cub->ceilling_rgb && cub->e_t && cub->floor_rgb
		&& cub->n_t && cub->s_t && cub->w_t)
		return (1);
	return (0);
}

void	ft_undifiende_error(t_map *cub)
{
	printf("ERROR...Undifiende character: %c\n", cub->c0);
	ft_texture_exit(cub);
}
