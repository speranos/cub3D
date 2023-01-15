#include "../cub.h"

void	ft_texture_check(char *map, t_map *cub)
{
	char	c0;
	char	c1;

	c0 = map[0];
	while (ft_alpha(c0, &map) != 1)
	{
		c1 = map[0];
		if(c0 == 'N' && c1 == 'O')
			ft_valide_path(&map, cub, 'N');
		else if(c0 == 'S' && c1 == 'O')
			ft_valide_path(&map, cub, 'S');
		else if(c0 == 'W' && c1 == 'E')
			ft_valide_path(&map, cub, 'W');
		else if(c0 == 'E' && c1 == 'A')
			ft_valide_path(&map, cub, 'E');
		else if(c0 == 'F' || c0 == 'C')
			ft_rgb_valide(&map, cub, c0);
		else
			ft_texture_exit(cub);
		c0 = map[0];
	}
}

int	ft_alpha(char c, char **map)
{
	if(c >= 65 && c <= 90)
	{
		(*map)++;
		return(0);
	}
	return(1);
}

void	ft_valide_path(char **map, t_map *cub, char c)
{
	int		i;
	char	*tmp;

	ft_skip_space(map);
	i = ft_get_len_new_line(*map);
	tmp = malloc(sizeof(char) * i + 1);
	i = 0;
	while(*map[0] != '\n')
	{
		tmp[i++] = *map[0];
		(*map)++;
	}
	tmp[i] = '\0';
	(*map)++;
	ft_add_txr_struc(tmp, cub, c);
}

int	ft_get_len_new_line(char *map)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '\n')
	{
		i++;
	}
	return(i);
}

void	ft_skip_space(char **map)
{
	(*map)++;
	while(*map[0] && *map[0] <= 32)
		(*map)++;
}

void	ft_add_txr_struc(char *tmp, t_map  *cub, char c)
{
	int	fd;

	fd = open(tmp, O_RDONLY);
	if(fd == -1)
	{
		printf("ERROR...'%s' Invalid texture path !!!\n", tmp);
		//free(tmp);
		ft_texture_exit(cub);
	}
	if(c == 'N')
		cub->north_texture = tmp;
	else if(c == 'S')
		cub->south_texture = tmp;
	else if(c == 'W')
		cub->west_texture = tmp;
	else if(c == 'E')
		cub->east_texture = tmp;
}

void	ft_texture_exit(t_map *cub)
{
	if(cub->north_texture)
		free(cub->north_texture);
	if(cub->east_texture)
		free(cub->east_texture);
	if(cub->south_texture)
		free(cub->south_texture);
	if(cub->west_texture)
		free(cub->west_texture);
	if(cub->ceilling_rgb)
		free(cub->ceilling_rgb);
	if(cub->floor_rgb)
		free(cub->floor_rgb);
	exit(0);
}