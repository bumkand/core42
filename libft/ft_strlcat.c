/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:32:45 by jaandras          #+#    #+#             */
/*   Updated: 2024/10/06 13:42:45 by jaandras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	if (!dst && size == 0)
		return (ft_strlen(src));
	d_len = 0;
	s_len = 0;
	i = 0;
	while (dst[d_len] && d_len < size)
		d_len++;
	while (src[s_len])
		s_len++;
	if (size <= d_len)
		return (d_len + s_len);
	while (src[i] && d_len + i < size - 1)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	if (d_len + i < size)
		dst[d_len + i] = '\0';
	return (d_len + s_len);
}

// int	main(void)
// {
// 	size_t j;
// 	char dst[500] = "asdfghjkl";
// 	char s[500] = "0123456789";

// 	j = ft_strlcat(dst, s, 5);
// 	printf("%zu\n", j);
// 	return (0);
// }