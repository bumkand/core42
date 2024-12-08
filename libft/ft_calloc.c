/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:42:33 by jakand            #+#    #+#             */
/*   Updated: 2024/10/06 12:41:03 by jaandras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(nmemb * size));
	if ((nmemb * size) < nmemb || (nmemb * size) < size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < nmemb * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

// int	main(void)
// {
// 	int	i;
// 	// Test 1: Alokovanie poľa 5 integerov (sizeof(int) je 4 bajty)
// 	int *array = (int *)ft_calloc(5, sizeof(int));

// 	if (array == NULL)
// 	{
// 		printf("Test 1: Alokácia zlyhala.\n");
// 		return (1);
// 	}
// 	i = 0;
// 	// Skontrolujeme, či sú všetky prvky inicializované na 0
// 	while (i < 5)
// 	{
// 		printf("Test 1 - array[%d] = %d\n", i, array[i]);
// 		i++;
// 	}

// 	// Uvoľníme pamäť
// 	free(array);

// 	// Test 2: Alokovanie poľa 10 znakov (char)
// 	char *char_array = (char *)ft_calloc(10, sizeof(char));

// 	if (char_array == NULL)
// 	{
// 		printf("Test 2: Alokácia zlyhala.\n");
// 		return (1);
// 	}
// 	i = 0;
// 	// Skontrolujeme, či sú všetky prvky inicializované na '\0'
// 	while (i < 10)
// 	{
// 		printf("Test 2 - char_array[%d] = %d\n", i, char_array[i]);
// 		i++;
// 	}

// 	// Uvoľníme pamäť
// 	free(char_array);

// 	// Test 3: Alokácia 0 prvkov
// 	int *empty_array = (int *)ft_calloc(0, sizeof(int));
// 	if (empty_array == NULL)
// 	{
// 		printf("Test 3: Alokácia zlyhala alebo vrátila NULL.\n");
// 	}
// 	else
// 	{
// 		printf("Test 3: Alokácia 0 prvkov prebehla úspešne.\n");
// 		free(empty_array);
// 	}

// 	return (0);
// }
