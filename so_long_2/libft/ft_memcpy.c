/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:14:47 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/19 23:02:54 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*d;
	char			*s;
	size_t			i;

	if ((!dst && !src) && n)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

// int main()
// {
// 	char *dest = NULL;
// 	char *src = NULL;
// 	ft_memcpy(dest, src, 5);
// }

// int main () {
//    const char src[50] = "https://www.tutorialspoint.com";
//    char dest[50]="ruth";
//    //strcpy(dest,"Heloooo!!");
//    printf("Before memcpy dest = %s\n", dest);
//    //memcpy(dest, src, 35);
//    ft_memcpy (dest, src, 35);
//    printf("After memcpy dest = %s\n", dest);
//    return(0);
// }