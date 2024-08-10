/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:15:07 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/15 19:21:07 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *alpha)
{
	size_t	count;

	count = 0;
	while (alpha[count] != '\0')
	{
		count++;
	}
	return (count);
}

// int main(void)
// {
//     printf("it is %i",ft_strlen("asdfd"));
// }