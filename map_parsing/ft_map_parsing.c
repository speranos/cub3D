#include "../cub.h"
char	*ft_empty_map(char *read)
{
	free(read);
	printf("ERROR...File empty !!!\n");
	return(NULL);
}

char	*ft_read(char **av)
{
	int	fd;
	char	*ret;
	char	*read;

	ret = NULL;
	fd = open(av[1], O_RDONLY);
	read = get_next_line(fd);
	if(read == NULL)
		return(ft_empty_map(read));
	while (read != NULL)
	{
		ret = ft_joint(ret, read);
		free(read);
		read = get_next_line(fd);
	}
	return(ret);
}

void	ft_map_parsing(char **av)
{
	char	*full_map;
	t_map	cub;

	full_map = ft_read(av);
	ft_init_strc();
	ft_texture_check(full_map, &cub);
	ft_map_elem_check(full_map, &cub);
	free(full_map);
	printf("HOOOOOO\n");
	while(1)
	{
		
	}
}

void	ft_