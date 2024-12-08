/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:03:37 by jaandras          #+#    #+#             */
/*   Updated: 2024/10/14 21:25:21 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Write whole string

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

// lenth of string => integer

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

// Function ITOA

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

// Main function PRINTF

int	ft_printf(const char *format, ...)
{
	int		i;
	char	*s;
	int		d;
	va_list	args;

	i = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && format[1] == 's')
		{
			s = va_arg(args, char *);
			ft_putstr_fd(s, 1);
			i += ft_strlen(s);
			i--;
			format++;
		}
		else if (*format == '%' && format[+1] == 'd')
		{
			d = va_arg(args, int);
			s = ft_itoa(d);
			ft_putstr_fd(s, 1);
			i += ft_strlen(s);
			free(s);
			format++;
		}
		else
			write(1, format, 1);
		format++;
		i++;
	}
	va_end(args);
	return (i);
}

int	main (void)
{
	int	result;

	result = printf("Sentence to know how many %s were written\n", "characters");
	printf("%d\n%d\n", result, 28);
	result = ft_printf("Sentence to know how many %s were written\n", "characters");
	ft_printf("%d\n%d\n", result, 28);
	return (0);
}
