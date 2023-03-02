#include "../cub.h"

void	ft_empty_map(char *read)
{
	free(read);
	printf("ERROR...File empty !!!\n");
	exit(1);
}

char	*ft_read(char **av)
{
	int		fd;
	char	*ret;
	char	*read;

	ret = NULL;
	fd = open(av[1], O_RDONLY);
	read = get_next_line(fd);
	if (read == NULL)
		ft_empty_map(read);
	while (read != NULL)
	{
		ret = ft_joint(ret, read);
		free(read);
		read = get_next_line(fd);
	}
	return (ret);
}

void	ft_init_strc(t_map *cub)
{
	cub->north_texture = NULL;
	cub->south_texture = NULL;
	cub->west_texture = NULL;
	cub->east_texture = NULL;
	cub->ceilling_rgb = NULL;
	cub->floor_rgb = NULL;
}

void	ft_map_parsing(char **av, t_map *cub)
{
	char	*full_map;
	char	*tmp;

	full_map = ft_read(av);
	tmp = full_map;
	ft_init_strc(cub);
	ft_texture_check(&full_map, cub);
	ft_map_elem_check(&full_map, cub);
	free(tmp);
}

void	ft_rm_rf(t_map *cub)
{
	ft_free_map(cub);
	ft_free_element(cub);
}

void	ft_free_map(t_map *cub)
{
	int	line;
	int	i;

	line = 0;
	i = 0;
	while(cub->map[line])
	{
		free(cub->map[line++]);
	}
	free(cub->map);
}

void	ft_free_element(t_map *cub)
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
}