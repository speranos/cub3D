/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <aoueldma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:22:13 by aoueldma          #+#    #+#             */
/*   Updated: 2023/03/10 12:28:07 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_wall_check(t_map *cub)
{
	int		i;
	char	start;
	int		line;
	char	end;

	i = 0;
	line = 1;
	ft_first_wall(cub);
	while (cub->map[line])
	{
		start = ft_wall_zero(cub, line);
		end = ft_wall_end(cub, line);
		if ((start != ' ' && start != 49) || (end != 49 && end != ' '))
			ft_wall_error(cub);
		line++;
	}
	line--;
	ft_last_wall(cub, line);
}

char	ft_wall_zero(t_map *cub, int line)
{
	int		i;
	char	c;

	i = 0;
	while (cub->map[line][i] && cub->map[line][i] <= 32 && \
	cub->map[line][i + 1] != '*')
		i++;
	c = cub->map[line][i];
	return (c);
}

char	ft_wall_end(t_map *cub, int line)
{
	int		i;
	char	c;

	i = 0;
	while (cub->map[line][i] && cub->map[line][i] != '*')
		i++;
	if (i <= 0)
		ft_wall_error(cub);
	c = cub->map[line][i - 1];
	return (c);
}

void	ft_first_wall(t_map *cub)
{
	int	i;

	i = 0;
	while (cub->map[0][i] != '*')
	{
		if (cub->map[0][i] <= 32 || cub->map[0][i] == 49)
			i++;
		else
		{
			ft_wall_error(cub);
		}
	}
}

void	ft_last_wall(t_map *cub, int line)
{
	int	i;

	i = 0;
	while (cub->map[line][i] != '*')
	{
		if (cub->map[line][i] <= 32 || cub->map[line][i] == 49)
			i++;
		else
			ft_wall_error(cub);
	}
}
