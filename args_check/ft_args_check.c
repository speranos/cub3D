#include "../cub.h"

void	ft_check_arg(int ac, char **av)
{
	if(ac != 2)
	{
		printf("ERRO...More or not enough argument !!!\n");
		exit(0);
	}
	ft_fd_check(av[1]);
	ft_dot_check(av[1]);

}

void	ft_dot_check(char *str)
{
	int		i;
	char	*tmp_str;
	int		a;

	tmp_str = "cub\0";
	i = ft_len(str);
	a = ft_len(tmp_str);
	while(str[i] != '.' || a >= 0)
	{
		if(str[i] != tmp_str[a] || a < 0)
		{
			printf("ERROR...Map fromat should be *.cub !!!\n");
			exit(0);
			return;
		}
		i--;
		a--;
	}
}

void	ft_fd_check(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if(fd == -1)
	{
		printf("ERROR...File '%s' not found !!!\n", str);
		exit(0);
	}
}