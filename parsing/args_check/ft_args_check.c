/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <aoueldma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:15:35 by aoueldma          #+#    #+#             */
/*   Updated: 2023/03/10 12:16:57 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_check_arg(int ac, char **av)
{
	if (ac != 2)
	{
		printf("ERROR...More or not enough argument !!!\n");
		exit(0);
	}
	ft_fd_check(av[1]);
	ft_dot_check(av[1]);
}

void	ft_dot_check(char *str)
{
	char	*tmp_str;
	int		a;
	int		i;

	tmp_str = "cub\0";
	i = ft_len(str);
	a = ft_len(tmp_str);
	while (str[i] != '.' || a >= 0)
	{
		if (str[i] != tmp_str[a] || a < 0)
		{
			printf("ERROR...Map fromat should be *.cub !!!\n");
			exit(0);
			return ;
		}
		i--;
		a--;
	}
}

void	ft_fd_check(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR...File '%s' not found !!!\n", str);
		exit(0);
	}
}
