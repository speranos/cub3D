#include "../parsing/cub.h"

void print_rect(t_map *game, int x, int y, int z, unsigned int color)
{
	int i;
	int j;

	i = 0;
	while (i < z)
	{
		j = 0;
		while (j < z)
		{
			my_mlx_pixel_put(game, y + j, x + i, color);
			j++;
		}
		i++;
	}
}

void put_pixels(t_map *game)
{
	int i;
	int j;
	j = 0;
	i = 0;

	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == '1')
				print_rect(game, i * SCALE, j * SCALE, SCALE, 0x808080);
			else if (game->map[i][j] == '0' || game->map[i][j] == 'W' || game->map[i][j] == 'N' || game->map[i][j] == 'E' || game->map[i][j] == 'S')
				print_rect(game, i * SCALE, j * SCALE, SCALE, 0x00ffffff);
			j++;
		}
		i++;
	}
}

void player_init(t_map *game)
{
	if (game->player == 'N')
		game->play->angle = 360 * M_PI / 180; // 2pi
	else if (game->player == 'S')
		game->play->angle = 180 * M_PI / 180; // pi
	else if (game->player == 'W')
		game->play->angle = 270 * M_PI / 180; // 3pi/2
	else if (game->player == 'E')
		game->play->angle = 90 * M_PI / 180; // pi/2
	game->play->AD = 0;
	game->play->move_speed = 4;
	game->play->turn_direction = 0;
	game->play->walk_direction = 0;
	game->play->rotation_speed = (M_PI / 180) * 4;
	game->play->position_x = game->play->position_x * SCALE + 16;
	game->play->position_y = game->play->position_y * SCALE + 16;
}

void struct_initialisation(t_map *game)
{
	ft_img_init(game->imge);
	get_pos(game);
	player_init(game);
	game->cast->num_rays = WINDOW_WIDTH;
}

int key_release(int key, t_player *player)
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
		player->AD = 0;
		player->walk_direction = 0;
	}
	else if (key == 2)
	{
		player->AD = 0;
		player->walk_direction = 0;
	}
	return (0);
}

int key_pressed(int key, t_player *player)
{
	player->AD = 0;
	if (key == 13 || key == 126) // W  flesh haut
		player->walk_direction = +1;
	else if (key == 1 || key == 125) // S  flesh bas
		player->walk_direction = -1;
	else if (key == 123) //  < camera wawaw
		player->turn_direction = -1;
	else if (key == 124) //  > camera wawaw
		player->turn_direction = +1;
	else if (key == 0) //  A
	{
		player->AD = 1;
		player->walk_direction = -1;
	}
	else if (key == 2) //  D
	{
		player->AD = 1;
		player->walk_direction = +1;
	}
	else if (key == 53) //  ESP
	{
		exit(0);
	}
	return (0);
}

void update_player(t_player *player, t_map *game)
{
	double move;
	double x;
	double y;

	move = player->walk_direction * player->move_speed;
	if (player->AD == 1)
	{
		x = player->position_x + cos(player->angle + M_PI / 2) * move;
		y = player->position_y + sin(player->angle + M_PI / 2) * move;
		// printf(" [%f  ||  %f ]\n", x,y);
	}
	else
	{
		x = player->position_x + cos(player->angle) * move;
		y = player->position_y + sin(player->angle) * move;
		// printf("%f  ||  %f \n", x,y);
	}
	if (check_wall(game, x / SCALE, player->position_y / SCALE) != 1)
	{
		player->position_x = x;
		// printf("{%f  ||  %f }\n", x,y);
	}
	if (check_wall(game, player->position_x / SCALE, y / SCALE) != 1)
	{
		player->position_y = y;
		// printf("%f  ||  %f \n", x,y);
	}
	player->angle += player->turn_direction * player->rotation_speed;
}

