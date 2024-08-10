/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:42:40 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/18 21:30:45 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	f;
	int		l;

	f = (char) c;
	l = ft_strlen(s);
	while (l >= 0)
	{
		if (f == s[l])
		{
			s = s + l;
			return ((char *)s);
		}
		l--;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main () {
//    char str[] = "This-is-just-a-test-string"; 
//    //const char ch = '-'; 
//    char  *p2;

//    //p = strrchr(str, ch); 
//    //printf("String starting from last occurrence of %c is: %s\n", ch, p);

//    //p2 = strrchr(str, 'i'); 
//    //p2 = ft_strrchr(str, 'i');
//    p2 = strrchr(str, 'i');
//    printf("String starting from last occurrence of 'i' is: %s\n", p2);

//    return 0;
// }