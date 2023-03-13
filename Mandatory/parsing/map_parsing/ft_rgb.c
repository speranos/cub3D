/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <aoueldma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:21:40 by aoueldma          #+#    #+#             */
/*   Updated: 2023/03/10 12:23:40 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_rgb_valide(char **map, t_map *cub, char c)
{
	(*map)++;
	if (*map[0] > 32)
	{
		printf("ERROR...RGB must separated by space\n");
		ft_texture_exit(cub);
	}
	ft_skip_space(map);
	ft_num_rgb(*map, cub);
	ft_num_to_struct(cub, map, c);
}

void	ft_num_rgb(char *map, t_map *cub)
{
	int	i;
	int	kama;

	i = 0;
	kama = 0;
	while (map[i] != '\n')
	{
		if (map[i] == ',' && (map[i - 1] >= 48 && map[i - 1] <= 57)
			&& (map[i + 1] >= 48 && map[i + 1] <= 57))
		{
			kama++;
			i++;
		}
		else if (map[i] >= 48 && map[i] <= 57)
			i++;
		else
			ft_rgb_error(cub);
	}
	ft_kama_check(kama, cub);
}

void	ft_kama_check(int kama, t_map *cub)
{
	if (kama != 2)
		ft_rgb_error(cub);
}

void	ft_rgb_error(t_map *cub)
{
	printf("ERORR...RGB\n");
	ft_texture_exit(cub);
}
