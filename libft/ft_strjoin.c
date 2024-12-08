/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:00:22 by jakand            #+#    #+#             */
/*   Updated: 2024/10/02 19:50:56 by jaandras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// char	*ft_strdup(const char *s)
// {
// 	int		i;
// 	int		j;
// 	char	*ptr;

// 	i = ft_strlen(s);
// 	j = 0;
// 	ptr = (char *) malloc((i + 1) * sizeof (char));
// 	if (!ptr)
// 		return (NULL);
// 	while (j < i)
// 	{
// 		ptr[j] = s[j];
// 		j++;
// 	}
// 	ptr[j] = '\0';
// 	return (ptr);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	if (ft_strlen(s1) + ft_strlen(s2) == 0)
		return (ft_strdup(""));
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (ft_strlen(s1) > i)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (ft_strlen(s2) > j)
	{
		ptr[i] = s2[j];
		j++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
