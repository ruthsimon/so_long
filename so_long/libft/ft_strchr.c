/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:25:29 by rsimon            #+#    #+#             */
/*   Updated: 2024/02/29 18:41:01 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strchr(const char *s, int c)
// {
// 	int		i;
// 	char	t;

// 	t = (char)c;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == t)
// 		{
// 			return ((char *)&s[i]);
// 		}
// 		i++;
// 	}
// 	if (t == '\0')
// 		return ((char *)&s[i]);
// 	return (NULL);
// }
char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	t;

	t = (char)c;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == t)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (t == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
// #include <string.h>
// int main ()
// {
//     char x[] = "tripoulieee";
//     //printf("%s", ft_strchr(x, 't'+256));
// 	printf("%s", strchr(x, 't' + 256));

//     return (0);
// }
