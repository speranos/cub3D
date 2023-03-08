#include "../cub_parsing.h"

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
	cub->n_t = NULL;
	cub->s_t = NULL;
	cub->w_t = NULL;
	cub->e_t = NULL;
	cub->ceilling_rgb = NULL;
	cub->floor_rgb = NULL;
}

void	cub3d(char **av, t_map *cub)
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
