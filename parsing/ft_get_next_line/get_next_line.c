#include "../cub_parsing.h"
#include <fcntl.h>

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
		buf[ret] = '\0';
		left = ft_joint(left, buf);
	}
	free(buf);
	buf = ft_line(left);
	left = ft_update_left(left);
	return (buf);
}
