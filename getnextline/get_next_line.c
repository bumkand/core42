/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:43:28 by jakand            #+#    #+#             */
/*   Updated: 2024/12/08 21:21:06 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i), sizeof(char));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
	{
		line[j++] = buffer[i++];
	}
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*take_line(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer || !buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_line(int fd, char *buffer)
{
	char	*line;
	int		char_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	line = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!line)
		return (NULL);
	char_read = 1;
	while (char_read > 0)
	{
		char_read = read(fd, line, BUFFER_SIZE);
		if (char_read == -1)
		{
			free(line);
			return (NULL);
		}
		line[char_read] = '\0';
		buffer = ft_free(buffer, line);
		if (ft_strchr(line, '\n'))
			break ;
	}
	free(line);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*read_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = get_line(fd, buffer);
	if (!buffer)
		return (NULL);
	read_line = take_line(buffer);
	buffer = next_line(buffer);
	// naposledy pridane vdaka comu sa uvolnil jeden byte
	if (buffer)
    {
        free(buffer);
        buffer = NULL;
    }
	return (read_line);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = -1;
	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) && ++i < 5)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
