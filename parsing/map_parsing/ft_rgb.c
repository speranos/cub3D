#include "../cub_parsing.h"

void	ft_rgb_valide(char **map, t_map *cub, char c)
{
	(*map)++;
	if (*map[0] > 32)
	{
		printf("ERROR...RGB must separated by space\n");
		ft_texture_exit(cub);
	}
	ft_skip_space(map);
	ft_num_rgb(*map, cub);
	ft_num_to_struct(cub, map, c);
}

void	ft_num_rgb(char *map, t_map *cub)
{
	int	i;
	int	kama;

	i = 0;
	kama = 0;
	while (map[i] != '\n')
	{
		if (map[i] == ',' && (map[i - 1] >= 48 && map[i - 1] <= 57)
			&& (map[i + 1] >= 48 && map[i + 1] <= 57))
		{
			kama++;
			i++;
		}
		else if (map[i] >= 48 && map[i] <= 57)
			i++;
		else
			ft_rgb_error(cub);
	}
	ft_kama_check(kama, cub);
}

void	ft_kama_check(int kama, t_map *cub)
{
	if (kama != 2)
		ft_rgb_error(cub);
}

void	ft_rgb_error(t_map *cub)
{
	printf("ERORR...RGB\n");
	ft_texture_exit(cub);
}

void	ft_num_to_struct(t_map *cub, char **map, char c)
{
	if (c == 'F' && !cub->floor_rgb)
		ft_add_floor(cub, map);
	else if (c == 'C' && !cub->ceilling_rgb)
		ft_add_ceilling(cub, map);
	else
	{
		printf("ERROR...RGB entered twice\n");
		ft_texture_exit(cub);
	}
}
