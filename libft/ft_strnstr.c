/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:49:31 by jakand            #+#    #+#             */
/*   Updated: 2024/10/06 13:09:16 by jaandras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	if (!big && len == 0)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	n = 0;
	while (big[n] && n < len)
	{
		i = 0;
		j = n;
		while (big[j] == little[i] && j < len)
		{
			i++;
			j++;
			if (little[i] == '\0')
				return ((char *)&big[n]);
		}
		n++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*largestring = "lorem ipsum dolor sit amet";
// 	const char	*smallstring = "ips";
// 	char	*ptr;

// 	ptr = ft_strnstr(largestring, smallstring, 9);
// 	if (ptr != NULL)
// 		printf("%s\n", ptr); // Použitie %s na výpis reťazca
// 	else
// 		printf("Substring not found\n");
// 	return (0);
// }
