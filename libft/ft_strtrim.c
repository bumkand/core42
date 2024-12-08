/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:15:40 by jaandras          #+#    #+#             */
/*   Updated: 2024/10/03 17:14:06 by jaandras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	find_char(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	j;
	size_t	k;
	char	*ptr;

	if (!set || !s1)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(""));
	while (find_char(set, *s1))
		s1++;
	if (*s1 == '\0')
		return (ft_strdup(""));
	j = ft_strlen(s1) - 1;
	while (j > 0 && find_char(set, s1[j]))
		j--;
	ptr = (char *)malloc((j + 2) * sizeof(char));
	if (!ptr)
		return (NULL);
	k = -1;
	while (++k <= j)
		ptr[k] = s1[k];
	ptr[k] = '\0';
	return (ptr);
}
