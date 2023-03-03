#include "../cub_parsing.h"

void ft_texture_check(char **map, t_map *cub)
{
	cub->tmp = 0;
	while (cub->tmp != 1)
	{
		cub->c0 = *map[0];
		cub->tmp = ft_alpha(cub->c0, map);
		if (cub->tmp != 0)
			break;
		if (cub->c0 == 'N' || cub->c0 == 'S' || cub->c0 == 'W' || cub->c0 == 'E')
			ft_to_vald_texture(map, cub);
		else if (cub->c0 == 'F' || cub->c0 == 'C')
			ft_rgb_valide(map, cub, cub->c0);
		else if (cub->c0 <= 32)
		{
			if (ft_end_check(cub) == 1)
				break;
			(*map)++;
		}
		else
			ft_undifiende_error(cub);
	}
}

int ft_alpha(char c, char **map)
{
	(void)map;
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void ft_valide_path(char **map, t_map *cub, char c0, char c1)
{
	int i;
	char *tmp;

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

	//                      (*map)++;
	ft_add_txr_struc(tmp, cub, c0);
}

int ft_get_len_new_line(char *map)
{
	int i;

	i = 0;
	while (map[i] && map[i] != '\n')
	{
		i++;
	}
	return (i);
}

void ft_skip_space(char **map)
{
	//(*map)++;
	while (*map[0] && *map[0] <= 32)
	{
		if (*map[0] == '\n')
			break;
		(*map)++;
	}
}

void ft_add_txr_struc(char *tmp, t_map *cub, char c)
{
	int fd;

	fd = open(tmp, O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR...'%s' Invalid texture path !!!\n", tmp);
		ft_texture_exit(cub);
	}
	if (c == 'N' && !cub->north_texture)
		cub->north_texture = tmp;
	else if (c == 'S' && !cub->south_texture)
		cub->south_texture = tmp;
	else if (c == 'W' && !cub->west_texture)
		cub->west_texture = tmp;
	else if (c == 'E' && !cub->east_texture)
		cub->east_texture = tmp;
	else
	{
		printf("ERROR...Texture entered twice\n");
		ft_texture_exit(cub);
	}
}

void ft_texture_exit(t_map *cub)
{
	if (cub->north_texture)
		free(cub->north_texture);
	if (cub->east_texture)
		free(cub->east_texture);
	if (cub->south_texture)
		free(cub->south_texture);
	if (cub->west_texture)
		free(cub->west_texture);
	if (cub->ceilling_rgb)
		free(cub->ceilling_rgb);
	if (cub->floor_rgb)
		free(cub->floor_rgb);
	exit(0);
}

void ft_undifiende_error(t_map *cub)
{
	printf("ERROR...Undifiende character: %c\n", cub->c0);
	ft_texture_exit(cub);
}

void ft_check_second_char(t_map *cub, char c0, char c1)
{
	if (c0 == 'N' && c1 == 'O')
		return;
	else if (c0 == 'S' && c1 == 'O')
		return;
	else if (c0 == 'W' && c1 == 'E')
		return;
	else if (c0 == 'E' && c1 == 'A')
		return;
	else
	{
		printf("ERROR...Element not valide\n");
		ft_texture_exit(cub);
	}
}

int ft_end_check(t_map *cub)
{
	if (cub->ceilling_rgb && cub->east_texture && cub->floor_rgb && cub->north_texture && cub->south_texture && cub->west_texture)
		return (1);
	return (0);
}

void ft_to_vald_texture(char **map, t_map *cub)
{
	(*map)++;
	cub->c1 = *map[0];
	ft_valide_path(map, cub, cub->c0, cub->c1);
}