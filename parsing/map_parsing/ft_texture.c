#include "../cub_parsing.h"

void	ft_texture_check(char **map, t_map *cub)
{
	cub->tmp = 0;
	while (cub->tmp != 1)
	{
		cub->c0 = *map[0];
		cub->tmp = ft_alpha(cub->c0, map);
		if (cub->tmp != 0)
			break ;
		if (cub->c0 == 'N' || cub->c0 == 'S'
			|| cub->c0 == 'W' || cub->c0 == 'E')
			ft_to_vald_texture(map, cub);
		else if (cub->c0 == 'F' || cub->c0 == 'C')
			ft_rgb_valide(map, cub, cub->c0);
		else if (cub->c0 <= 32)
		{
			if (ft_end_check(cub) == 1)
				break ;
			(*map)++;
		}
		else
			ft_undifiende_error(cub);
	}
}

int	ft_alpha(char c, char **map)
{
	(void)map;
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

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
