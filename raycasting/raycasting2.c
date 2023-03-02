#include "../parsing/cub.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void ft_image(t_map *game)
{
	game->imge->img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->imge->add_img = mlx_get_data_addr(game->imge->img, &game->imge->bits_per_pixel, &game->imge->size_line, &game->imge->endian);
}

void ft_img_init(t_img *img)
{
	img->bits_per_pixel = 0;
	img->size_line = 0;
	img->endian = 0;
}

void get_pos(t_map *game)
{
	int i;
	int j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'W' || game->map[i][j] == 'S' || game->map[i][j] == 'E')
			{
				game->play->position_y = i;
				game->play->position_x = j;
			}
			j++;
		}
		i++;
	}
}

void my_mlx_pixel_put(t_map *game, int x, int y, int color)
{
	char *dst;

	if (x >= 0 && y >= 0 && x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
	{
		dst = game->imge->add_img + (y * game->imge->size_line + x * (game->imge->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}