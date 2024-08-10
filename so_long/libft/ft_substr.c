/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:05:38 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/19 21:03:25 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*alloc_mem(unsigned int start, size_t len, const char *s)
{
	size_t	slen;
	char	*sub;

	slen = ft_strlen(s);
	if (start + len > slen)
		sub = malloc(((slen - start) + 1) * sizeof(char));
	else
		sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	return (sub);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	sub = alloc_mem(start, len, s);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

// int main()
// {
// 	char original_string[] = "Hello, World!";
// 	unsigned int start_index = 7;
// 	size_t substring_length = 100;

// 	char *substring = ft_substr(original_string, start_index, substring_length);

// 	if (substring == NULL)
// 	{
// 		printf("Memory allocation failed.\n");
// 		return 1;
// 	}

// 	printf("Original String: %s\n", original_string);
// 	printf("Substring: %s\n", substring);

// 	// Remember to free the allocated memory after use
// 	free(substring);

// 	return 0;
// }