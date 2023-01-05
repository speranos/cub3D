#include "../cub.h"

int	ft_searche(char	*buf)
{
	int	i;

	i = 0;
	if(!buf)
		return(1);
	while(buf[i])
	{
		if(buf[i] == '\n')
			return(1);
		i++;
	}
	return(0);
}

char	*ft_joint(char *left, char *buf)
{
	char	*ret;
	int		i;
	int		a;


	if(!buf)
		return(NULL);
	a = ft_len(left) + ft_len(buf);
	ret = malloc(sizeof(char) * (a + 1));
	i = 0;
	a = 0;
	if(left)
	{
		while (left[a])
			ret[i++] = left[a++];
		a = 0;
	}
	while (buf[a])
		ret[i++] = buf[a++];
	ret[i] = '\0';
	free(left);
	return(ret);
}

char	*ft_line(char *left)
{
	int		i;
	char	*line;

	if(!left)
		return(NULL);
	i = ft_new_line_len(left);
	if(i <= 0)
		return(NULL);
	line = malloc(sizeof(char) * i + 1);
	i = 0;
	while(left[i] && left[i - 1] != '\n')
	{
		line[i] = left[i];
		i++;
	}
	line[i] = '\0';
	return(line);
}

char	*ft_update_left(char *left)
{
	char	*update;
	int		i;
	int		a;

	if(!left)
		return(NULL);
	i = (ft_len(left) - ft_new_line_len(left));
	if(i <= 0)
	{
		free(left);
		return(NULL);
	}
	update = malloc(sizeof(char) * i + 1);
	i = ft_new_line_len(left);
	a = 0;
	while (left[i])
		update[a++] = left[i++];
	update[a] = '\0';
	free(left);
	return(update);
}

int	ft_new_line_len(char *str)
{
	int	i;

	i = 0;
	if(!str)
		return(0);
	while (str[i] && str[i - 1] != '\n')
		i++;
	return(i);
}