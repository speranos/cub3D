#include "cub.h"

int	main(int ac, char **av)
{
	ft_check_arg(ac, av);
	printf("waaaa\n");
}

void	ft_check_arg(int ac, char **av)
{
	(void)av;
	if(ac != 2)
		exit(0);
}