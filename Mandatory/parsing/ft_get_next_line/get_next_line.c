/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <aoueldma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:16:05 by aoueldma          #+#    #+#             */
/*   Updated: 2023/03/14 12:14:48 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*get_next_line(int fd)
{
	static char	*left;
	int			ret;
	char		*buf;
	int			buffer_size;

	buffer_size = 13;
	buf = malloc(sizeof(char) * buffer_size + 1);
	ret = 1;
	buf[0] = '\0';
	while (!ft_searche(buf) && ret != 0)
	{
		ret = read(fd, buf, buffer_size);
		if(ret < 0)
			return(0);
		buf[ret] = '\0';
		left = ft_joint(left, buf);
	}
	free(buf);
	buf = ft_line(left);
	left = ft_update_left(left);
	return (buf);
}
