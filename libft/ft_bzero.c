/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:02:58 by jaandras          #+#    #+#             */
/*   Updated: 2024/09/22 16:33:04 by jaandras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;
	char	a;

	a = '\0';
	i = 0;
	if (!s)
		s = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = a;
		i++;
	}
}

// #include <unistd.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	s[500] = "Hello, I love 422222";

// 	ft_bezero(s, 10);
// 	write(1, s, 20);
// 	printf("%s\n", s);
// 	return (0);
// }
