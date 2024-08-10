/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:03:39 by rsimon            #+#    #+#             */
/*   Updated: 2023/09/09 21:28:50 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

// #include "stdio.h"
// int	main()
// {
// 	int c=0;
// 	print_char('t');
// 	c= print_char('r');
// 	write(1, "\n", 1);
// 	printf("count is %i", c);
// }