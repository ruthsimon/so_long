/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 23:02:48 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/19 20:42:01 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if ((size != 0) && (count > 4294967295 / size))
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

// int main()
// {
// 	//int *arr = ft_calloc(3, sizeof(int));

// 	char *arr2 = ft_calloc(2, 4294967296);
// 	// int i = 0;
// 	// arr[0] = 'r';
// 	// arr[1] = 'u';
// 	// arr[2] = 't';
// 	// arr[3] = 'h';
// 	// while (i < 3)
// 	// {
// 	// 	printf("%c", arr[i++]);
// 	// }
// 	printf("%s", arr2);
// 	return (0);
// }
