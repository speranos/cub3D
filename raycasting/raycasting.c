#include "../parsing/cub.h"

int check_wall(t_map *game, int x, int y)
{
	if (y >= 0 && x >= 0 && game->map[y][x] == '1')
		return (1);
	return (0);
}

void ft_draw_player(t_map *game)
{
	int i;
	int j;
	int k;
	// int distance;
	double angle = game->play->angle - (30 * M_PI / 180);
	double max_ang = game->play->angle + (30 * M_PI / 180);

	game->cast->dist_wall = malloc(sizeof(double) * 1081);
	game->cast->dist_wall2 = malloc(sizeof(double) * 1081);

	float projection_distance = 0.5f * SCALE / tan(0.523599);
	i = 0;
	j = 0;
	k = 0;
	while (angle < max_ang)
	{
		i = 0;
		while (game->play->position_x + i * cos(angle) < WINDOW_WIDTH && (game->play->position_y + i * sin(angle)) < WINDOW_HEIGHT)
		{
			if (check_wall(game, (int)((game->play->position_x + i * cos(angle)) / SCALE), (int)((game->play->position_y + i * sin(angle)) / SCALE)))
				break;
			//my_mlx_pixel_put(game, (int)(game->play->position_x  + i * cos(angle)), (int)(game->play->position_y +  i * sin(angle)) , 0x00ff0000);
			i++;
		}
		game->cast->x_wall = (int)(game->play->position_x + i * cos(angle));
		game->cast->y_wall = (int)(game->play->position_y + i * sin(angle));
		game->cast->dist = sqrt((game->cast->x_wall - game->play->position_x) * (game->cast->x_wall - game->play->position_x) +
								(game->cast->y_wall - game->play->position_y) * (game->cast->y_wall - game->play->position_y));
		// printf("%d\n", game->cast->dist);
		game->cast->dist_wall[j] = game->cast->dist * cos(angle - game->play->angle);
		game->cast->dist_wall2[k] = ((WINDOW_HEIGHT * projection_distance / game->cast->dist_wall[j]));
		angle += 0.0009696273622190719871;
		j++;
		k++;
	}
	draw_circle(game);
	// printf("[ x = %d ] [ y = %d ]\n",game->cast->x_wall, game->cast->y_wall);
}

void floor_ceeling(t_map *cube)
{
	int i;
	int j;

	i = 0;
	while (i < WINDOW_HEIGHT / 2)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(cube, j, i, 0x00BFFF);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < WINDOW_HEIGHT / 2)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(cube, j, i + WINDOW_HEIGHT / 2, 0xC0C0C0);
			j++;
		}
		i++;
	}
}

void draw_walls(t_map *game)
{
	int toppixel = 0;
	int mid = WINDOW_HEIGHT / 2;
	int lowpixel;
	int i = 0;
	while (i < 1080)
	{
		toppixel = mid - game->cast->dist_wall2[i] / 2;
		lowpixel = mid + game->cast->dist_wall2[i] / 2;
		while (toppixel <= lowpixel)
		{
			my_mlx_pixel_put(game, i, toppixel, 0xD2691E);
			toppixel++;
		}
		i++;
	}
}

int ft_draw(t_map *game)
{
	ft_image(game);
	put_pixels(game);
	floor_ceeling(game);
	ft_draw_player(game);
	draw_walls(game);
	update_player(game->play, game);
	mlx_put_image_to_window(game->mlx, game->win, game->imge->img, 0, 0);
	mlx_destroy_image(game->mlx, game->imge->img);
	return (0);
}