/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:52:01 by jakand            #+#    #+#             */
/*   Updated: 2024/09/28 22:12:37 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c_char;
	size_t			i;

	str = (void *) s;
	c_char = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == c_char)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	size_t	n = 8;
// 	const char	*str = "asdf";
// 	int	c_har = '\0';
// 	char	*result;

// 	result = ft_memchr(str, c_har, n);
// 	if (result != 0)
// 		printf("%c\n", *result);
// 	else
// 		printf("Character not found within first %zu bytes.\n", n);
// 	return (0);
// }
