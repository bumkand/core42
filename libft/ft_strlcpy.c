/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:14:32 by jakand            #+#    #+#             */
/*   Updated: 2024/09/26 16:42:56 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
// int	main(void)
// {
// 	int	j;
// 	char	dst[] = "";
// 	char	src[] = "1234567890";

// 	j = ft_strlcpy(dst, src, 3);
// 	printf("%i\n", j);
// 	return (0);
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	char	*d_len;
// 	char	*s_len;
// 	int	i;

// 	d_len = (char *) dst;
// 	s_len = (char *) src;
// 	i = 0;
// 	while (*(src + i) && size--)
// 	{
// 		d_len[i] = s_len[i];
// 		i++;
// 	}
// 	d_len[i] = '\0';
// 	printf("%s\n", d_len);
// 	while (*(src + i))
// 		++i;
// 	return(i);
// }

// int	main(void)
// {
// 	int j;
// 	char dst[] = "asdfghjklpoiuadhg;kajhdso;igjaoehgiuaehg";
// 	char src[] = "12345678901234567890";

// 	j = ft_strlcpy(dst, src, 30);
// 	printf("%i\n", j);
// 	return (0);
// }
