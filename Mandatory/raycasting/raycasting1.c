/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 03:22:34 by aait-mas          #+#    #+#             */
/*   Updated: 2023/03/13 22:35:43 by aait-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_pressed(int key, t_player *player)
{
	player->ad = 0;
	if (key == 13 || key == 126)
		player->walk_direction = +1;
	else if (key == 1 || key == 125)
		player->walk_direction = -1;
	else if (key == 123)
		player->turn_direction = -1;
	else if (key == 124)
		player->turn_direction = +1;
	else if (key == 0)
	{
		player->ad = 1;
		player->walk_direction = -1;
	}
	else if (key == 2)
	{
		player->ad = 1;
		player->walk_direction = +1;
	}
	else if (key == 53)
	{
		exit(0);
	}
	return (0);
}

int	key_release(int key, t_player *player)
{
	if (key == 13 || key == 126)
		player->walk_direction = 0;
	else if (key == 1 || key == 125)
		player->walk_direction = 0;
	else if (key == 123)
		player->turn_direction = 0;
	else if (key == 124)
		player->turn_direction = 0;
	else if (key == 0)
	{
		player->ad = 0;
		player->walk_direction = 0;
	}
	else if (key == 2)
	{
		player->ad = 0;
		player->walk_direction = 0;
	}
	return (0);
}
