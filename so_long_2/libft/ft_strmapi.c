/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 21:22:47 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/18 21:29:58 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	ptr = malloc((ft_strlen(s)+1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// char	transform_char(unsigned int index, char c) {
//     c = c + index;
//     return (c);
// }

// int main() {
//     const char *original_string = "Hello";
//     char *modified_string = ft_strmapi(original_string, &transform_char);

//     if (modified_string == NULL) {
//         printf("Memory allocation failed.\n");
//         return 1;
//     }

//     printf("Original string: %s\n", original_string);
//     printf("Modified string: %s\n", modified_string);

//     // Remember to free the allocated memory after use
//     free(modified_string);

//     return 0;
// }