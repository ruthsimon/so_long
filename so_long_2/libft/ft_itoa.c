/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:47:59 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/19 20:43:04 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_counter(int n)
{
	int	i;

	i = 0 ;
	if (n < 0)
	{
		n *= -1;
		i = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*result(int num, int t, char *str)
{
	int	s;

	s = 0;
	if (num < 0)
	{
		s = 1;
		num = num * -1;
	}
	if (s == 1)
		str[0] = '-';
	str[t] = '\0';
	t--;
	while (t > 0 || num > 0)
	{
		str[t] = '0' + (num % 10);
		num = num / 10;
		t--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*str;

	digits = digit_counter(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
	{
		str = malloc (sizeof(char) * (digits + 1));
		if (str == NULL)
			return (NULL);
	}
	return (result(n, digits, str));
}

// int main()
// {
//     int x = +2014;
//     char *result = ft_itoa(x);
//     printf("Result: %s\n", result);
//     free(result);  // Don't forget to free the allocated memory
//     return 0;
// }