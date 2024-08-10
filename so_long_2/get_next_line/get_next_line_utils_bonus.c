/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:14:21 by rsimon            #+#    #+#             */
/*   Updated: 2024/02/21 17:22:00 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_static(char *ptr, char **stat)
{
	if (ptr == NULL)
	{
		free(*stat);
		*stat = NULL;
		return (NULL);
	}
	return (ptr);
}

size_t	ft_strlen(const char *alpha)
{
	size_t	count;

	count = 0;
	while (alpha[count] != '\0')
	{
		count++;
	}
	return (count);
}

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
	while (s1[i] != '\0' && s1[i] != "\n")
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	int		len;
	int		i;
	int		j;

	if (s1 == NULL)
		s1 = ft_strdup("");
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	joined = malloc((len + 1) * sizeof(char));
	if (!joined)
		return (free(s1), NULL);
	while (s1[i] != '\0')
	{
		joined[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j] != '\0')
		joined[i++] = s2 [j++];
	joined[i] = '\0';
	return (joined);
}
