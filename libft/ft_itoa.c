/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:10:03 by jakand            #+#    #+#             */
/*   Updated: 2024/10/05 16:28:36 by jaandras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_cpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static int	get_num_len(int n)
{
	int	num_len;

	num_len = 0;
	if (n <= 0)
		num_len++;
	while (n)
	{
		n /= 10;
		num_len++;
	}
	return (num_len);
}

static char	*convert_number(int n, int num_len)
{
	char	*ptr;
	int		i;

	i = num_len - 1;
	ptr = (char *)malloc((num_len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[num_len] = '\0';
	if (n == 0)
		ptr[0] = '0';
	if (n < 0)
	{
		ptr[0] = '-';
		n = -n;
	}
	while (n)
	{
		ptr[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	int		num_len;
	char	*result;

	if (n == -2147483648)
	{
		result = malloc(12 * sizeof(char));
		if (!result)
			return (NULL);
		return (str_cpy(result, "-2147483648"));
	}
	num_len = get_num_len(n);
	result = convert_number(n, num_len);
	return (result);
}

// static char	*put_nbr(int n, char *c, int *i)
// {
// 	if (n <= 9)
// 	{
// 		c[*i] = n + 48;
// 		(*i)++;
// 		c[*i] = '\0';
// 	}
// 	else
// 	{
// 		put_nbr(n / 10, c, i);
// 		put_nbr(n % 10, c, i);
// 	}
// 	return (c);
// }

// static char	*str_cpy(char *dst, const char *src)
// {
// 	size_t	i;

// 	i = 0;
// 	while (src[i] != '\0')
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (dst);
// }

// char	*ft_itoa(int n)
// {
// 	char	*str;
// 	char	*ptr;
// 	int		num_len;
// 	int		i;
// 	int		count;

// 	num_len = 0;
// 	i = 0;
// 	count = n;
// 	if (n == -2147483648)
// 	{
// 		ptr = (char *)malloc((ft_strlen("-2147483648") + 1) * sizeof(char));
// 		if (!ptr)
// 			return (NULL);
// 		str_cpy(ptr, "-2147483648");
// 		return (ptr);
// 	}
// 	if (n == 0)
// 	{
// 		ptr = (char *)malloc(2 * sizeof(char));
// 		if (!ptr)
// 			return (NULL);
// 		ptr[0] = '0';
// 		ptr[1] = '\0';
// 		return (ptr);
// 	}
// 	while (count != 0)
// 	{
// 		count /= 10;
// 		num_len++;
// 	}
// 	str = (char *)malloc((num_len + 1) * sizeof(char));
// 	if (!str)
// 		return (NULL);
// 	if (n < 0)
// 	{
// 		put_nbr(-n, str, &i);
// 		ptr = (char *)malloc((ft_strlen(str) + 2) * sizeof(char));
// 		if (!ptr)
// 		{
// 			free(str);
// 			return (NULL);
// 		}
// 		ptr[0] = '-';
// 		ptr[i] = '\0';
// 		str_cpy(ptr + 1, str);
// 		free((char *)str);
// 		return (ptr);
// 	}
// 	put_nbr(n, str, &i);
// 	ptr = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
// 	if (!ptr)
// 	{
// 		free(str);
// 		return (NULL);
// 	}
// 	ptr[i] = '\0';
// 	str_cpy(ptr, str);
// 	free((char *)str);
// 	return (ptr);
// }

// #include <stdio.h>

// int	main(void)
// {
//     char    *result;

//     result = ft_itoa(2147483647);
// 	printf("%s\n", result);
// 	return (0);
// }
