/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 23:18:51 by jakand            #+#    #+#             */
/*   Updated: 2024/10/02 19:33:01 by jaandras         ###   ########.fr       */
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
// 	if (ptr == NULL)
// 		return (NULL);
// 	while (j < i)
// 	{
// 		ptr[j] = s[j];
// 		j++;
// 	}
// 	ptr[j] = '\0';
// 	return (ptr);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*ptr;
	size_t	s_len;

	j = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= (unsigned int)s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (j < len)
	{
		ptr[j] = s[start + j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

// int	main(void)
// {
// 	char const	*s = "Hi, I am Mandalorian, friend of Yoda.";
// 	unsigned int	start = 0;
// 	size_t		len = 0;
// 	char		*result;

// 	result = ft_substr(s, start, len);
// 	if (!result)
// 		printf("Substring wasn't find");
// 	else
// 		printf("Lenth is %ld\n", len);
// 		printf("Start is %i\n", start);
// 		printf("Character: %s\n", result);
// 	return (0);
// }
