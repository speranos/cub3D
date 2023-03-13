/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_elem_chek5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <aoueldma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:21:14 by aoueldma          #+#    #+#             */
/*   Updated: 2023/03/10 12:21:14 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_skip_new_line(t_map *cub, char **map)
{
	int	i;

	i = 0;
	while ((*map)[i] && (*map)[i] != '\n')
	{
		if ((*map)[i] >= 48 && (*map)[i] <= 57)
			break ;
		else if ((*map)[i] > 32)
			ft_wall_error(cub);
		i++;
	}
	if ((*map)[i] == '\n')
	{
		while (i >= 0)
		{
			(*map)++;
			i--;
		}
		ft_skip_new_line(cub, map);
	}
}
