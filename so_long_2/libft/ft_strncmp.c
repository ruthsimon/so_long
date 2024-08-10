/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:58:08 by rsimon            #+#    #+#             */
/*   Updated: 2024/02/19 13:09:08 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		size;

	size = 0;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && ((unsigned char)s1[i] != '\0'))
	{
		size = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (size != 0)
			return (size);
		i++;
	}
	if (i < n)
		size = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (size);
}

// #include <stdio.h>
// int main()
// {
// 	char str1[] = "Hello";
// 	char str2[] = "HellO";
// 	printf("%d", ft_strncmp(str1, str2, 5));
// }
// int main () {
//     // char str1[20]="hello";
//     // char str2[20]= "helLO WORLD";
//     // int result;
//     result = strncmp(str1, str2, 5);
//     result = ft_strncmp(str1, str2, 3);

//     printf(" The result is %i", result);
// }