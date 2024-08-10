/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 23:02:55 by rsimon            #+#    #+#             */
/*   Updated: 2024/02/29 17:53:37 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		s;
	int		i;
	char	*ptr;

	s = ft_strlen(s1);
	i = 0;
	ptr = (char *)malloc(sizeof(*ptr) * (s + 1));
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// #include <stdio.h>
// int main()
// {
//     char source[] = "GeeksForGeeks";
//     // 5 bytes of source are copied to a new memory
//     // allocated dynamically and pointer to copied
//     // memory is returned.
//     char* target = ft_strdup(source);
//     printf("%s", target);
//     return 0;
// }