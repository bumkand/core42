/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:01:21 by jakand            #+#    #+#             */
/*   Updated: 2024/09/28 13:30:50 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c_char;
	char	*ptr;

	ptr = NULL;
	i = 0;
	c_char = c;
	while (s[i])
	{
		if (s[i] == c_char)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == c_char)
		return ((char *) &s[i]);
	return (ptr);
}

// int	main(void)
// {
// 	const char str[] = "Hello I am Jakub";
// 	int ch = 'I';
// 	char *result;

// 	// Testování ft_strchr
// 	result = ft_strchr(str, ch);

// 	if (result != NULL)
// 		printf("Character '%c' found at position: %ld\n", ch, result - str);
// 	else
// 		printf("Character '%c' not found in the string.\n", ch);

// 	// Testování pro znak, který není v řetězci
// 	ch = 'o';
// 	result = ft_strchr(str, ch);

// 	if (result != NULL)
// 		printf("Character '%c' found at position: %ld\n", ch, result - str);
// 	else
// 		printf("Character '%c' not found in the string.\n", ch);

// 	return 0;
// }
