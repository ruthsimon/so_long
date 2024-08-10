/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexlow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:58:26 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/22 22:12:34 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_hexlow(unsigned int num)
{
	char	y;
	char	*set;

	set = "0123456789abcdef";
	if (num == 0)
		return ;
	y = set[num % 16];
	put_hexlow(num / 16);
	write(1, &y, 1);
	return ;
}

int	print_hexlow(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	put_hexlow(num);
	while (num > 0)
	{
		num = num / 16;
		count++;
	}
	return (count);
}

// #include<stdio.h>
// int main()
// {
// 	printf("it is %i", print_hexlow(2345678));
// 	printf("\n%x",2345678);
// }
