#include "../cub_parsing.h"

void	ft_add_map_to_strc(t_map *cub, char **map)
{
	int	len;
	int	num_of_line;
	int	i;

	i = 0;
	len = ft_get_gbl_len_of_line(*map);
	num_of_line = ft_get_num_of_line(*map);
	cub->x = len;
	cub->y = num_of_line;
	cub->map = malloc(sizeof(char *) * (num_of_line + 1));
	while (i < num_of_line)
	{
		cub->map[i] = malloc(sizeof(char) * (len + 1));
		i++;
	}
	ft_map_to_map(cub, *map, num_of_line, len);
	i = 0;
	while (cub->map[i])
		printf("%s\n", cub->map[i++]);
}

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

int	ft_get_gbl_len_of_line(char *map)
{
	int	i;
	int	len;
	int	tmp;

	i = 0;
	len = 0;
	tmp = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			if (tmp < len)
				tmp = len;
			len = 0;
		}
		i++;
		len++;
		if (map[i] == '\0' && tmp < len)
			tmp = len;
	}
	return (tmp);
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