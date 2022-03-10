#include "get_next_line.h"

char	*ft_check(int	fd, char *buff, char *str, int res)
{
	while (res > 0 && ft_strchr(str, '\n'))
	{
		str = ft_strjoin(str, buff);
		res = read(fd, buff, 1);
		buff[res] = '\0';
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static int	res;
	static char	buff[BUFFER_SIZE / BUFFER_SIZE + 1];
	char		*str;

	str = NULL;
	if (res == 0)
	{
		res = read(fd, buff, 1);
		buff[res] = '\0';
	}
	if (res > 0 && buff[0] != '\0')
		str = ft_check(fd, buff, str, res);
	else
		return (NULL);
	return (str);
}

///////////////////////////////////////////////////////////////////////////////////////////

if (len < BUFFER_SIZE && len[BUFFER_SIZE != '\n'] && len[BUFFER_SIZE] != '\0')
	{
		tmp = malloc(sizeof(char) * (len + 1));
		tmp = ft_strjoinnew(buffer, line);
		free(line);
		line = tmp;
	}
	if (len > BUFFER_SIZE)
	{
		while (len == BUFFER_SIZE)
		{
			tmp = malloc(sizeof(char) * (ret + 1));
			tmp = ft_strjoinnew(buffer, line);
			free(line);
			line = tmp;
		}
		if (len < BUFFER_SIZE)
		{
			tmp = ft_strjoinnew(buffer, line);
			free(line);
			line = tmp;
		}
		return (line);
	}