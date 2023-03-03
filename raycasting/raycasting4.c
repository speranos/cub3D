// #include "../cub3d.h"

// void put_pixels2(t_map *game)
// {
// 	int i;
// 	int j;
// 	j = 0;
// 	i = 0;

// 	while (game->map[i])
// 	{
// 		j = 0;
// 		while (game->map[i][j] != '\0')
// 		{
// 			if (game->map[i][j] == '1')
// 				print_rect(game, i * SCALE2, j * SCALE2, SCALE2, 0x808080);
// 			else if (game->map[i][j] == '0' || game->map[i][j] == 'W' || game->map[i][j] == 'N' || game->map[i][j] == 'E' || game->map[i][j] == 'S')
// 				print_rect(game, i * SCALE2, j * SCALE2, SCALE2, 0x00ffffff);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// // void ft_draw_player2(t_map *game)
// // {
// // 	int i;

// // 	i = 0;
// // 	while (i < 15)
// // 	{
// // 		my_mlx_pixel_put(game, game->play->position_x_mini_carte  + i * cos(game->play->angle), game->play->position_y_mini_carte + i * sin(game->play->angle), 0x00ff0000);
// // 		i++;
// // 	}
// // 	draw_circle2(game);
// // }

// void ft_draw_player2(t_map *game)
// {
// 	double i;
// 	double angle = game->play->angle - (30 * M_PI / 180);
// 	double max_ang = game->play->angle + (30 * M_PI / 180);

// 	i = 0;

// 	while (angle < max_ang)
// 	{
// 		i = 0;
// 		while (game->play->position_x + i * cos(angle) < WINDOW_WIDTH && (game->play->position_y + i * sin(angle)) < WINDOW_HEIGHT)
// 		{
// 			if (check_wall(game, (int)((game->play->position_x_mini_carte + i * cos(angle)) / SCALE2), (int)((game->play->position_y_mini_carte + i * sin(angle)) / SCALE2)))
// 				break;
// 			my_mlx_pixel_put(game, (int)(game->play->position_x_mini_carte + i * cos(angle)), (int)(game->play->position_y_mini_carte +  i * sin(angle)) , 0x00DFFF00);
// 			i += 0.09;
// 		}
// 		angle += 0.00097;
// 	}
// 	draw_circle2(game);
// }

// void draw_circle2(t_map *game)
// {
// 	double radius;
// 	double angle;
// 	int i;

// 	i = 0;
// 	angle = 0;
// 	radius = 0;
// 	while (radius < 4)
// 	{
// 		angle = 0;
// 		while (angle < 360)
// 		{
// 			i = 0;
// 			while (i < radius)
// 			{
// 				my_mlx_pixel_put(game, game->play->position_x_mini_carte + i * cos(angle), game->play->position_y_mini_carte + i * sin(angle), 0x008000);
// 				i++;
// 			}
// 			angle += 0.1f;
// 		}
// 		radius++;
// 	}
// }

// void update_player2(t_player *player, t_map *game)
// {
// 	double move;
// 	double x;
// 	double y;

// 	move = player->walk_direction * player->move_speed;
// 	if (player->AD == 1)
// 	{
// 		x = player->position_x_mini_carte + cos(player->angle + M_PI / 2) * move;
// 		y = player->position_y_mini_carte + sin(player->angle + M_PI / 2) * move;
// 	}
// 	else
// 	{
// 		x = player->position_x_mini_carte + cos(player->angle) * move;
// 		y = player->position_y_mini_carte + sin(player->angle) * move;
// 	}
// 	if (check_wall(game, x / SCALE2, player->position_y_mini_carte / SCALE2) != 1)
// 	{
// 		player->position_x_mini_carte = x;
// 	}
// 	if (check_wall(game, player->position_x_mini_carte / SCALE2, y / SCALE2) != 1)
// 	{
// 		player->position_y_mini_carte = y;
// 	}
// 	player->angle += player->turn_direction * player->rotation_speed;
// }
