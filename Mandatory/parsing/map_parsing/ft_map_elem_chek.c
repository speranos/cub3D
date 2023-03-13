/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_elem_chek.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <aoueldma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:21:06 by aoueldma          #+#    #+#             */
/*   Updated: 2023/03/10 12:21:06 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_map_char_check(char *map, t_map *cub)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (map[i])
	{
		if (map[i] <= 32)
			i++;
		else if (map[i] == '1' || map[i] == '0')
			i++;
		else if (map[i] == 'S' || map[i] == 'W'
			|| map[i] == 'N' || map[i] == 'E')
		{
			cub->player = map[i];
			p++;
			i++;
		}
		else
			ft_diff_element(cub, map[i]);
	}
	if (p != 1)
		ft_player_erro(cub);
}

void	ft_diff_element(t_map *cub, char c)
{
	printf("ERROR...'%c' Unsupported character in the map\n", c);
	ft_texture_exit(cub);
}

void	ft_player_erro(t_map *cub)
{
	printf("ERROR...You entered more or less \
		than the required number of player\n");
	ft_texture_exit(cub);
}

void	ft_last_check(t_map *cub)
{
	int		line;
	int		i;
	char	c;

	line = 0;
	i = 0;
	while (cub->map[line])
	{
		while (cub->map[line][i])
		{
			c = cub->map[line][i];
			if (c == '0')
				ft_zero_check(cub, line, i);
			else if (c == cub->player)
				ft_p_check(cub, line, i);
			i++;
		}
		i = 0;
		line++;
	}
}
