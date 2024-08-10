/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:48:25 by rsimon            #+#    #+#             */
/*   Updated: 2023/09/09 21:57:26 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_decimal(int dec)
{
	char	y;
	char	*set;

	set = "0123456789";
	if (dec < 0)
	{
		write(1, "-", 1);
		dec = dec * -1;
	}
	if (dec == 0)
		return ;
	y = set[dec % 10];
	write_decimal(dec / 10);
	write(1, &y, 1);
}

int	print_dec(int deci)
{
	int	count;

	count = 0;
	if (deci == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (deci == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (deci < 0)
		count++;
	write_decimal(deci);
	while (deci != 0)
	{
		deci = deci / 10;
		count++;
	}
	return (count);
}

// #include <stdio.h>
// int main()
// {
//   print_dec(-234);
//   //printf("\n %i",print_dec(1456784578));
// }
// #include <stdio.h>
// int main()
// {
// 	printf("\n%d\n", print_dec(-2147483648));
// 	return (0);
// }