/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:59:13 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/18 15:52:39 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	int			count;

	i = 0;
	count = 0;
	if (haystack == NULL && len == 0)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while ((haystack[i + j] == needle[j])
			&& haystack[i + j] && needle[j] && (i + j < len))
		{
			count = haystack[i + j] - needle[j];
			j++;
		}
		if (count == 0 && (j == ft_strlen(needle)))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

// int main () 
// {
//   char haystack[30] =  "aaabcabcd";
//   char needle [10]= "cd";
//   char *ret;

//    //ret = strnstr(haystack, needle, 10);
//    ret = ft_strnstr(haystack, needle, 8);

//    printf("The substring is: %s\n", ret);
//    return(0);
// }
// char	*ft_strnstr(char *haystack, char *needle, size_t len)
// {
// 	size_t	i;
// 	int		x; 

// 	x = ft_strlen(needle);
// 	i = 0;

// 	if( needle == 0)
// 		return haystack;
// 	while (i < len && haystack[i] != '\0')
// 	{
// 		if (haystack[i] == needle[0] && (0 == ft_strncmp(haystack, needle, x)))
// 		{
// 			return (&haystack[i]);
// 		}
// 		i++;
// 	}
// 	return NULL;

// }

// int main () {
//   char haystack[20] = "TutorialsPoint";
//   char needle []= "ria";
//    char *ret;

//    //ret = strnstr(haystack, needle, 10);
//    ret = ft_strnstr(haystack, needle, 10);

//    printf("The substring is: %s\n", ret);
//    return(0);
// }

// #include <stdio.h>
// #include <string.h>

// int main() {
//     const char* haystack = "The quick brown fox jumps over the lazy dog";
//     const char* needle = "fox";
//     size_t len = 10;

//     char* result = strnstr(haystack, needle, len);

//     if (result != NULL) {
//         printf("Found the substring: %s\n", result);
//     } else {
//         printf("Substring not found.\n");
//     }

//     return 0;
// }