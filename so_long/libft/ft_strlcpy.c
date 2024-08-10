/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:12:55 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/16 23:06:01 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	z;

	i = 0;
	z = 0;
	while (src[z] != '\0')
		z++;
	if (size == 0)
		return (z);
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (z);
}

// int main()
// {
// 	char dest[10] = "Hello";
// 	char *src = "Hey girl, what's up?";

// 	// printf( "ruth %zu\n", ft_strlcpy(dest, src, 0));
// 	printf( "cpu %zu\n", strlcpy(dest, src, 0));
// 	printf("%s", dest);
// }
// int main(void) 
// {
//     char src[] = "Hello, world!";
//     char dest[12]= "ruth simon";
//     int f= ft_strlcpy(dest, src,12);
//     printf("%i\n",f);
//     return 0;
// }