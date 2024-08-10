/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:56:07 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/12 21:23:55 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	int		i;
// 	char	t;

// 	t = (char)c;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == t)
// 		{
// 			return ((char *)&s[i]);
// 		}
// 		i++;
// 	}
// 	if (t == '\0')
// 		return ((char *)&s[i]);
// 	return (NULL);
// }

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	t;

	t = (char)c;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == t)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (t == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

int	printer(const char *str, int *i, va_list args)
{
	int		len;

	len = 0;
	if (str[(*i) + 1] == 'c')
		len += print_char(va_arg(args, int));
	else if (str[(*i) + 1] == 's')
		len += print_string(va_arg(args, char *));
	else if (str[(*i) + 1] == 'p')
		len += print_pointer(va_arg(args, unsigned long long int));
	else if (str[(*i) + 1] == 'd' || str[(*i) + 1] == 'i')
		len += print_dec(va_arg(args, int));
	else if (str[(*i) + 1] == 'u')
		len += print_unsigned(va_arg(args, unsigned int));
	else if (str[(*i) + 1] == 'x')
		len += print_hexlow(va_arg(args, unsigned int));
	else if (str[(*i) + 1] == 'X')
		len += print_hexupp(va_arg(args, unsigned int));
	else if (str[(*i) + 1] == '%')
		len += print_char('%');
	(*i)++;
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	char	*set;
	va_list	args;
	int		len;

	va_start (args, str);
	set = "cspdiuxX%%";
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && ft_strchr(set, str[i + 1]))
			len += printer(str, &i, args);
		else
			len += print_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

// #include<stdio.h>
// int main()
// {
// 	ft_printf("\nThis is ruth --> %d\n",20);
// 	ft_printf("Hello %% but %x is 42 %s", 5, "ruth");
// 	printf("\nThis is pc --> %d\n", 10);
// 	printf("Hello %% but %x is 42 %s\n", 5, "ruth");
// 	ft_printf("Hello %% but %x is 42 %s", 5, "ruth");
// 	return (0);
// }

// #include<stdio.h>
// int main()
// {
// 	//char *str = NULL;

// 	ft_printf("%p", NULL);
// }