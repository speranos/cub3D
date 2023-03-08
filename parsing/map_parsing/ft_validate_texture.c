#include "../cub_parsing.h"

void	ft_valide_path(char **map, t_map *cub, char c0, char c1)
{
	int		i;
	char	*tmp;

	ft_check_second_char(cub, c0, c1);
	(*map)++;
	if (*map[0] > 32)
	{
		printf("ERROR...Texture must separated by space\n");
		ft_texture_exit(cub);
	}
	ft_skip_space(map);
	i = ft_get_len_new_line(*map);
	tmp = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (*map[0] && *map[0] != '\n')
	{
		tmp[i++] = *map[0];
		(*map)++;
	}
	tmp[i] = '\0';
	ft_add_txr_struc(tmp, cub, c0);
}

void	ft_check_second_char(t_map *cub, char c0, char c1)
{
	if (c0 == 'N' && c1 == 'O')
		return ;
	else if (c0 == 'S' && c1 == 'O')
		return ;
	else if (c0 == 'W' && c1 == 'E')
		return ;
	else if (c0 == 'E' && c1 == 'A')
		return ;
	else
	{
		printf("ERROR...Element not valide\n");
		ft_texture_exit(cub);
	}
}


int	ft_get_len_new_line(char *map)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '\n')
	{
		i++;
	}
	return (i);
}

void	ft_skip_space(char **map)
{
	while (*map[0] && *map[0] <= 32)
	{
		if (*map[0] == '\n')
			break ;
		(*map)++;
	}
}