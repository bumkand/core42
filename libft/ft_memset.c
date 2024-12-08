/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:25:55 by jaandras          #+#    #+#             */
/*   Updated: 2024/09/19 20:14:28 by jaandras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char s[5000] = "GeeksForGeeks is for programming geeks";

// 	ft_memset(s, ':', 10);
// 	printf("%s\n", s);
// 	return (0);
// }