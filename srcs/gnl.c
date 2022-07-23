#include "cub3d.h"

static char	*get_output_line(char *save)
{
	size_t	i;
	char	*str;

	if (save[0] == '\0')
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(save) + 2));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*get_save(char *save)
{
	size_t		i;
	size_t		j;
	char		*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	i++;
	str = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (save[i])
		str[j++] = save[i++];
	str[j] = '\0';
	free(save);
	return (str);
}

static char	*read_line(int fd, char *save)
{
	char	*buf;
	ssize_t	n;

	buf = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	n = NOT_EOF;
	while (ft_strchr(save, '\n') == NULL && n != END_OF_FILE)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == READ_ERROR)
		{
			free(buf);
			return (NULL);
		}
		buf[n] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || OPEN_MAX < fd)
		return (NULL);
	save[fd] = read_line(fd, save[fd]);
	line = get_output_line(save[fd]);
	save[fd] = get_save(save[fd]);
	return (line);
}
