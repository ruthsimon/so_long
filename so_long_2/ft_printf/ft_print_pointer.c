/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:48:18 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/22 22:11:42 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_hex(unsigned long long int nbr)
{
	char	*set;
	char	y;

	set = "0123456789abcdef";
	if (nbr == 0)
	{
		write(1, "0x", 2);
		return ;
	}
	y = set [nbr % 16];
	put_hex(nbr / 16);
	write (1, &y, 1);
}

int	print_pointer(unsigned long long int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	put_hex(nbr);
	while (nbr > 0)
	{
		nbr = nbr / 16;
		count++;
	}
	return (count + 2);
}

// #include <stdio.h>
// int main()
// {
// 	void *x= NULL;
// 	int *c;
// 	c= (int *)x;
// 	int f= 234567890;
// 	c= &f;
// 	unsigned long long int z= *c;
// 	//print_pointer(z);
// 	printf("\ncount is %i\n", print_pointer(z));
// }
// #include<stdio.h>
// int main()
// {
// 	//char a = 5;

// 	printf("it is %p",print_pointer(NULL));
// 	printf("\n%p\n", NULL);
// 	return (0);
// }
// int main()
// {
// 	print_pointer((unsigned long long int)NULL);
// 	return (0);
// }