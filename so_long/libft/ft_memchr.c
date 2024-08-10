/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:58:59 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/18 15:51:03 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*x;
	size_t			i;
	unsigned char	r;

	x = (unsigned char *)s;
	r = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (x[i] == r)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

// int main () {
//    char str[] = "https://www.tutorialspoint.com";
//    const char ch = '.';
//    char *ret;

//    //ret = memchr(str, ch, strlen(str));
//    ret = ft_memchr(str, ch, strlen(str));

//    printf("String after |%c| is  |%s|\n", ch, ret);

//    return(0);
// }