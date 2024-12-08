/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:14:11 by jdecorte          #+#    #+#             */
/*   Updated: 2024/12/08 21:19:49 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *line)
{
	char	*temp;

	temp = ft_strjoin(buffer, line);
	if (!temp)
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (temp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		total;
	char	*buffer;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2);
	buffer = ft_calloc((total + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		buffer[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		buffer[i++] = s2[j++];
	buffer[i] = '\0';
	return (buffer);
}

size_t	ft_strlen(const char *string)
{
	int	i;

	if (!string)
		return (0);
	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *string, int character)
{
	char	*str;

	if (!string)
		return (NULL);
	str = (char *)string;
	while (*str != character && *str != '\0')
		str++;
	if (*str == character)
		return (str);
	else
		return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*buffer;
	size_t	i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if ((nmemb * size) < nmemb || (nmemb * size) < size)
		return (NULL);
	buffer = malloc(nmemb * size);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		buffer[i] = 0;
		i++;
	}
	return (buffer);
}
