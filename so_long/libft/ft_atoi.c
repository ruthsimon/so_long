/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:25:02 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/19 20:37:09 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	signof(char c, int *i)
{
	int	sign;

	sign = 1;
	if (c == '-' || c == '+')
	{
		if (c == '-')
		{
			sign = -1;
		}
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	res;
	int					digit;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = signof(str[i], &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - '0';
		res = res * 10;
		if (res > 9223372036854775807 && sign == 1)
			return (-1);
		if (res > 9223372036854775807 && sign == -1)
			return (0);
		res += digit;
		i++;
	}
	return ((int)(res * sign));
}

// int main()
// {
// 	printf("%d\n", ft_atoi("-123"));
// 	printf("%d\n", atoi("    4"));
// 	return (0);
// }
// int main()
// {
// 	printf("%d\n", ft_atoi("92233720"));
// 	printf("%d\n",   ft_atoi("-92233720368547758100000000"));
// 	printf("%d\n", ft_atoi("-92"));
// 	//unsigned long long max
// 	// printf("%d\n", atoi("9223372036854775807"));
// 	//unsigned long long min
// 	// printf("%d\n", atoi("-9223372036854775811"));
// 	return (0);
// }
// int main () {
//    int val;
//    char str[20];
//    strcpy(str, "-234567-3454aaa");
//    //val = atoi(str);
//    val =ft_atoi(str);
//    printf("String value = %s, Int value = %d\n", str, val);
//    strcpy(str, "tutorialspoint.com");
//    val = atoi(str);
//    printf("String value = %s, Int value = %d\n", str, val);
//    return(0);
// }
