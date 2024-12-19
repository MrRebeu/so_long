#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	int		len;

	len = ft_strlen(s);
	i = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
char	*read_line(int fd, char *temp)
{
	char    *buffer;
	int     bytes_read;
	char    *tmp;

	if (temp && ft_strchr(temp, '\n'))
        	return (temp);
        buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (!temp)
			temp = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(temp, buffer);
			free(temp);
			temp = tmp;
		}
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	if (bytes_read == -1)
	{
		free(temp);
		return (NULL);
	}
	return (temp);
}

char	*ft_getline(char *buffer)
{
	int	i;
	char	*line;
	
	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;

    // +2 pour le \n et le \0
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
    // Copie jusqu'au \n inclus
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')  // Ajoute le \n s'il exis
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';  // Termine la chaîne
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;
	char	*temp;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_line(fd, buffer); 
	if (!buffer)
		return (NULL);
	line = (ft_getline(buffer));
	if (ft_strchr(buffer, '\n'))
	{
		temp = ft_strdup(ft_strchr(buffer, '\n') + 1);
		free(buffer);
		buffer = temp;
	}
	else
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}
