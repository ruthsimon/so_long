/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexupp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:58:22 by rsimon            #+#    #+#             */
/*   Updated: 2023/09/09 21:40:20 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_hexupp(unsigned int num)
{
	char	y;
	char	*set;

	set = "0123456789ABCDEF";
	if (num == 0)
	{
		return ;
	}
	y = set[num % 16];
	put_hexupp(num / 16);
	write(1, &y, 1);
}

int	print_hexupp(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (num < 0)
		num = num * -1;
	put_hexupp(num);
	while (num > 0)
	{
		num = num / 16;
		count++;
	}
	return (count);
}

// #include <stdio.h>
// int main()
// {
// 	printf("it is %i,", print_hexupp(23456789));
// }
