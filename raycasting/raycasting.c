#include "../cub3d.h"

int check_wall(t_map *game, int x, int y)
{
	if (y >= 0 && x >= 0 && game->map[y][x] == '1')
		return (1);
	return (0);
}

void ft_draw_player(t_map *game)
{
	double i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;

	double angle = game->play->angle - (30 * M_PI / 180);
	double max_ang = game->play->angle + (30 * M_PI / 180);
	game->cast->dist_wall = malloc(sizeof(double) * 1080);
	game->cast->dist_wall2 = malloc(sizeof(double) * 1080);
	game->cast->tab_x = malloc(sizeof(double) * 1080);
	game->cast->tab_y = malloc(sizeof(double) * 1080);

	float projection_distance = 0.7f * 32 / tan(0.523599);
	while (angle < max_ang)
	{
		i = 0;
		while (game->play->position_x + i * cos(angle) < WINDOW_WIDTH && (game->play->position_y + i * sin(angle)) < WINDOW_HEIGHT)
		{
			if (check_wall(game, (int)((game->play->position_x + i * cos(angle)) / SCALE), (int)((game->play->position_y + i * sin(angle)) / SCALE)))
				break;
			i += 0.05;
		}
		game->cast->x_wall = (game->play->position_x + i * cos(angle));
		game->cast->y_wall = (game->play->position_y + i * sin(angle));
		game->cast->dist = sqrt((game->cast->x_wall - game->play->position_x) * (game->cast->x_wall - game->play->position_x) +
								(game->cast->y_wall - game->play->position_y) * (game->cast->y_wall - game->play->position_y)) + 10;
		game->cast->tab_x[j] = game->cast->x_wall;
		game->cast->tab_y[j] = game->cast->y_wall;
		game->cast->dist_wall[j] = game->cast->dist * cos(game->play->angle - angle);
		game->cast->dist_wall2[k] = ((WINDOW_HEIGHT * projection_distance / game->cast->dist_wall[j]));
		angle += 0.00097;
		j++;
		k++;
	}
}

void draw_walls(t_map *game)
{
    int toppixel = 0;
    int mid = WINDOW_HEIGHT / 2;
    int lowpixel;
    int i = 0;
    int tex_y;
    int index;
    int color;
    int offsetx;
    int offsety;
	int	d = 0;

    while (i < WINDOW_WIDTH)
    {
        toppixel = mid - game->cast->dist_wall2[i] * 0.7f;
        lowpixel = mid + game->cast->dist_wall2[i] * 0.7f;
        offsetx = (int)game->cast->tab_y[i] % 32;
        while (toppixel <= lowpixel)
        {
			if ((int)game->cast->tab_x[i] % 32 > 0 && (int)game->cast->tab_x[i] % 32 < 31 && (int)game->cast->tab_y[i] % 32 == 0){

				offsetx = (int)game->cast->tab_x[i] % 32;
				d = 0;
			}

			else if ((int)game->cast->tab_y[i] % 32 > 0 && (int)game->cast->tab_y[i] % 32 < 31 && (int)game->cast->tab_x[i] % 32 == 31){
				offsetx = (int)game->cast->tab_y[i] % 32;
				d = 1;
			
			
			}

			else if ((int)game->cast->tab_x[i] % 32 > 0 && (int)game->cast->tab_x[i] % 32 < 31 && (int)game->cast->tab_y[i] % 32 == 31){
				offsetx = (int)game->cast->tab_x[i] % 32;
				d = 2;
			}
			else if ((int)game->cast->tab_y[i] % 32 > 0 && (int)game->cast->tab_y[i] % 32 < 31 && (int)game->cast->tab_x[i] % 32 == 0){
				offsetx = (int)game->cast->tab_y[i] % 32;
				d = 3;
			}
            tex_y = (int)(((float)(toppixel - mid + game->cast->dist_wall2[i] * 0.7f) / (float)(2.0f * game->cast->dist_wall2[i] * 0.7f)) * (float)32);
            offsety = (int)(tex_y % 32);
            index = (32 * offsety) + offsetx;
            color = game->create_pixel[d].image_data[index];
            my_mlx_pixel_put(game, i, toppixel, color);
            toppixel++;
        }
        i++;
    }
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

int ft_draw(t_map *game)
{
	ft_image(game);
	floor_ceeling(game);
	ft_draw_player(game);
	draw_walls(game);
	put_pixels(game);
	update_player(game->play, game);
	ft_draw_player_mini_map(game);
	update_player_mini_map(game->play, game);
	mlx_put_image_to_window(game->mlx, game->win, game->imge->img, 0, 0);
	mlx_destroy_image(game->mlx, game->imge->img);
	return (0);
}