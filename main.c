#include "cub.h"

int	main(int ac, char **av)
{
	t_map	cub;

	ft_check_arg(ac, av);
	ft_map_parsing(av, &cub);
	//raycasting
	printf("y = =>>>>>>>>>> %d\nx =>>>>>>>>> %d\n", cub.y, cub.x);
	ft_rm_rf(&cub);
	while(1);
	// {
	// }
}

// int	main(int ac, char **av)
// {
// 	int	fd;
// 	char	*line;
// 	(void)ac;
// 	fd = open(av[1], O_RDONLY);
// 	line = get_next_line(fd);
// 	while(line != NULL)
// 	{
// 		printf("line ============ %s\n", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	while (1)
// 	{
// 	}
// }