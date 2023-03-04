#include "../cub3d.h"

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
				print_rect(game, i * SCALE2, j * SCALE2, SCALE2, 0x0000080);
			else if (game->map[i][j] == '0' || game->map[i][j] == 'W' || game->map[i][j] == 'N' || game->map[i][j] == 'E' || game->map[i][j] == 'S')
				print_rect(game, i * SCALE2, j * SCALE2, SCALE2, 0xC0C0C0);
			j++;
		}
		i++;
	}
}

void draw_circle(t_map *game)
{
	double radius;
	double angle;
	int i;

	i = 0;
	angle = 0;
	radius = 0;
	while (radius < 6)
	{
		angle = 0;
		while (angle < 360)
		{
			i = 0;
			while (i < radius)
			{
				my_mlx_pixel_put(game, game->play->position_x + i * cos(angle), game->play->position_y + i * sin(angle), 0x008000);
				i++;
			}
			angle += 0.1f;
		}
		radius++;
	}
}