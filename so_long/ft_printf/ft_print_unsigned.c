/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:04:50 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/31 20:02:50 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_unsigned(unsigned int nbr)
{
	char	y;
	char	*set;

	set = "0123456789";
	if (nbr == 0)
		return (0);
	y = set[nbr % 10];
	put_unsigned(nbr / 10);
	write(1, &y, 1);
	return (1);
}

int	print_unsigned(unsigned int num)
{
	int	count;
	int	original;

	count = 0;
	original = num;
	put_unsigned(original);
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

// #include <stdio.h>
// int main ()
// {
//     printf("it is %i", print_unsigned(-2345678));
// 	printf("it is %u",-2345678 );
// }