#include "../cub_parsing.h"

int	ft_get_num_of_line(char *map)
{
	int	i;
	int	len;

	i = 0;
	len = 1;
	while (map[i])
	{
		if (map[i] == '\n')
			len++;
		i++;
	}
	return (len);
}

void	ft_skip_new_line(t_map *cub, char **map)
{
	int	i;

	i = 0;
	while ((*map)[i] && (*map)[i] != '\n')
	{
		if ((*map)[i] >= 48 && (*map)[i] <= 57)
			break ;
		else if ((*map)[i] > 32)
			ft_wall_error(cub);
		i++;
	}
	if ((*map)[i] == '\n')
	{
		while (i >= 0)
		{
			(*map)++;
			i--;
		}
		ft_skip_new_line(cub, map);
	}
}

void	ft_wall_error(t_map *cub)
{
	printf("ERROR...Map must be surrounded by 1\n");
	ft_texture_exit(cub);
}

void	ft_map_to_map(t_map *cub, char *map, int num_of_line, int len)
{
	int	i;
	int	a;
	int	line;

	i = 0;
	a = 0;
	line = 0;
	while (line < num_of_line)
	{
		while (map[i] && map[i] != '\n')
			cub->map[line][a++] = map[i++];
		if (a < len)
			a = ft_stars(cub, a, line, len);
		cub->map[line++][a] = '\0';
		a = 0;
		i++;
	}
	cub->map[line] = 0;
}

int	ft_stars(t_map *cub, int a, int line, int len)
{
	while (a < len)
	{
		cub->map[line][a] = '*';
		a++;
	}
	return (a);
}
