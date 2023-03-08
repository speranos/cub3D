#include "../cub_parsing.h"

int	ft_rgb_atoi(char **map)
{
	int	res;

	res = 0;
	while (*map[0] != ',' && *map[0] != '\n')
	{
		res = res * 10 + (*map[0] - 48);
		(*map)++;
	}
	return (res);
}

void	ft_add_floor(t_map *cub, char **map)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	cub->floor_rgb = malloc(sizeof(int) * 3);
	while (*map[0] != '\n')
	{
		num = ft_rgb_atoi(map);
		if (num < 0 || num > 255)
			ft_rgb_error(cub);
		else
			cub->floor_rgb[i++] = num;
		if (*map[0] == '\n')
			break ;
		(*map)++;
	}
	(*map)++;
}

void	ft_add_ceilling(t_map *cub, char **map)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	cub->ceilling_rgb = malloc(sizeof(int) * 3);
	while (*map[0] != '\n')
	{
		num = ft_rgb_atoi(map);
		if (num < 0 || num > 255)
			ft_rgb_error(cub);
		else
			cub->ceilling_rgb[i++] = num;
		if (*map[0] == '\n')
			break ;
		(*map)++;
	}
	(*map)++;
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
