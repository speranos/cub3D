#include "../cub.h"

void    ft_map_elem_check(char  **map, t_map *cub)
{
	(void)map;
	ft_validate(cub);
	ft_skip_new_line(cub, map);
	ft_map_char_check(*map, cub);
	ft_add_map_to_strc(cub, map);
	//ft_check_wall;
	ft_last_check(cub);
}

void    ft_validate(t_map *cub)
{
	if(!cub->ceilling_rgb || !cub->floor_rgb)
		ft_map_error(cub, 'c');
	if(!cub->east_texture || !cub->north_texture
		|| !cub->south_texture || !cub->west_texture)
		ft_map_error(cub, 't');
}

void    ft_map_error(t_map *cub, char c)
{
	if(c == 'c')
		printf("ERROR...Missing color\n");
	else if(c == 't')
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
	cub->map = malloc(sizeof(char*) * (num_of_line + 1));
	while(i < num_of_line)
	{
		cub->map[i] = malloc(sizeof(char) * (len + 1));
		i++;
	}
	ft_map_to_map(cub, *map, num_of_line, len);
	i = 0;
	while(cub->map[i])
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
	while(map[i])
	{
		if(map[i] == '\n')
		{
			if(len > tmp)
				tmp = len;
			len = 0;
		}
		i++;
		len++;
	}
	return(tmp);
}

int	ft_get_num_of_line(char *map)
{
	int	i;
	int	len;

	i = 0;
	len = 1;
	while(map[i])
	{
		if(map[i] == '\n')
			len++;
		i++;
	}
	return(len);
}

void	ft_skip_new_line(t_map *cub, char **map)
{
	int	i;

	i = 0;
	while((*map)[i] && (*map)[i] != '\n')
	{
		if((*map)[i] >= 48 && (*map)[i] <= 57)
			break;
		else if((*map)[i] > 32)
			ft_wall_error(cub);
		i++;
	}
	if((*map)[i] == '\n')
	{
		while(i >= 0)
		{
			(*map)++;
			i--;
		}
		ft_skip_new_line(cub, map);
	}
}

void	ft_wall_error(t_map *cub)
{
	//to add :
	// if(cub->map)
	// 	ft_free_map(cub);
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
	while(line < num_of_line)
	{
		while(map[i] && map[i] != '\n')
			cub->map[line][a++] = map[i++];
		if(a < len)
			a = ft_stars(cub, a, line, len);
		cub->map[line++][a] = '\0';
		a = 0;
		i++;
	}
	cub->map[line] = 0;
}

int	ft_stars(t_map *cub, int a, int line, int len)
{
	while(a < len)
	{
		cub->map[line][a] = '*';
		a++;
	}
	return(a);
}

void	ft_map_char_check(char *map, t_map *cub)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while(map[i])
	{
		if(map[i] <= 32)
			i++;
		else if(map[i] == '1' || map[i] == '0')
			i++;
		else if(map[i] == 'S' || map[i] == 'W'
			|| map[i] == 'N' || map[i] == 'E')
		{
			cub->player = map[i];
			p++;
			i++;
		}
		else
			ft_diff_element(cub, map[i]);
	}
	if(p != 1)
		ft_player_erro(cub);
}

void	ft_diff_element(t_map *cub, char c)
{
	printf("ERROR...'%c' Unsupported character in the map\n", c);
	ft_texture_exit(cub);
}

void	ft_player_erro(t_map *cub)
{
	printf("ERROR...You entered more or less than the required number of player\n");
	ft_texture_exit(cub);
}

void	ft_last_check(t_map *cub)
{
	int		line;
	int		i;
	char	c;

	line = 0;
	i = 0;
	while(cub->map[line])
	{
		while(cub->map[line][i])
		{
			c = cub->map[line][i];
			if(c == '0')
				ft_zero_check(cub, line, i);
			else if(c == cub->player)
				ft_p_check(cub, line, i);
			i++;
		}
		i = 0;
		line++;
	}
}

void	ft_zero_check(t_map *cub, int line, int i)
{
	if(cub->map[line][i + 1] != '0' && cub->map[line][i + 1] != '1'
		&& cub->map[line][i + 1] != cub->player)
			ft_zero_error(cub);
	else if(cub->map[line][i - 1] != '0' && cub->map[line][i - 1] != '1'
		&& cub->map[line][i - 1] != cub->player)
			ft_zero_error(cub);
	else if(cub->map[line + 1][i] != '0' && cub->map[line + 1][i] != '1'
		&& cub->map[line + 1][i] != cub->player)
			ft_zero_error(cub);
	else if(cub->map[line - 1][i] != '0' && cub->map[line - 1][i] != '1'
		&& cub->map[line - 1][i] != cub->player)
			ft_zero_error(cub);
}

void	ft_p_check(t_map *cub, int line, int i)
{
	if(cub->map[line][i + 1] != '0' && cub->map[line][i + 1] != '1')
		ft_p_error(cub);
	else if(cub->map[line][i - 1] != '0' && cub->map[line][i - 1] != '1')
		ft_p_error(cub);
	else if(cub->map[line + 1][i] != '0' && cub->map[line + 1][i] != '1')
		ft_p_error(cub);
	else if(cub->map[line - 1][i] != '0' && cub->map[line - 1][i] != '1')
		ft_p_error(cub);
}

void	ft_zero_error(t_map *cub)
{
	printf("ERROR...'0' Should be surrounded by '0' or '1' or 'player'\n");
	ft_texture_exit(cub);
}

void	ft_p_error(t_map *cub)
{
	printf("ERROR...Player should be surrounded by '0' or '1'\n");
	ft_texture_exit(cub);
}