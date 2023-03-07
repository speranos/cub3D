#include "../cub3d.h"

void	texture_init(t_map *game)
{
	game->create_pixel[0].image = mlx_xpm_file_to_image(game->mlx, game->west_texture, &game->create_pixel[0].width, &game->create_pixel[0].height);
	game->create_pixel[0].image_data = (unsigned int *)mlx_get_data_addr(game->create_pixel[0].image, &game->create_pixel[0].bits_per_pixel, &game->create_pixel[0].size_line, &game->create_pixel[0].endian);

	game->create_pixel[1].image = mlx_xpm_file_to_image(game->mlx, game->north_texture, &game->create_pixel[1].width, &game->create_pixel[1].height);
	game->create_pixel[1].image_data = (unsigned int *)mlx_get_data_addr(game->create_pixel[1].image, &game->create_pixel[1].bits_per_pixel, &game->create_pixel[1].size_line, &game->create_pixel[1].endian);

	game->create_pixel[2].image = mlx_xpm_file_to_image(game->mlx, game->south_texture, &game->create_pixel[2].width, &game->create_pixel[2].height);
	game->create_pixel[2].image_data = (unsigned int *)mlx_get_data_addr(game->create_pixel[2].image, &game->create_pixel[2].bits_per_pixel, &game->create_pixel[2].size_line, &game->create_pixel[2].endian);

	game->create_pixel[3].image = mlx_xpm_file_to_image(game->mlx, game->east_texture, &game->create_pixel[3].width, &game->create_pixel[3].height);
	game->create_pixel[3].image_data = (unsigned int *)mlx_get_data_addr(game->create_pixel[3].image, &game->create_pixel[3].bits_per_pixel, &game->create_pixel[3].size_line, &game->create_pixel[3].endian);
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
	game->play->position_x = game->play->position_x_map * SCALE + 16;
	game->play->position_y = game->play->position_y_map * SCALE + 16;
	game->play->position_x_mini_carte = game->play->position_x_map * SCALE2 + 4;
	game->play->position_y_mini_carte = game->play->position_y_map * SCALE2 + 4;
}

void struct_initialisation(t_map *game)
{
	ft_img_init(game->imge);
	get_pos(game);
	player_init(game);
	texture_init(game);
	game->cast->num_rays = WINDOW_WIDTH;
}

int	mouse_move(int x, int y, t_map *game)
{
	(void)y;
	(void)x;
	(void)game;

	if (x < 400)
		game->play->turn_direction = -0.25;
	else if (x > 600)
		game->play->turn_direction = +0.25;
	else if (x > 400 || x < 600)
		game->play->turn_direction = 0;
	return (1);
}

int	mouse_click(int key, int x, int y, t_map *game)
{
	(void)y;
	(void)x;
	if (key == 1)
		game->play->turn_direction = -1;
	if (key == 2)
		game->play->turn_direction = 1;
	return (1);
}

int	mouse_release(int key, int x, int y, t_map *game)
{
	(void)y;
	(void)x;
	if (key == 1)
		game->play->turn_direction = 0;
	if (key == 2)
		game->play->turn_direction = 0;
	return (1);
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
		//printf("%f  ||  %f \n", x,y);
	}
	player->angle += player->turn_direction * player->rotation_speed;
}
