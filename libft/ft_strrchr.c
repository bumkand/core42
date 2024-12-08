/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:25:34 by jakand            #+#    #+#             */
/*   Updated: 2024/09/28 15:42:44 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c_char;
	char	*ptr;

	i = 0;
	c_char = c;
	ptr = NULL;
	while (s[i])
		i++;
	while (i != 0)
	{
		if (s[i] == c_char)
			return ((char *) &s[i]);
		i--;
	}
	if (s[i] == c_char)
		return ((char *) &s[i]);
	return (ptr);
}

// int	main(void)
// {
// 	const char str[] = "Hello I am Jakub";
// 	int ch = ' ';
// 	char *result;

// 	// Testování ft_strrchr
// 	result = ft_strrchr(str, ch);

// 	if (result != NULL)
// 		printf("Character '%c' found at position: %ld\n", ch, result - str);
// 	else
// 		printf("Character '%c' not found in the string.\n", ch);

// 	// Testování pro znak, který není v řetězci
// 	ch = '\0';
// 	result = ft_strrchr(str, ch);

// 	if (result != NULL)
// 		printf("Character '%c' found at position: %ld\n", ch, result - str);
// 	else
// 		printf("Character '%c' not found in the string.\n", ch);

// 	return 0;
// }
