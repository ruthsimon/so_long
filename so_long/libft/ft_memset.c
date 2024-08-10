/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:58:42 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/19 23:03:14 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	x;
	char			*t;
	size_t			i;

	x = (unsigned char)c;
	t = (char *) s;
	i = 0;
	while (i < n)
	{
		t[i] = c;
		i++;
	}
	return (s);
}

// int main ()
// {
//     char  arr[]= "ruthsimontekle";
//     ft_memset(arr,'t',5);
//     printf("%s",arr);
// }
