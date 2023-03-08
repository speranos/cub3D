#include "../cub_parsing.h"

void	ft_map_elem_check(char **map, t_map *cub)
{
	ft_validate(cub);
	ft_skip_new_line(cub, map);
	ft_map_char_check(*map, cub);
	ft_add_map_to_strc(cub, map);
	ft_wall_check(cub);
	ft_last_check(cub);
}

void	ft_validate(t_map *cub)
{
	if (!cub->ceilling_rgb || !cub->floor_rgb)
		ft_map_error(cub, 'c');
	if (!cub->e_t || !cub->n_t || !cub->s_t || !cub->w_t)
		ft_map_error(cub, 't');
}

void	ft_map_error(t_map *cub, char c)
{
	if (c == 'c')
		printf("ERROR...Missing color\n");
	else if (c == 't')
		printf("ERROR...Missing texture\n");
	ft_texture_exit(cub);
}

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
