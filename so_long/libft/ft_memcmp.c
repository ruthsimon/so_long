/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:59:10 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/19 19:09:53 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp( void *s1, void *s2, size_t n)
{
	size_t			i;
	int				size;
	unsigned char	*s01;
	unsigned char	*s02;

	s01 = (unsigned char *)s1;
	s02 = (unsigned char *)s2;
	i = 0;
	size = 0;
	while (i < n)
	{
		size += s01[i] - s02[i];
		if (size != 0)
			return (size);
		i++;
	}
	return (0);
}

// int main () {
//    char str1[15]= "abcdef";
//    char str2[15]= "ABCDEF";
//    int ret;
//    //ret = memcmp(str1, str2, 5);
//    ret = ft_memcmp(str1, str2, 5);
//    printf("the value is %i", ret);
// }

// int main ()
// {
// 	char *s1 = "\xff\xaa\xde\xffMACOSX\xff";
// 	char *s2 = "\xff\xaa\xde\x02";
// 	size_t size = 8;
// 	int i1 = memcmp(s1, s2, size);
// 	int i2 = ft_memcmp(s1, s2, size);
// 	// if (i1 == i2)
// 	// 	exit(TEST_SUCCESS);
// 	// exit(TEST_FAILED);
// 	printf ("i is %i", i1);
// 	printf ("i is %i", i2);
// }