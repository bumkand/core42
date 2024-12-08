/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:51:00 by jaandras          #+#    #+#             */
/*   Updated: 2024/09/23 17:18:54 by jaandras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dst;
	char	*s;

	s = (char *)src;
	dst = (char *)dest;
	if (s > dst)
	{
		i = 0;
		while (i < n)
		{
			dst[i] = s[i];
			i++;
		}
	}
	if (dst > s)
	{
		i = n;
		while (i-- > 0)
		{
			dst[i] = s[i];
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char	dst[500] = "asdfghjkl";
// 	char	s[500] = "0123456789";

// 	ft_memmove(dst, s, 3);
// 	printf("%s\n", dst);
// 	return (0);
// }
