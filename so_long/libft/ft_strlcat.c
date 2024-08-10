/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:13:57 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/18 21:29:33 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	z;
	size_t	i;
	size_t	r;
	int		k;

	z = ft_strlen(src);
	if (dst == NULL && size == 0)
		return (z + size);
	i = ft_strlen(dst);
	r = i;
	k = 0;
	if (size < i || (size == 0))
		return (z + size);
	while (src[k] != '\0' && i < size - 1)
		dst[i++] = src[k++];
	dst[i] = '\0';
	return (z + r);
}

// int main()
// {
// 	char dest[30]; 
// 	memset(dest, 0, 30);
// 	char *src = "123";
// 	printf("%zu\n", ft_strlcat(dest, src, 0));
// 	printf("%s\n", dest);
// }
// int main() 
// {
//     char src[] = "Hello, world!";
//     char dest[24]= "";
//     int f = ft_strlcat(dest, src, 0);
//     printf("%i\n",f);
//     printf("%s\n", dest);
//     return 0;
// }
// int main()
// {
//     char src[] = "Hello, world!";
//     char *dest = NULL;

//     int f = ft_strlcat(dest, src, 0);
//     printf("%i\n",f);
//     printf("%s\n", dest);
//     return 0;
// }