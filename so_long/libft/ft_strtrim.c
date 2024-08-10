/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:57:49 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/29 19:37:27 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*new;
	int		j;
	int		s;

	i = 0;
	j = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	s = ft_strlen(s1);
	while (s1[i] && in_set(s1[i], set))
		i++;
	while (s > 0 && in_set(s1[s - 1], set))
		s--;
	if (s < i)
		return (ft_strdup(""));
	new = malloc((s - i + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (i < s)
		new[j++] = s1[i++];
	new [j] = '\0';
	return (new);
}

// int main ()
// {
// 	char *s1 = "\t  \n\n\nHello \t  Please\n Trim me !\n t\t\n  ";
// 	char *ret = ft_strtrim(s1, " \n\t");
// 	printf("%s", ret);
// 	// char *new;

// 	// new = ft_strtrim(a,b);
// 	// printf( "it is %s", new);
// }