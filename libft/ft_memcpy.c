/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:06:19 by jaandras          #+#    #+#             */
/*   Updated: 2024/09/22 17:40:09 by jaandras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*str;
	char	*dst;

	str = (char *)src;
	dst = (char *)dest;
	i = 0;
	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	while (i < n)
	{
		dst[i] = str[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	src[5000] = "Forest Gump is one of the biggest geeks";
// 	char	dest[5000] = "";

// 	ft_memcpy(dest, src, 10);
// 	printf("%s\n", dest);
// 	return (0);
// }
