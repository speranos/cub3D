#include "../parsing/cub.h"

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